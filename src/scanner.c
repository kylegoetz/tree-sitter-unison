#include "misc.h"
#include "scanner_types.h"
#include "vector_helpers.h"
#include "helpers.c"
#include "result.c"
#include "debug.c"
#include "condition.c"
#include "parser_utils.c"
#include "logic.c"
#include <stdint.h>

#include "tree_sitter/parser.h"
#include <stdlib.h> // malloc, free, calloc
#include <stdio.h> // fprintf, stderr
#include <assert.h> // assert
#include <string.h> // memcpy, strlen, strncat

/**
 * Instruct the lexer that the current position is the end of the potentially detected symbol, causing the next run to
 * be started after this character in the success case.
 *
 * This is useful if the validity of the detected symbol depends on what follows, e.g. in the case of a layout end
 * before a `where` token.
 */


// --------------------------------------------------------------------------------------------------------
// Evaluation
// --------------------------------------------------------------------------------------------------------

/**
  * The main function of the parsing machinery, executing the parser by passing in the initial state and analyzing the
  * result.
  *
  * If the parser concluded with success, the `result_symbol` attribute of the lexer is set, by which the parsed symbol
  * is communicated to tree-sitter, and `true` is returned, indicating to tree-sitter to use the result.
  *
  * If the parser concluded with failure, no `result_symbol` is set and `false` is returned.
  *
  * If the parser did _not_ conclude, i.e. all steps finished with `cont`, a failure is reported as well.
  *
  * If the `DEBUG_NEXT_TOKEN` flag is set, the next token will be printed.
  */
static bool eval(Result (*chk)(State *state), State *state) {
  Result result = chk(state);
  if (result.finished && result.sym != FAIL) {
#ifdef DEBUG
    // TODO(414owen) can names[] fail?
    if (state->marked == -1) {
      LOG(VERBOSE, "%d\n", column(state));
    } else {
      LOG(VERBOSE, "%s@%d\n", state->marked_by, state->marked);
    }
#endif
    state->lexer->result_symbol = result.sym;
    LOG(WARN, "Lexer result: %s\n", sym_names[state->lexer->result_symbol]);
    return true;
  } else return false;
}

// ----------
// API
// ----------

/**
 * This function allocates the persistent state of the parser that is passed into the other API functions.
 */
void *tree_sitter_unison_external_scanner_create() {
  indent_vec *s = (indent_vec *)calloc(1, sizeof(indent_vec));
  return s;
}

/**
 * Main logic entry point.
 * Since the state is a singular vector, it can just be cast and used directly.
 */
bool tree_sitter_unison_external_scanner_scan(void *indents_v, TSLexer *lexer, const bool *syms) {
  indent_vec *indents = (indent_vec*) indents_v;
  State state = {
    .lexer = lexer,
    .symbols = syms,
    .indents = indents
  };
  LOG(WARN, "===================\nBeginning scanner\n");
  debug_state(&state);

  if (after_error(&state)) {
      LOG(INFO, "After error. Short-circuiting to fail.\n");
      return false;
  }
  bool res = eval(scan_all, &state);
  LOG(WARN, "End scanner with %s and symbol %s\n", res ? "success" : "failure", state.lexer->result_symbol ? sym_names[state.lexer->result_symbol] : "(none)");
  return res;
}

/**
 * Copy the current state to another location for later reuse.
 * This is normally more complex, but since this parser's state constists solely of a vector of integers, it can just be
 * copied.
 */
unsigned tree_sitter_unison_external_scanner_serialize(indent_vec *s, char *buffer) {
	if (s == NULL) return 0;
	unsigned i = 0;
	buffer[i++] = (char)s->len;
	buffer[i++] = (char)s->lm_len;
	for(size_t j = 0; j < s->len && i < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++j) {
		buffer[i++] = (char)s->data[j];
	}
	for(size_t j = 0; j < s->lm_len && i < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++j) {
		buffer[i++] = (char)s->list_marker_stack[j];
	}
	return i;
}

/**
 * Load another parser state into the currently active state.
 * `payload` is the state of the previous parser execution, while `buffer` is the saved state of a different position
 * (e.g. when doing incremental parsing).
 */
void tree_sitter_unison_external_scanner_deserialize(indent_vec *s, char *buffer, unsigned length) {
	if (s == NULL) return;
	s->len = 0;
	s->lm_len = 0;
	if(length < 2) return;

	unsigned i = 0;
	size_t i_len = (unsigned char)buffer[i++];
	size_t m_len = (unsigned char)buffer[i++];
	if (i_len + m_len + 2 > length) return;

	if(i_len > 0) {
		VEC_GROW(s, i_len);
	}
	if(m_len > 0) {
		VEC_GROW_LM(s, m_len);
	}

	for(size_t j = 0; j < i_len; ++j) {
		VEC_PUSH(s, (unsigned char)buffer[i++]);
	}
	for(size_t j = 0; j < m_len; ++j) {
		VEC_PUSH_LM(s, (unsigned char)buffer[i++]);
	}
}

/**
 * Destroy the state.
 */
void tree_sitter_unison_external_scanner_destroy(void *indents_v) {
  indent_vec *indents = (indent_vec*) indents_v;
  if(indents == NULL) return;

  if(indents->data != NULL) free(indents->data);
  if(indents->list_marker_stack != NULL) free(indents->list_marker_stack);

  free(indents);
}
