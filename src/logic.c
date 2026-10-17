#include <ctype.h> // isalpha, isdigit

/**
 * These parsers constitute the higher-level logic, loosely.
 */

/** End-of-file check.
 *
 * If EOF has been reached, two scenarios are valid:
 *  - The file is empty, in which case the parser is still at the root rule, where `S_EMPTY` is valid.
 *  - The current layout can be ended. This may happen multiple times, since the parser will restart until the last
 *    layout end rule has been parsed.
 * If those cases do not apply, parsing fails.
 */
static Result eof(State *state) {
  LOG(INFO, "->eof (%u, %c)\n", COL, PEEK);
  if (is_eof(state)) {
    if (SYM(EMPTY)) {
      return finish(EMPTY, "eof");
    }
    Result res = end_or_semicolon("end_or_semicolon", state);
    SHORT_SCANNER;
    return res_fail;
  }
  return res_cont;
}

/**
 * Detect the cyclic and cid parts of a hash (OCTOTHORPE and DOT).
 * A hash is of the form ##builtin or #prefix(.cyclic)(#cid)
 * We let builtins be discovered by the JS, so fail for ##.
 * We also detect #prefix in the JS. So only detect the #cid and .cyclic
 * The cid is only valid if we've just found the prefix, so can never
 * detect the cid when should be detecting the prefix.
 */
static Result hash(State *state) {
  if (SYM(OCTOTHORPE)) {
    if (!is_eof(state) && PEEK == '#') { // Could be the cid of a hash
      S_ADVANCE;
      bool found = false;
      while (isdigit(PEEK) || isalpha(PEEK)) {
        found = true;
        S_ADVANCE;
      }
      if (found) {
        MARK("hash", state);
        return finish(OCTOTHORPE, "hash");
      } else {
        return res_fail;
      }
    }
  }
  if (SYM(DOT)) {
    if (!is_eof(state) && PEEK == '.') { // Could be cyclic of a hash
      S_ADVANCE;
      bool found = false;
      while (isdigit(PEEK) || isalpha(PEEK)) {
        found = true;
        S_ADVANCE;
      }
      if(found) {
        MARK("hash", state);
        return finish(DOT, "hash");
      } else {
        return res_fail;
      }
    }
  }
  return res_cont;
}

/**
 * Check for fold. However, because check for fold consumes -- it needs to consider line comments as well.
 */
static Result fold(State *state) {
  LOG(INFO, "->fold with PEEK =%c@%u\n", PEEK, column(state));
  if (seq("--", state)) { // either FOLD or COMMENT
    LOG(VERBOSE, "--- and PEEK is %c@%u\n", PEEK, column(state));
    switch(PEEK) {
      case '-': { // FOLD
        // TODO ADVANCE and PEEK, it's only FOLD if newline!!
        while(!is_eof(state)) S_ADVANCE;
        LOG(VERBOSE, "after advancing, PEEK is %c and should be EOF: %s\n", PEEK, is_eof(state) ? "true" : "false");
        MARK("fold", state);
        return finish(FOLD, "fold");
      }
      default: { // COMMENT
        while(!is_eof(state) && !is_newline(PEEK)) S_ADVANCE;
        LOG(VERBOSE, "after advancing, PEEK is %c and should be EOF: %s\n", PEEK, is_eof(state) ? "true" : "false");
        MARK("fold", state);
        return finish(COMMENT, "comment");
      }
    }
  }
  return res_cont;
}

/**
 * End a layout by removing an indentation from the stack, but only if the current column (which should be in the next
 * line after skipping whitespace) is smaller than the layout indent.
 */
static Result dedent(uint32_t indent, State *state) {
  LOG(INFO, "->dedent (indent = %u, col = %u, PEEK = %c)\n", indent, COL, PEEK);
  LOG(VERBOSE, "smaller_indent = %s\n", smaller_indent(indent, state) ? "yes" : "no");
  if (smaller_indent(indent, state)) return layout_end("dedent", state);
  return res_cont;
}


/**
 * Succeed for `SEMICOLON` if the indent of the next line is equal to the current layout's.
 */
static Result newline_semicolon(uint32_t indent, State *state) {
    LOG(VERBOSE, "[newline_semicolon] (indent = %u)\n", indent);
  if (SYM(SEMICOLON) && same_indent(indent, state)) {
    return finish(SEMICOLON, "newline_semicolon");
  }
  return res_cont;
}

/**
 * Parse an inline `where` or `with` token.
 *
 * Necessary because `is_newline_where` needs to know that no `where` may follow, and `with` can end a layout started by `handle`.
 */
static Result where_or_with(State *state) {
  LOG(INFO, "->where_or_with (col = %u, peek = %c)\n", COL, PEEK);
  if (PEEK == 'w') {
    S_ADVANCE;
    if (token("here", state)) {
      if (SYM(WHERE)) {
            MARK("where_or_when", state);
            return finish(WHERE, "where");
          }
    } else if (SYM(END) && token("ith", state)) {
      return layout_end("with", state);
    }
  }
  return res_cont;
}

/**
 * An `in` token ends the layout openend by a `let` and its nested layouts.
 */
static Result in(State *state) {
  if (SYM(IN) && token("in", state)) {
    MARK("in", state);
    pop(state);
    return finish(IN, "in");
  }
  return res_cont;
}

/**
 * An `else` token may end a layout opened in the body of a `then`.
 */
static Result else_(State *state) {
  return token("else", state) ? layout_end("else", state) : res_cont;
}

/**
 * A `then` token may end a layout opened in the body of an `if`.
 */
 static Result then(State *state) {
   return token("then", state) ? layout_end("then", state) : res_cont;
 }

/**
 * Consume all characters up to the end of line and succeed with `syms::commment`.
 */
static Result inline_comment(State *state) {
  LOG(INFO, "->inline_comment: consume rest of line then succeed with COMMENT\n");
  for (;;) {
    LOG(VERBOSE, "Examining if still same line: %c\n", PEEK);
    switch (PEEK) {
      NEWLINE_CASES:
      case 0:
        goto inline_comment_after_skip;
      default:
        S_ADVANCE;
        break;
    }
  }

inline_comment_after_skip:
  MARK("inline_comment", state);
  return finish(COMMENT, "inline_comment");
}

/**
 * Handle an operator that begins with `=`. If it's a single `=` then fail
 * and allow the JS to handle it instead. Without this, the JS often
 * sees a term assignment as function application with operator `=` as
 * discovered by the external scanner. This function exists to prevent
 * this.
 *
 * TODO might consider what happens if we're parsing a symop like (<=#somehash) and will it explode at the hash
 */
static Result equals(State *state) {
  LOG(INFO, "->equals (%u, %c)\n", COL, PEEK);
  if (PEEK == '=') {
    S_ADVANCE;
    if (is_eof(state) || isws(PEEK) || !symbolic(PEEK)) {
      return res_fail;
    }
  }
  return res_cont;
}



static bool found_pipe_or_logical_op(uint8_t pipe_count, uint8_t amp_count) {
  return pipe_count == 1 || pipe_count == 2 || amp_count == 2;
}

/**
 * Detect operators.
 * Cannot run before determining DOT is not an absolute qualifier.
 * Need to exclude certain symbols as solutions. The following cannot
 * be considered operators: =, &&, ||, | (`|` is handled by the JS)
 * Also need to exclude !( and ! bc these are bangs, a reserved keyword not an operator.
 *
 * Needs to recognize `(OPERATOR)` as a parenthesized operator
 */
static Result operator(State *state) {
  LOG(INFO, "operator (%u, %c)\n", COL, PEEK);

  if (is_eof(state)) return res_cont;

  // Process WATCH
  if (COL == 0 && PEEK == '>') {
    S_ADVANCE;
    if (!symbolic(PEEK) ) {
      MARK("operator", state);
      return finish_if_valid(WATCH, "watch", state);
    }
  }

  if (!symbolic(PEEK)) return res_fail;
  if (PEEK == '=') {
    Result res = equals(state);
    SHORT_SCANNER;
  }

  // Detect bangs and let JS handle them
  if ( PEEK == '!') {
    S_ADVANCE;
    if (is_eof(state) || PEEK == '(' || !symbolic(PEEK)) {
      return res_fail;
    }
  }

  uint8_t and_count = 0;
  uint8_t or_count = 0;
  bool previous_was_colon = false;
  bool is_on_first_char = true; // Used so alongside arrow_has_begun we can be sure to match -> and never --> or =-> or ~~-> etc.
  bool arrow_has_begun = false; // Used to track if we have - so if we encounter > trigger FAIL for JS lexer to take over
  /*
   * scan until we encounter a non-symbol char; at that point, if
   * - whitespace or #, succeed SYMOP
   * - non-whitespace, fail since SYMOP must be surrounded by whitespace
   *
   */
  while (!is_eof(state)) {
    LOG(VERBOSE, "[operator] Looping with PEEK = %c\n", PEEK);
    if(arrow_has_begun && PEEK == '>') { // If we were parsing -> as an operator, fail becasue it's not'
        return res_fail;
    }
    if(PEEK == '-') {
    	if(is_on_first_char) {
     		arrow_has_begun = true;
     	} else {
      	if(arrow_has_begun) {
       		while(!is_eof(state) && !is_newline(PEEK)) S_ADVANCE;
       		MARK("operator", state);
         	return finish(COMMENT, "operator");
       	}
      }
    }

    if (!symbolic(PEEK) && previous_was_colon) {
      return res_fail; // This means we just recognized a `:` by itself, which is not an operator but part of a type signature.
    }
    if (symbolic(PEEK)) { // If we find | or & as first symbol, count it. Otherwise, ensure code never thinks it has found || or &&
      previous_was_colon = false;
      switch (PEEK) {
        case '|': {
          if (or_count == 0 || or_count == 1) ++or_count;
          break;
        }
        case '&': {
          if (and_count == 0 || and_count == 1) ++and_count;
          break;
        }
        case ':': previous_was_colon = true;
        default: {
          or_count = -1;
          and_count = -1;
        }
      }
      S_ADVANCE;
      MARK("operator", state);
    } else {
      LOG(VERBOSE, "[operator] encountered a non-symbol (PEEK = %c, or_count = %u, and_count = %u)\n", PEEK, or_count, and_count);
      if (found_pipe_or_logical_op(or_count, and_count)) return res_fail;
      return (isws(PEEK) || PEEK == '#') ? finish_if_valid(SYMOP, "symbolic operator", state) : res_fail;
    }
    is_on_first_char = false;
  }
  if (found_pipe_or_logical_op(or_count, and_count)) return res_fail;
  S_ADVANCE;
  MARK("operator", state);
  return finish_if_valid(SYMOP, "symbolic operator", state);
}

/**
 * This function is called after a +/- is consumed.
 * The following cases must be handled:
 // * 2. SYMOP that begins with +/- and is terminated by whitespace or ')', the latter of which indicates a parenthetical operator
 // * 3. post-sign symbolic chars as SYMOP
 // * 4. COMMENT
 */
static Result post_pos_neg_sign(State *state, bool is_neg) {
  LOG(INFO, "->post_pos_neg_sign; PEEK = %c\n", PEEK);
  Result res = res_fail;
  // Immediately terminate as symop if sign followed by whitespace, EOF, or ')', the latter of which is expected in the case of the parenthetical op pattern in JS grammar.
  if (isws(PEEK) || is_eof(state) || PEEK == ')') {
    MARK("post_pos_neg_sign", state);
    return finish_if_valid(SYMOP, "+/-", state);
  } else if(PEEK == '-' && is_neg) {
  	while(!is_eof(state) && !is_newline(PEEK)) S_ADVANCE;
   MARK("post_pos_neg_sign", state);
   return finish(COMMENT, "post_pos_neg_sign");
  }
  switch(PEEK) {
    case '>':
      S_ADVANCE;
      if(!symbolic(PEEK)) {
        return res_fail;
      } else {
        return operator(state);
      }
      break;
    case '.':
      S_ADVANCE;
      if(isdigit(PEEK)) {
        return res_fail;
      } else {
        return operator(state);
      }
      break;
    NUMERIC_CASES:
      return res_fail;
      break;
    default:
      LOG(VERBOSE, "non-dot symbolic PEEK %c\n", PEEK);
      res = operator(state);
      LOG(VERBOSE, "Result of operator: %s\n", sym_names[res.sym]);
      SHORT_SCANNER;
  }
  return res_fail;
}

/**
 * Parse an inline comment if the next chars are two or more minuses and the char after the last minus is not
 * symbolic.
 *
 * To be called when it is certain that two (or three!) minuses cannot succeed as a symbolic operator.
 * Or when one cannot be.
 * Those cases are:
 *   - `START` is valid
 *   - Operator matching was done already
 */
static Result minus(State *state) {
  LOG(INFO, "->minus\n");
  if (PEEK != '-') return res_cont;
  S_ADVANCE;
  switch(PEEK) {
    NUMERIC_CASES:
      return res_fail;
    case '.': {
      return post_pos_neg_sign(state, true);
    }
    case '-': { // COMMENT, FOLD
      S_ADVANCE;
      if (PEEK == '-') { // FOLD
        while(!is_eof(state)) S_ADVANCE;
        MARK("minus", state);
        return finish_if_valid(FOLD, "fold", state);
      }
      return inline_comment(state);
    }
  }
  return res_cont;
}

/**
 * Succeed for a comment.
 */
static Result multiline_comment_success(State *state) {
  MARK("multiline_comment", state);
  return finish(COMMENT, "multiline_comment");
}

/**
 * Can appear anywhere. Only call once we've consumed a `{{` (in `multiline_comment`).
 */
static Result doc_block(State *state) {
    LOG(INFO, "[doc_block] (col = %u, peek = %c)\n", COL, PEEK);
    if (!SYM(DOC_BLOCK)) {
        return res_fail;
    }
    uint16_t level = 1;
    while (!is_eof(state) && level > 0) {
        switch(PEEK) {
            case '{': {
                S_ADVANCE;
                if (!is_eof(state) && PEEK == '{') {
                    ++level;
                }
                S_ADVANCE;
                break;
            }
            case '}': {
                S_ADVANCE;
                if (!is_eof(state) && PEEK == '}') {
                    --level;
                }
                S_ADVANCE;
                break;
            }
            default: S_ADVANCE;
        }
    }
    if (level == 0) {
        MARK("doc_block", state);
        return res_finish(DOC_BLOCK);
    }
    return res_fail;
}

/**
 * See `nested_comment`.
 *
 * Since {- -} comments and {{ }} doc blocks can be nested arbitrarily, this has to keep track of how many have been openend, so that the
 * outermost comment isn't closed prematurely.
 */
static Result multiline_comment(State *state) {
  LOG(INFO, "->multiline_comment (col = %u, PEEK = %c)\n", COL, PEEK);
  uint16_t level = 0;
  for (;;) {
    switch (PEEK) {
      case '{':
        S_ADVANCE;
        if (PEEK == '-') {
          S_ADVANCE;
          level++;
        }
        break;
      case '-':
        S_ADVANCE;
        if (PEEK == '}') {
          S_ADVANCE;
          if (level == 0) return multiline_comment_success(state);
          level--;
        }
        break;
      case 0: {
        Result res = eof(state);
        SHORT_SCANNER;
        return res_fail;
      }
      default:
        S_ADVANCE;
        break;
    }
  }
}

/**
 * When a brace is encountered, it can be a multi-line comment, doc block, or ability-related.
 * In the first two cases, the comment/doc block is parsed, otherwise parsing fails to delegate to the corresponding grammar rule.
 */
static Result brace(State *state) {
  LOG(INFO, "->brace (col = %u, peek = %c)\n", COL, PEEK);
  if (PEEK != '{') return res_fail;
  S_ADVANCE;
  LOG(INFO, "[brace] after first open brace (peek = %c)\n", PEEK);
  switch (PEEK) {
    case '{': {
      S_ADVANCE;
      return doc_block(state);
    }
    case '-': return multiline_comment(state);
    default: return res_fail;
  }
}


/**
 * Parse either inline or block comments. (or fold)
 */
static Result comment(State *state) {
  LOG(INFO, "->comment (col = %u, PEEK = %c)\n", state->lexer->get_column(state->lexer), PEEK);
  switch (PEEK) {
    case '-': {
      Result res = minus(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case '{': {
      Result res = brace(state);
      SHORT_SCANNER;
      return res_fail;
    }
  }
  return res_cont;
}

static Result close_layout_in_list(State *state) {
	LOG(INFO, "close_layout_in_list (peek = %c)\n", PEEK);
  switch (PEEK) {
    case ']': {
      if (state->symbols[END]) {
        pop(state);
        return finish(END, "bracket");
      }
      break;
    }
    case ',': {
      Result res = layout_end("close_layout_in_list: ,", state);
      SHORT_SCANNER;
      return res_fail;
    }
  }
  return res_cont;
}

/**
 * Parse things that begin with `-`. This is
 * 1. symops
 * 2. negative numbers
 * 3. inline comment (TODO)
 * 4. fold (TODO)
 * Note: I do not think comments are implicated here.
 * Note 2: Must fail for `->` so the JS grammar can take over and recognize the arrow.
 */
static Result handle_negative(State *state) {
  LOG(VERBOSE, "->handle_negative; PEEK = %c\n", PEEK);
  if (PEEK != '-' && PEEK != '+') return res_cont;
  S_ADVANCE;
  return post_pos_neg_sign(state, PEEK == '-');
}

/**
 * Call only after consuming all adjacent quotation marks and have determined it's a single char
 * Two chars should already be handled by calling function (inline_tokens).
 * Scan until we encounter an unescaped single quotation mark.
 * Fail if encounter newline or EOF.
 */
static Result single_line_text_literal(State *state) {
  LOG(VERBOSE, "[single_line_text_literal] peek = %c", PEEK);
  while(!is_eof(state) && !is_newline(PEEK)) {
    if(PEEK == '\\') {
      S_ADVANCE;
      S_ADVANCE;
    } else {
      if (PEEK == '"') {
        S_ADVANCE;
        MARK("single_line_text_literal", state);
        return finish(TEXT_LITERAL, "text literal");
      } else {
        S_ADVANCE;
      }
    }
  }
  return res_fail;
}

static Result multiline_text_literal(int qmark_count, State *state) {
  LOG(VERBOSE, "[multiline_text_literal] qmark_count = %u, peek = %c", qmark_count, PEEK);
  int j = 0;
  while (!is_eof(state) && j < qmark_count) {
    if (PEEK == '"') {
      ++j;
      LOG(VERBOSE, "found %u closing closing quotation marks\n", j);
    } else {
      LOG(VERBOSE, "found a non-quotation mark (%c); restarting closing count\n", PEEK);
      j = 0;
    }
    S_ADVANCE;
  }
  if(j == qmark_count) {
    MARK("text literal", state);
    return finish(TEXT_LITERAL, "text literal");
  }
  else {
    return res_fail;
  }
}

static Result text_literal(State *state) {
  if(SYM(TEXT_LITERAL)) {
    LOG(VERBOSE, "looking at text literal\n");
    S_ADVANCE;
    int i = 1;
    while(PEEK == '"') { ++i; S_ADVANCE; }
    LOG(VERBOSE, "text literal that starts with %u quotation marks\n", i);
    if (i == 1) {
      return single_line_text_literal(state);
    }
    else if (i == 2) { // empty text literal
      MARK("text_literal", state);
      return finish(TEXT_LITERAL, "text_literal");
    }
    else {
      return multiline_text_literal(i, state);
    }
  }
  return res_cont;
}

/** Parse special tokens before the first newline that can't be reliably detected by tree-sitter:
 *   TODO revisit whether we want to use `inline_tokens` at all
 *   - `where` here is just for the actual valid token
 *   - `in` closes a layout when inline
 *   - `then` closes a layout when inline
 *   - `,` if END is a possibility, closes layout
 *   - THIS IS NOT TRUE! '+' closes a layout when inline if END valid `x = 5 + 2`, the + does not close a layout!
 *   - `)` can end the layout of an `of`
 *   - symbolic operators are complicated to implement with regex
 *   - `$` can be a splice if not followed by whitespace
 *   - '[' can be a list or a quasiquote
 *   - '|' in a quasiquote, since it can be followed by symbolic operator characters, which would be consumed
 * TODO: should this handle -> instead of layout_start handling it?
 */
static Result inline_tokens(State *state) {
  LOG(INFO, "inline_tokens (%u, %c)\n", COL, PEEK);
  switch (PEEK) {
    case '"': { // consume a text literal, failing if malformed or disallowed
      Result res = text_literal(state);
      SHORT_SCANNER;
    }
    case 'w': {
      Result res = where_or_with(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case 'i': {
      Result res = in(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case 'e': {
      Result res = else_(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case 't': {
      Result res = then(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case '}': {
      Result res = layout_end("}", state);
      SHORT_SCANNER;
      return res_fail;
    }
    case ')': {
      Result res = layout_end(")", state);
      SHORT_SCANNER;
      return res_fail;
    }
    case ']': {
      Result res = layout_end("]", state);
      SHORT_SCANNER;
      return res_fail;
    }
    SYMBOLIC_CASES: {
      Result res = operator(state);
      SHORT_SCANNER;
      return res_fail;
    }
    case ',': {
      if (SYM(COMMA_END)) {
        return finish(COMMA_END, "inline_tokens: COMMA_END");
      }
      Result res = layout_end("inline_tokens: ,", state);
      SHORT_SCANNER;
      return res_fail;
    }
    case '{': {
      Result res = comment(state);
      SHORT_SCANNER;
    }
  }
  return close_layout_in_list(state);
}

/**
 * If the symbol `START` is valid, starting a new layout is almost always indicated.
 *
 * If the next character is a pipe and GUARD_LAYOUT_START is valid, tokenize the zero-width GUARD_LAYOUT_START.
 * If the next character is a left brace, it is either a comment, effect pattern, pragma or an explicit layout. In the comment case, the
 * it must be parsed here.
 * If the next character is a minus, it might be a comment.
 * If the next character is a +, it might be -> TODO what does this mean? + is not part of ->
 *
 * In all of those cases, the layout can't be started now. In the comment and pragma case, it will be started in the
 * next run.
 *
 * This pushes the indentation of the first non-whitespace character onto the stack.
 */
static Result layout_start(uint32_t column, State *state) {
    LOG(INFO, "->layout_start (column = %u, col = %u, PEEK = %c)\n", column, COL, PEEK);
    uint32_t offset = 0;

    // Need to make sure we aren't calculating a layout based on comment col
    LOG(VERBOSE, "[layout_start] before matching START (col = %u, PEEK = %c, sym(START) = %u, sym(GLS) = %u)\n", COL, PEEK, SYM(START), SYM(GUARD_LAYOUT_START));
    if (SYM(GUARD_LAYOUT_START)) {
        if (PEEK == '|') {
            LOG(VERBOSE, "[layout_start] found GUARD_LAYOUT_START; about to push col = %u\n", column);
            MARK("guard_layout_start", state);
            push(COL, state);
            return finish(GUARD_LAYOUT_START, "layout_start");
        }
    }
    if (SYM(START)) {
        LOG(VERBOSE, "[layout_start] inside START; COL = %u\n", COL);
        switch (PEEK) {
            case '-': {
                MARK("layout_start", state);
                S_ADVANCE;
                if (PEEK == '-') {
                    return inline_comment(state);
                }
                else if (PEEK == '>') {
                    return res_fail;
                } else {
                  ++offset; // So we don't count the '-' as part of the indent
                }
                LOG(VERBOSE, "[layout_start] inside - (col = %u, PEEK = %c)\n", COL, PEEK);
                goto foo;
            }
            case '{': {
                MARK("layout_start", state);
                S_ADVANCE;
                if (PEEK == '-') {
                    return multiline_comment(state);
                } else {
                  ++offset; // So we don't count the '{' as part of the indent
                }
                LOG(VERBOSE, "[layout_start] inside { (col = %u, PEEK = %c)\n", COL, PEEK);
                goto foo;
            }
        }
        foo:
        LOG(VERBOSE, "[layout_start] about to push col = %u\n", COL - offset);
        push(COL - offset, state);
        return finish(START, "layout_start");
    }
    return res_cont;
}

/**
 * After a layout has ended, the originator might need to be terminated by semicolon as well, but since the layout end
 * advances until the next line, it cannot be done in the newline checks.
 *
 * This can happen, for example, with nested `do` layouts:
 *
 * f = do
 *   a <- b
 *   do c <- d
 *      e
 *   f
 *
 * Here, when the inner `do`'s  layout is ended, the next step is started at `f`, but the outer `do`'s layout expects a
 * semicolon. Since `f` is on the same indent as the outer `do`'s layout, this parser matches.
 */
static Result post_end_semicolon(uint32_t column, State *state) {
  LOG(INFO, "->post_end_semicolon(%u, %c)\n", column, PEEK);
  if (PEEK == ',' || PEEK == ')' || PEEK == ']' || PEEK == '}') {
    return res_cont;
  }
  return SYM(SEMICOLON) && indent_lesseq(column, state)
    ? finish(SEMICOLON, "post_end_semicolon")
    : res_cont;
}

/**
 * Like `post_end_semicolon`, but for layout end.
 */
static Result repeat_end(uint32_t column, State *state) {
  LOG(INFO, "->repeat_end(%u, %c)\n", column, PEEK);
  if (state->symbols[END] && smaller_indent(column, state)) {
    LOG(VERBOSE, "[repeat_end] end available, is smaller indent, so returning END\n");
    return layout_end("repeat_end", state);
  }
  return res_cont;
}

/**
 * Rules that decide based on the indent of the next line.
 */
static Result newline_indent(uint32_t indent, State *state) {
  LOG(INFO, "->newline_indent (col = %u, indent = %u, PEEK = %c)\n", COL, indent, PEEK);
  Result res = dedent(indent, state);
  SHORT_SCANNER;
  res = close_layout_in_list(state);
  SHORT_SCANNER;
  return newline_semicolon(indent, state);
}

/**
 * Rules that decide based on the first token on the next line.
 * - starts with `-` (COMMENT, FOLD)
 * - starts with `w` (END)
 * - starts with `>` (WATCH)
 * - starts with `"` (TEXT_LITERAL)
 * NOTE: not SYMOP because cannot begin a line with one. (TODO I don't think this is true; `a\n\t++ foo` is valid)
 */
static Result newline_token(State *state) {
  LOG(INFO, "->newline_token (col = %u, peek = %c)\n", COL, PEEK);
  if (PEEK == '-') {
    return minus(state);
  }
  switch (PEEK) {
    SYMBOLIC_CASES:
    case '`': {
      if (PEEK == '+') {
        Result res = handle_negative(state);
        SHORT_SCANNER;
      } else if (PEEK == '>') {
        S_ADVANCE;
        if (!symbolic(PEEK)) {
          MARK("newline_token", state);
          return finish_if_valid(WATCH, "watch", state);
        }
      }
      return res_fail;
    }
    case 'w': {
      Result res = where_or_with(state);
      SHORT_SCANNER;
    }
    case '"': {
      Result res = text_literal(state);
      SHORT_SCANNER;
    }
  }
  if (PEEK == 'i') return in(state);
  return res_cont;
}

/**
 * To be called after parsing a newline, with the indent of the next line as argument.
 */
static Result newline(uint32_t indent, State *state) {
  LOG(INFO, "->newline(%u)\n", indent);
  Result res = eof(state);
  SHORT_SCANNER;
  if(SYM(START) || SYM(GUARD_LAYOUT_START)) {
    Result res = layout_start(indent, state);
    SHORT_SCANNER;
  }
  res = newline_indent(indent, state);
  SHORT_SCANNER;

  // fix for #94 - otherwise will scan for DOC_BLOCK before use-clause, line-ending SEMICOLON
  res = comment(state);
  SHORT_SCANNER;


  return newline_token(state);

}

/**
 * Parsers that have to run when the next non-space character is not a newline:
 *
 *   - Layout start
 *   - ending nested layouts at the same position
 *   - numeric literals + symops
 *   - Tokens `where`, `with`, `in`, `$`, `)`, `]`, `,`
 *   - comments
 */
static Result immediate(uint32_t column, State *state) {
  LOG(INFO, "->immediate (col = %u, PEEK = %c)\n", COL, PEEK);
  Result res = layout_start(column, state);
  SHORT_SCANNER;
  res = post_end_semicolon(column, state);
  SHORT_SCANNER;
  res = repeat_end(column, state);
  SHORT_SCANNER;
  return inline_tokens(state);
}

/**
 * Parsers that have to run _before_ parsing whitespace:
 *
 *   - Error check
 *   - Indent stack initialization
 *   - Qualified module dot (leading whitespace would mean it would be `(.)`)
 *   - Fold
 */
static Result init(State *state) {
  LOG(INFO, "->init (col = %u, PEEK = %c)\n", COL, PEEK);

  Result res = eof(state);
  SHORT_SCANNER;

  /**
   * It is almost always the right thing to do to start
   * a new layout if it's possible
   */
  if (SYM(START)) {
      uint32_t indent = count_indent(state);
      res = layout_start(indent, state);
      SHORT_SCANNER;
  }

  res = hash(state);
  SHORT_SCANNER;
  if (SYM(FOLD) && PEEK == '-') {
    res = fold(state);
    SHORT_SCANNER;
  } else if(SYM(COMMENT) && PEEK == '-') {
  	res = comment(state);
   	SHORT_SCANNER;
  }

  return res_cont;
}

/**
 * The main parser checks whether the first non-space character is a newline and delegates accordingly.
 */
static Result scan_main(State *state) {
  LOG(INFO, "->scan_main (%u, %c)\n", COL, PEEK);
  skipspace(state);
  Result res = eof(state);
  SHORT_SCANNER;
  MARK("main", state);
  if (is_newline(PEEK)) {
    LOG(VERBOSE, "is newline\n");
    S_SKIP;
    uint32_t indent = count_indent(state);
    return newline(indent, state);
  }
  uint32_t col = column(state);
  return immediate(col, state);
}

/**
 * The entry point to the parser.
 */
static Result scan_all(State *state) {
  LOG(INFO, "->scan_all (%u, %c)\n", COL, PEEK);
  Result res = init(state);
  SHORT_SCANNER;
  return scan_main(state);
}
