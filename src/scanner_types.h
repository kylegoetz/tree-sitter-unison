#ifndef SCANNER_TYPES_H
#define SCANNER_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include "tree_sitter/parser.h"

typedef enum {
    SEMICOLON,
    START,
    END,
    COMMA_END,
    DOT,
    WHERE,
    VARSYM,
    COMMENT,
    FOLD,
    COMMA,
    IN,
    INDENT,
    EMPTY,
    SYMOP,
    PREFIX_SYMOP,
    WATCH,
    START_AND_ARROW,
    OCTOTHORPE,
    DOC_BLOCK,
    GUARD_LAYOUT_START,
    DESTRUCTURE_START,
    TEXT_LITERAL,
    START_LIST,
    END_LIST,
    FAIL, // always last in list
} Sym;

static char *sym_names[] = {
    "semicolon",
    "start",
    "end",
    "comma end",
    "dot",
    "where",
    "varsym",
    "comment",
    "fold",
    "comma",
    "in",
    "indent",
    "empty",
    "symop",
    "(symop)",
    "watch",
    "start ->",
    "octothorpe",
    "doc block",
    "guard layout start",
    "destructure start",
    "text literal",
    "start list",
    "end list",
    "fail",
};


/**
 * State
 *
 * We track two things:
 *
 * 1. an indentation stack
 * 2. if we are in a nested list/tuple (where a single element might or might not have its own indentation stack),
 * keep track of where the element's indentation stack began in #1.
 *
 * Then, as we scan, if we enter a list or tuple where we must track this, push col to #1 and the current idx to #2
 * When we encounter a comma:
 * 	- if #2 is non-empty, succeed END
 *  - if #2 is empty, fail
 * When we find END with no comma, succeed END
 */
typedef struct {
    uint32_t *data;
    size_t len;
    size_t cap;
    size_t *list_marker_stack;
    size_t lm_len;
    size_t lm_cap;
} indent_vec;

/**
 * This structure contains the external and internal state.
 *
 * The parser provides the lexer interface and the list of valid symbols.
 *
 * The internal state consists of a stack of indentation widths that is manipulated whenever a layout is started or
 * terminated.
 */
typedef struct {
  TSLexer *lexer;
  const bool *symbols;
  indent_vec *indents;
#ifdef DEBUG
	int marked;
	char *marked_by;
#endif
} State;

typedef struct {
    Sym sym;
    bool finished;
} Result;

// Short circuit
#define SHORT_SCANNER if (res.finished) return res;
// Move the parser position one character to the right.
#define S_ADVANCE state->lexer->advance(state->lexer, false)
#define S_SKIP state->lexer->advance(state->lexer, true)
#define PEEK state->lexer->lookahead
#define COL state->lexer->get_column(state->lexer)
#define SYM(s) (state->symbols[s])

#endif
