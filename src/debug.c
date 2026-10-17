#if defined(DEBUG) && DEBUG

#define LOGL(format, ...) \
	do {\
		state->lexer->log(state->lexer, format, ##__VA_ARGS__); \
	} while(0)

static void debug_valid(State *state) {
  if (all_syms(state->symbols)) {
    LOGL("all");
    return;
  }
  bool fst = true;
  LOGL("\"");
  for (Sym i = SEMICOLON; i < FAIL; i++) {
    if (state->symbols[i]) {
      if (!fst) LOGL(",");
      LOGL("%s", sym_names[i]);
      fst = false;
    }
  }
  LOGL("\"");
}

static void debug_indents(indent_vec *indents) {
  if (indents->len == 0) LOG(VERBOSE, "empty");
  bool empty = true;
  for (size_t i = 0; i < indents->len; i++) {
    if (!empty) LOG(VERBOSE, "-");
    LOG(VERBOSE, "%d", indents->data[i]);
    empty = false;
  }
}

static void debug_state(State *state) {
  LOG(VERBOSE, "State { syms = ");
  debug_valid(state);
  LOG(VERBOSE, "col = %d", state->lexer->get_column(state->lexer));
  LOG(VERBOSE, ", indents = ");
  debug_indents(state->indents);
  LOG(VERBOSE, " }\n");
}

#else

static inline void debug_indents(indent_vec *indents) { (void)indents; }
static inline void debug_state(State *state) { (void)state; }

#endif
