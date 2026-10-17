#include "scanner_types.h"
#include <string.h>

#define NEWLINE_CASES \
  case '\n': \
  case '\r': \
  case '\f'

static bool is_newline(uint32_t c) {
  switch (c) {
    NEWLINE_CASES:
      return true;
    default:
      return false;
  }
}

/**
 * Advance the lexer until the following character is neither space nor tab.
 */
static void skipspace(State *state) {
    while (PEEK == ' ' || PEEK == '\t') {
        state->lexer->advance(state->lexer, true);
    }
}

/**
 * Advance the parser until a non-whitespace character is encountered, while counting whitespace according to the rules
 * in the syntax reference, resetting the counter on each newline.
 *
 * This advances to the first nonwhite character in the next nonempty line and determines its indentation.
 */
static uint32_t count_indent(State *state) {
    uint32_t indent = 0;
    for (;;) {
        switch (PEEK) {
            case '\n': case '\r': case '\f':
                state->lexer->advance(state->lexer, true);
                indent = 0;
                break;
            case ' ':
                state->lexer->advance(state->lexer, true);
                indent++;
                break;
            case '\t':
                state->lexer->advance(state->lexer, true);
                indent += 8;
                break;
            default:
                return indent;
        }
    }
}

/**
 * Require that the argument string follows the current position and is followed by whitespace.
 * See `seq`
 */
static bool token(const char *restrict s, State *state) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) {
        if (s[i] != PEEK) return false;
        state->lexer->advance(state->lexer, false);
    }
    // Check token end
    return (PEEK == 0 || PEEK == ' ' || PEEK == '\n' || PEEK == '(' || PEEK == ')' || PEEK == '[' || PEEK == ']');
}

/**
 * The parser appears to call `scan` with all symbols declared as valid directly after it encountered an error, so
 * this function is used to detect them.
 */
static bool all_syms(const bool *syms) {
  for (int i = 0; i <= FAIL; i++) {
    if (!syms[i]) return false;
  }
  return true;
}

static bool is_eof(State *state) { return state->lexer->eof(state->lexer); }

/**
 * The parser's position in the current line.
 */
static uint32_t column(State *state) {
  return is_eof(state) ? 0 : state->lexer->get_column(state->lexer);
}

// Only use string literals we actually need
#ifdef DEBUG
static void MARK(char *marked_by, State *state) {
  state->marked = column(state);
  state->marked_by = marked_by;
  state->lexer->mark_end(state->lexer);
}
#else
#define MARK(s, state) state->lexer->mark_end(state->lexer);
#endif
