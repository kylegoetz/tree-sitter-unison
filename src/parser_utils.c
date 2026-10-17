static Result finish(const Sym s, char *restrict desc) {
  LOG(INFO, "finish: %s\n", desc);
  return res_finish(s);
}

static Result finish_if_valid(const Sym s, char *restrict desc, State *state) {
  LOG(INFO, "->finish_if_valid %s (%u, %c)\n", desc, COL, PEEK);
  return SYM(s) ? finish(s, desc) : res_cont;
}

static void push(uint16_t ind, State *state) {
  LOG(VERBOSE, "push: %d\n", ind);
  VEC_PUSH(state->indents, ind);
}

static void pop(State *state) {
  LOG(INFO, "pop\n");
  debug_indents(state->indents);
  if (indent_exists(state)) {
    VEC_POP(state->indents);
  }
  debug_indents(state->indents);
}

static Result layout_end(char *desc, State *state) {
  LOG(INFO, "layout_end (col = %u, desc = %s, PEEK = %c)\n", COL, desc, PEEK);
    if(SYM(END)) {
        pop(state);
        return finish(END, desc);
    }
    return res_cont;
}

/**
 * Convenience parser, since those two are often used together.
 */
static Result end_or_semicolon(char *desc, State *state) {
  LOG(INFO, "->end_or_semicolon (%u, %c)\n", COL, PEEK);
  Result res = layout_end(desc, state);
  SHORT_SCANNER;
  return finish_if_valid(SEMICOLON, desc, state);
}
