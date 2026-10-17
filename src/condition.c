#define WS_CASES \
  case ' ': \
  case '\f': \
  case '\n': \
  case '\r': \
  case '\t': \
  case '\v'

#define SYMBOLIC_CASES \
    case '$': \
    case '%': \
    case '^': \
    case '&': \
    case '*': \
    case '-': \
    case '=': \
    case '+': \
    case '<': \
    case '>': \
    case '.': \
    case '~': \
    case '\\': \
    case '/': \
    case ':': \
    case '!': \
    case '|'

static bool isws(uint32_t c) {
  switch (c) {
    WS_CASES: return true;
    default: return false;
  }
}


static bool seq(const char * restrict s, State *state) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) {
    int32_t c = s[i];
    int32_t c2 = PEEK;
    if (c != c2) return false;
    S_ADVANCE;
  }
  return true;
}

static bool indent_exists(State *state) { return state->indents->len != 0; };

static bool same_indent(uint32_t indent, State *state) {
    return
        (indent == 0 && !indent_exists(state))
        || (indent_exists(state) && indent == VEC_BACK(state->indents));
}

static bool smaller_indent(uint32_t indent, State *state) {
  LOG(INFO, "->smaller_indent (indent = %u, indent exists = %c, col = %u, PEEK = %c, indent exists: %s)\n", indent, indent_exists(state) ? 'y' : 'n', COL, PEEK, indent_exists(state) ? "yes" : "no");
  if (indent_exists(state)) {
    LOG(VERBOSE, "indent exists and indent = %u, back = %u\n", indent, VEC_BACK(state->indents));
  }
  return indent_exists(state) && (indent < VEC_BACK(state->indents));
}

static bool indent_lesseq(uint32_t indent, State *state) {
	LOG(INFO, "indent_lesseq: indent = %u\n", indent);
	return indent_exists(state) && indent <= VEC_BACK(state->indents);
}

static bool after_error(State *state) { return all_syms(state->symbols); }

static bool symbolic(uint32_t c) {
  switch (c) {
    SYMBOLIC_CASES:
      return true;
    default:
      return false;
  }
}
