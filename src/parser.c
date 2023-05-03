#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 116
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 87
#define ALIAS_COUNT 0
#define TOKEN_COUNT 60
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  sym__eol = 1,
  anon_sym_DASH_DASH = 2,
  aux_sym_comment_line_token1 = 3,
  anon_sym_LBRACE_DASH = 4,
  aux_sym_comment_multiline_token1 = 5,
  anon_sym_DASH_RBRACE = 6,
  anon_sym_DASH_DASH_DASH = 7,
  aux_sym_comment_fold_token1 = 8,
  anon_sym_LBRACE_LBRACE = 9,
  anon_sym_RBRACE_RBRACE = 10,
  sym_literal_text = 11,
  sym_literal_nat = 12,
  sym_literal_int = 13,
  sym_literal_float = 14,
  sym_literal_char = 15,
  anon_sym_true = 16,
  anon_sym_false = 17,
  sym_literal_byte = 18,
  anon_sym_LBRACK = 19,
  anon_sym_COMMA = 20,
  anon_sym_RBRACK = 21,
  anon_sym_LPAREN = 22,
  anon_sym_RPAREN = 23,
  anon_sym_use = 24,
  anon_sym_forall = 25,
  anon_sym_ = 26,
  anon_sym_EQ = 27,
  anon_sym_COLON = 28,
  sym__lowercase_regular_identifier = 29,
  sym__regular_identifier = 30,
  anon_sym_DASH_GT = 31,
  anon_sym_DOT = 32,
  sym_kw_termlink = 33,
  sym_kw_typelink = 34,
  anon_sym_SQUOTE = 35,
  anon_sym_do = 36,
  anon_sym_PIPE = 37,
  anon_sym_BANG = 38,
  anon_sym_BQUOTE = 39,
  anon_sym_if = 40,
  anon_sym_then = 41,
  anon_sym_else = 42,
  anon_sym_handle = 43,
  anon_sym_unique = 44,
  anon_sym_structural = 45,
  anon_sym_where = 46,
  anon_sym_AMP_AMP = 47,
  anon_sym_PIPE_PIPE = 48,
  anon_sym_type = 49,
  anon_sym_ability = 50,
  anon_sym_alias = 51,
  anon_sym_let = 52,
  anon_sym_namespace = 53,
  anon_sym_cases = 54,
  anon_sym_match = 55,
  anon_sym_with = 56,
  sym__layout_semicolon = 57,
  sym__layout_start = 58,
  sym__layout_end = 59,
  sym_unison = 60,
  sym_comment_line = 61,
  sym_comment_multiline = 62,
  sym_comment_fold = 63,
  sym_comment_documentation_block = 64,
  sym__expression = 65,
  sym_literal_boolean = 66,
  sym_literal_list = 67,
  sym_literal_function = 68,
  sym_literal_tuple = 69,
  sym_literal_typelink = 70,
  sym_kw_forall = 71,
  sym_kw_equals = 72,
  sym_type_signature_colon = 73,
  sym_type_signature = 74,
  sym_type_name = 75,
  sym_name = 76,
  sym_term_definition = 77,
  sym_term_declaration = 78,
  sym_regular_identifier = 79,
  sym_type_variable = 80,
  sym_type_arrow = 81,
  sym_type = 82,
  aux_sym_literal_list_repeat1 = 83,
  aux_sym_literal_function_repeat1 = 84,
  aux_sym_term_definition_repeat1 = 85,
  aux_sym_type_repeat1 = 86,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__eol] = "_eol",
  [anon_sym_DASH_DASH] = "--",
  [aux_sym_comment_line_token1] = "comment_line_token1",
  [anon_sym_LBRACE_DASH] = "{-",
  [aux_sym_comment_multiline_token1] = "comment_multiline_token1",
  [anon_sym_DASH_RBRACE] = "-}",
  [anon_sym_DASH_DASH_DASH] = "---",
  [aux_sym_comment_fold_token1] = "comment_fold_token1",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [sym_literal_text] = "literal_text",
  [sym_literal_nat] = "literal_nat",
  [sym_literal_int] = "literal_int",
  [sym_literal_float] = "literal_float",
  [sym_literal_char] = "literal_char",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_literal_byte] = "literal_byte",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_use] = "use",
  [anon_sym_forall] = "forall",
  [anon_sym_] = "∀",
  [anon_sym_EQ] = "=",
  [anon_sym_COLON] = ":",
  [sym__lowercase_regular_identifier] = "_lowercase_regular_identifier",
  [sym__regular_identifier] = "_regular_identifier",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_DOT] = ".",
  [sym_kw_termlink] = "kw_termlink",
  [sym_kw_typelink] = "kw_typelink",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_do] = "do",
  [anon_sym_PIPE] = "|",
  [anon_sym_BANG] = "!",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_else] = "else",
  [anon_sym_handle] = "handle",
  [anon_sym_unique] = "unique",
  [anon_sym_structural] = "structural",
  [anon_sym_where] = "where",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_type] = "type",
  [anon_sym_ability] = "ability",
  [anon_sym_alias] = "alias",
  [anon_sym_let] = "let",
  [anon_sym_namespace] = "namespace",
  [anon_sym_cases] = "cases",
  [anon_sym_match] = "match",
  [anon_sym_with] = "with",
  [sym__layout_semicolon] = "_layout_semicolon",
  [sym__layout_start] = "_layout_start",
  [sym__layout_end] = "_layout_end",
  [sym_unison] = "unison",
  [sym_comment_line] = "comment_line",
  [sym_comment_multiline] = "comment_multiline",
  [sym_comment_fold] = "comment_fold",
  [sym_comment_documentation_block] = "comment_documentation_block",
  [sym__expression] = "_expression",
  [sym_literal_boolean] = "literal_boolean",
  [sym_literal_list] = "literal_list",
  [sym_literal_function] = "literal_function",
  [sym_literal_tuple] = "literal_tuple",
  [sym_literal_typelink] = "literal_typelink",
  [sym_kw_forall] = "kw_forall",
  [sym_kw_equals] = "kw_equals",
  [sym_type_signature_colon] = "type_signature_colon",
  [sym_type_signature] = "type_signature",
  [sym_type_name] = "type_name",
  [sym_name] = "name",
  [sym_term_definition] = "term_definition",
  [sym_term_declaration] = "term_declaration",
  [sym_regular_identifier] = "regular_identifier",
  [sym_type_variable] = "type_variable",
  [sym_type_arrow] = "type_arrow",
  [sym_type] = "type",
  [aux_sym_literal_list_repeat1] = "literal_list_repeat1",
  [aux_sym_literal_function_repeat1] = "literal_function_repeat1",
  [aux_sym_term_definition_repeat1] = "term_definition_repeat1",
  [aux_sym_type_repeat1] = "type_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__eol] = sym__eol,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [aux_sym_comment_line_token1] = aux_sym_comment_line_token1,
  [anon_sym_LBRACE_DASH] = anon_sym_LBRACE_DASH,
  [aux_sym_comment_multiline_token1] = aux_sym_comment_multiline_token1,
  [anon_sym_DASH_RBRACE] = anon_sym_DASH_RBRACE,
  [anon_sym_DASH_DASH_DASH] = anon_sym_DASH_DASH_DASH,
  [aux_sym_comment_fold_token1] = aux_sym_comment_fold_token1,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [sym_literal_text] = sym_literal_text,
  [sym_literal_nat] = sym_literal_nat,
  [sym_literal_int] = sym_literal_int,
  [sym_literal_float] = sym_literal_float,
  [sym_literal_char] = sym_literal_char,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_literal_byte] = sym_literal_byte,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_forall] = anon_sym_forall,
  [anon_sym_] = anon_sym_,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym__lowercase_regular_identifier] = sym__lowercase_regular_identifier,
  [sym__regular_identifier] = sym__regular_identifier,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_kw_termlink] = sym_kw_termlink,
  [sym_kw_typelink] = sym_kw_typelink,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_do] = anon_sym_do,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_handle] = anon_sym_handle,
  [anon_sym_unique] = anon_sym_unique,
  [anon_sym_structural] = anon_sym_structural,
  [anon_sym_where] = anon_sym_where,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_ability] = anon_sym_ability,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_namespace] = anon_sym_namespace,
  [anon_sym_cases] = anon_sym_cases,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_with] = anon_sym_with,
  [sym__layout_semicolon] = sym__layout_semicolon,
  [sym__layout_start] = sym__layout_start,
  [sym__layout_end] = sym__layout_end,
  [sym_unison] = sym_unison,
  [sym_comment_line] = sym_comment_line,
  [sym_comment_multiline] = sym_comment_multiline,
  [sym_comment_fold] = sym_comment_fold,
  [sym_comment_documentation_block] = sym_comment_documentation_block,
  [sym__expression] = sym__expression,
  [sym_literal_boolean] = sym_literal_boolean,
  [sym_literal_list] = sym_literal_list,
  [sym_literal_function] = sym_literal_function,
  [sym_literal_tuple] = sym_literal_tuple,
  [sym_literal_typelink] = sym_literal_typelink,
  [sym_kw_forall] = sym_kw_forall,
  [sym_kw_equals] = sym_kw_equals,
  [sym_type_signature_colon] = sym_type_signature_colon,
  [sym_type_signature] = sym_type_signature,
  [sym_type_name] = sym_type_name,
  [sym_name] = sym_name,
  [sym_term_definition] = sym_term_definition,
  [sym_term_declaration] = sym_term_declaration,
  [sym_regular_identifier] = sym_regular_identifier,
  [sym_type_variable] = sym_type_variable,
  [sym_type_arrow] = sym_type_arrow,
  [sym_type] = sym_type,
  [aux_sym_literal_list_repeat1] = aux_sym_literal_list_repeat1,
  [aux_sym_literal_function_repeat1] = aux_sym_literal_function_repeat1,
  [aux_sym_term_definition_repeat1] = aux_sym_term_definition_repeat1,
  [aux_sym_type_repeat1] = aux_sym_type_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__eol] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_line_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_multiline_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DASH_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_fold_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_literal_text] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_nat] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_int] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_float] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_char] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_literal_byte] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_forall] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym__lowercase_regular_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym__regular_identifier] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_kw_termlink] = {
    .visible = true,
    .named = true,
  },
  [sym_kw_typelink] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_do] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_handle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unique] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_structural] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_where] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ability] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_namespace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cases] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_with] = {
    .visible = true,
    .named = false,
  },
  [sym__layout_semicolon] = {
    .visible = false,
    .named = true,
  },
  [sym__layout_start] = {
    .visible = false,
    .named = true,
  },
  [sym__layout_end] = {
    .visible = false,
    .named = true,
  },
  [sym_unison] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_line] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_multiline] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_fold] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_documentation_block] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_literal_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_list] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_function] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_tuple] = {
    .visible = true,
    .named = true,
  },
  [sym_literal_typelink] = {
    .visible = true,
    .named = true,
  },
  [sym_kw_forall] = {
    .visible = true,
    .named = true,
  },
  [sym_kw_equals] = {
    .visible = true,
    .named = true,
  },
  [sym_type_signature_colon] = {
    .visible = true,
    .named = true,
  },
  [sym_type_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_type_name] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_term_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_term_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_regular_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_type_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_type_arrow] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_literal_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_literal_function_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_term_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 4,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 7,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 17,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 24,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 16,
  [30] = 30,
  [31] = 19,
  [32] = 20,
  [33] = 20,
  [34] = 34,
  [35] = 15,
  [36] = 19,
  [37] = 13,
  [38] = 13,
  [39] = 39,
  [40] = 39,
  [41] = 16,
  [42] = 42,
  [43] = 15,
  [44] = 39,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 47,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 52,
  [54] = 51,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 50,
  [61] = 61,
  [62] = 49,
  [63] = 63,
  [64] = 47,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 21,
  [69] = 69,
  [70] = 70,
  [71] = 27,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 72,
  [77] = 74,
  [78] = 78,
  [79] = 30,
  [80] = 30,
  [81] = 28,
  [82] = 72,
  [83] = 74,
  [84] = 28,
  [85] = 58,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 11,
  [90] = 45,
  [91] = 63,
  [92] = 65,
  [93] = 93,
  [94] = 94,
  [95] = 66,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 59,
  [108] = 108,
  [109] = 46,
  [110] = 110,
  [111] = 70,
  [112] = 69,
  [113] = 113,
  [114] = 114,
  [115] = 115,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(104);
      if (lookahead == '!') ADVANCE(188);
      if (lookahead == '"') ADVANCE(100);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(185);
      if (lookahead == '(') ADVANCE(151);
      if (lookahead == ')') ADVANCE(152);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == ',') ADVANCE(149);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '.') ADVANCE(181);
      if (lookahead == '0') ADVANCE(119);
      if (lookahead == ':') ADVANCE(158);
      if (lookahead == '=') ADVANCE(157);
      if (lookahead == '?') ADVANCE(101);
      if (lookahead == '[') ADVANCE(148);
      if (lookahead == ']') ADVANCE(150);
      if (lookahead == '`') ADVANCE(189);
      if (lookahead == 'a') ADVANCE(23);
      if (lookahead == 'c') ADVANCE(16);
      if (lookahead == 'd') ADVANCE(70);
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == 'f') ADVANCE(22);
      if (lookahead == 'h') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(43);
      if (lookahead == 'l') ADVANCE(37);
      if (lookahead == 'm') ADVANCE(18);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == 's') ADVANCE(90);
      if (lookahead == 't') ADVANCE(39);
      if (lookahead == 'u') ADVANCE(69);
      if (lookahead == 'w') ADVANCE(47);
      if (lookahead == '{') ADVANCE(7);
      if (lookahead == '|') ADVANCE(187);
      if (lookahead == '}') ADVANCE(97);
      if (lookahead == 8704) ADVANCE(156);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(102)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '-') ADVANCE(12);
      if (lookahead == '{') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(114);
      if (lookahead != 0) ADVANCE(115);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(100);
      if (lookahead == '(') ADVANCE(151);
      if (lookahead == ')') ADVANCE(152);
      if (lookahead == '.') ADVANCE(98);
      if (lookahead == '0') ADVANCE(119);
      if (lookahead == '?') ADVANCE(101);
      if (lookahead == '[') ADVANCE(148);
      if (lookahead == ']') ADVANCE(150);
      if (lookahead == 'f') ADVANCE(161);
      if (lookahead == 't') ADVANCE(174);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(118);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '&') ADVANCE(197);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(98);
      if (lookahead == '>') ADVANCE(179);
      if (lookahead == '}') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(109);
      if (lookahead == '{') ADVANCE(116);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(180);
      if (lookahead == ':') ADVANCE(158);
      if (lookahead == '=') ADVANCE(157);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 11:
      if (lookahead == ':') ADVANCE(158);
      if (lookahead == '=') ADVANCE(157);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 12:
      if (lookahead == '>') ADVANCE(179);
      END_STATE();
    case 13:
      if (lookahead == 'L') ADVANCE(50);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(65);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(59);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(87);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(26);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 23:
      if (lookahead == 'b') ADVANCE(49);
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(46);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(60);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(153);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(192);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(199);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(196);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(193);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(194);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(203);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(74);
      if (lookahead == 'h') ADVANCE(38);
      if (lookahead == 'r') ADVANCE(93);
      if (lookahead == 'y') ADVANCE(72);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 43:
      if (lookahead == 'f') ADVANCE(190);
      END_STATE();
    case 44:
      if (lookahead == 'f') ADVANCE(172);
      if (lookahead == 8704) ADVANCE(156);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 45:
      if (lookahead == 'h') ADVANCE(206);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(205);
      END_STATE();
    case 47:
      if (lookahead == 'h') ADVANCE(41);
      if (lookahead == 'i') ADVANCE(88);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(67);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 54:
      if (lookahead == 'k') ADVANCE(182);
      END_STATE();
    case 55:
      if (lookahead == 'k') ADVANCE(183);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(154);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(195);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(52);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(56);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 63:
      if (lookahead == 'm') ADVANCE(13);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(42);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(191);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(48);
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(186);
      END_STATE();
    case 71:
      if (lookahead == 'p') ADVANCE(20);
      END_STATE();
    case 72:
      if (lookahead == 'p') ADVANCE(31);
      END_STATE();
    case 73:
      if (lookahead == 'q') ADVANCE(94);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 79:
      if (lookahead == 's') ADVANCE(99);
      END_STATE();
    case 80:
      if (lookahead == 's') ADVANCE(201);
      END_STATE();
    case 81:
      if (lookahead == 's') ADVANCE(204);
      END_STATE();
    case 82:
      if (lookahead == 's') ADVANCE(71);
      END_STATE();
    case 83:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 84:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 85:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(202);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(96);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(95);
      END_STATE();
    case 92:
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 93:
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 94:
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 95:
      if (lookahead == 'u') ADVANCE(77);
      END_STATE();
    case 96:
      if (lookahead == 'y') ADVANCE(200);
      END_STATE();
    case 97:
      if (lookahead == '}') ADVANCE(117);
      END_STATE();
    case 98:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 99:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(147);
      END_STATE();
    case 100:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 101:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(142);
      END_STATE();
    case 102:
      if (eof) ADVANCE(104);
      if (lookahead == '!') ADVANCE(188);
      if (lookahead == '"') ADVANCE(100);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(185);
      if (lookahead == '(') ADVANCE(151);
      if (lookahead == ')') ADVANCE(152);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == ',') ADVANCE(149);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '.') ADVANCE(98);
      if (lookahead == '0') ADVANCE(119);
      if (lookahead == ':') ADVANCE(158);
      if (lookahead == '=') ADVANCE(157);
      if (lookahead == '?') ADVANCE(101);
      if (lookahead == '[') ADVANCE(148);
      if (lookahead == ']') ADVANCE(150);
      if (lookahead == '`') ADVANCE(189);
      if (lookahead == 'a') ADVANCE(23);
      if (lookahead == 'c') ADVANCE(16);
      if (lookahead == 'd') ADVANCE(70);
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == 'f') ADVANCE(22);
      if (lookahead == 'h') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(43);
      if (lookahead == 'l') ADVANCE(37);
      if (lookahead == 'm') ADVANCE(18);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == 's') ADVANCE(90);
      if (lookahead == 't') ADVANCE(39);
      if (lookahead == 'u') ADVANCE(69);
      if (lookahead == 'w') ADVANCE(47);
      if (lookahead == '{') ADVANCE(7);
      if (lookahead == '|') ADVANCE(187);
      if (lookahead == '}') ADVANCE(97);
      if (lookahead == 8704) ADVANCE(156);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(102)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 103:
      if (eof) ADVANCE(104);
      if (lookahead == ')') ADVANCE(152);
      if (lookahead == ',') ADVANCE(149);
      if (lookahead == '-') ADVANCE(12);
      if (lookahead == ']') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(103)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__eol);
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(1);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead == '-') ADVANCE(113);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_comment_line_token1);
      if (lookahead == '\n') ADVANCE(107);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_comment_line_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LBRACE_DASH);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_comment_multiline_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(110);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(111);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym_comment_multiline_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(111);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_DASH_RBRACE);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_DASH);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym_comment_fold_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(114);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(115);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_comment_fold_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(115);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_literal_text);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (lookahead == 'x') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(120);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(123);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(133);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_literal_nat);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_literal_int);
      if (lookahead == '.') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_literal_float);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_literal_char);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_literal_byte);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(147);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_forall);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_forall);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__lowercase_regular_identifier);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'L') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'k') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'o') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'p') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(177);
      if (lookahead == 'y') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'u') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_kw_termlink);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_kw_typelink);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_kw_typelink);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(178);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_do);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(198);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_handle);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_unique);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_structural);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_where);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_type);
      if (lookahead == 'L') ADVANCE(51);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_ability);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_namespace);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_cases);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_match);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_with);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 44},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 44},
  [18] = {.lex_state = 44},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 103},
  [22] = {.lex_state = 10},
  [23] = {.lex_state = 10},
  [24] = {.lex_state = 103},
  [25] = {.lex_state = 103},
  [26] = {.lex_state = 10},
  [27] = {.lex_state = 103},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 10},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 103},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 10},
  [48] = {.lex_state = 10},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 10},
  [56] = {.lex_state = 103},
  [57] = {.lex_state = 10},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 44},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 10},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 103},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 103},
  [72] = {.lex_state = 103},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 103},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 103},
  [77] = {.lex_state = 103},
  [78] = {.lex_state = 10},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 103},
  [83] = {.lex_state = 103},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 103},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 107},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 10},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 103},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 110},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 110},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 1},
};

enum {
  ts_external_token__layout_semicolon = 0,
  ts_external_token__layout_start = 1,
  ts_external_token__layout_end = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__layout_semicolon] = sym__layout_semicolon,
  [ts_external_token__layout_start] = sym__layout_start,
  [ts_external_token__layout_end] = sym__layout_end,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__layout_semicolon] = true,
    [ts_external_token__layout_start] = true,
    [ts_external_token__layout_end] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_LBRACE_DASH] = ACTIONS(1),
    [anon_sym_DASH_RBRACE] = ACTIONS(1),
    [anon_sym_DASH_DASH_DASH] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [sym_literal_text] = ACTIONS(1),
    [sym_literal_nat] = ACTIONS(1),
    [sym_literal_int] = ACTIONS(1),
    [sym_literal_float] = ACTIONS(1),
    [sym_literal_char] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_literal_byte] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_forall] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_kw_termlink] = ACTIONS(1),
    [sym_kw_typelink] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_do] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_handle] = ACTIONS(1),
    [anon_sym_unique] = ACTIONS(1),
    [anon_sym_structural] = ACTIONS(1),
    [anon_sym_where] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_ability] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_cases] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_with] = ACTIONS(1),
    [sym__layout_semicolon] = ACTIONS(1),
    [sym__layout_start] = ACTIONS(1),
    [sym__layout_end] = ACTIONS(1),
  },
  [1] = {
    [sym_unison] = STATE(106),
    [sym_comment_line] = STATE(105),
    [sym_comment_multiline] = STATE(105),
    [sym_comment_fold] = STATE(105),
    [sym_comment_documentation_block] = STATE(105),
    [sym_type_signature] = STATE(56),
    [sym_name] = STATE(26),
    [sym_term_definition] = STATE(103),
    [sym_term_declaration] = STATE(105),
    [sym_regular_identifier] = STATE(75),
    [sym__eol] = ACTIONS(3),
    [anon_sym_LBRACE_DASH] = ACTIONS(5),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(7),
    [sym__regular_identifier] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_RPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(13), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(11), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(53), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [44] = 11,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    ACTIONS(31), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(29), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(27), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(52), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [88] = 11,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    ACTIONS(37), 1,
      anon_sym_RBRACK,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(35), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(33), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(54), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [132] = 11,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    ACTIONS(43), 1,
      anon_sym_RBRACK,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(41), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(39), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(51), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [176] = 10,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
    ACTIONS(53), 1,
      anon_sym_LPAREN,
    ACTIONS(55), 1,
      sym__regular_identifier,
    ACTIONS(57), 1,
      sym_kw_typelink,
    STATE(25), 1,
      aux_sym_literal_function_repeat1,
    STATE(71), 1,
      sym_regular_identifier,
    ACTIONS(47), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(49), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(45), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(97), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [217] = 10,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
    ACTIONS(53), 1,
      anon_sym_LPAREN,
    ACTIONS(55), 1,
      sym__regular_identifier,
    ACTIONS(57), 1,
      sym_kw_typelink,
    STATE(25), 1,
      aux_sym_literal_function_repeat1,
    STATE(71), 1,
      sym_regular_identifier,
    ACTIONS(49), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(61), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(59), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(90), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [258] = 10,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(65), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(63), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(67), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [299] = 10,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
    ACTIONS(53), 1,
      anon_sym_LPAREN,
    ACTIONS(55), 1,
      sym__regular_identifier,
    ACTIONS(57), 1,
      sym_kw_typelink,
    STATE(25), 1,
      aux_sym_literal_function_repeat1,
    STATE(71), 1,
      sym_regular_identifier,
    ACTIONS(49), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(69), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(67), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(108), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [340] = 10,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      sym__regular_identifier,
    ACTIONS(25), 1,
      sym_kw_typelink,
    STATE(24), 1,
      aux_sym_literal_function_repeat1,
    STATE(27), 1,
      sym_regular_identifier,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(73), 2,
      sym_literal_nat,
      sym_literal_int,
    ACTIONS(71), 4,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
    STATE(45), 6,
      sym__expression,
      sym_literal_boolean,
      sym_literal_list,
      sym_literal_function,
      sym_literal_tuple,
      sym_literal_typelink,
  [381] = 2,
    ACTIONS(75), 6,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
    ACTIONS(77), 6,
      sym_literal_nat,
      sym_literal_int,
      anon_sym_true,
      anon_sym_false,
      sym__regular_identifier,
      sym_kw_typelink,
  [398] = 2,
    ACTIONS(79), 6,
      sym_literal_text,
      sym_literal_float,
      sym_literal_char,
      sym_literal_byte,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
    ACTIONS(81), 6,
      sym_literal_nat,
      sym_literal_int,
      anon_sym_true,
      anon_sym_false,
      sym__regular_identifier,
      sym_kw_typelink,
  [415] = 4,
    ACTIONS(85), 1,
      anon_sym_DASH_GT,
    STATE(13), 1,
      aux_sym_type_repeat1,
    STATE(77), 1,
      sym_type_arrow,
    ACTIONS(83), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [430] = 6,
    ACTIONS(88), 1,
      anon_sym_forall,
    ACTIONS(90), 1,
      anon_sym_,
    ACTIONS(92), 1,
      sym__regular_identifier,
    STATE(41), 1,
      sym_type_name,
    STATE(64), 1,
      sym_kw_forall,
    STATE(115), 1,
      sym_type,
  [449] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    STATE(13), 1,
      aux_sym_type_repeat1,
    STATE(77), 1,
      sym_type_arrow,
    ACTIONS(94), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [464] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    STATE(15), 1,
      aux_sym_type_repeat1,
    STATE(77), 1,
      sym_type_arrow,
    ACTIONS(98), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [479] = 6,
    ACTIONS(88), 1,
      anon_sym_forall,
    ACTIONS(90), 1,
      anon_sym_,
    ACTIONS(100), 1,
      sym__regular_identifier,
    STATE(16), 1,
      sym_type_name,
    STATE(46), 1,
      sym_type,
    STATE(47), 1,
      sym_kw_forall,
  [498] = 6,
    ACTIONS(88), 1,
      anon_sym_forall,
    ACTIONS(90), 1,
      anon_sym_,
    ACTIONS(102), 1,
      sym__regular_identifier,
    STATE(29), 1,
      sym_type_name,
    STATE(48), 1,
      sym_kw_forall,
    STATE(109), 1,
      sym_type,
  [517] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    STATE(13), 1,
      aux_sym_type_repeat1,
    STATE(77), 1,
      sym_type_arrow,
    ACTIONS(104), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [532] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    STATE(19), 1,
      aux_sym_type_repeat1,
    STATE(77), 1,
      sym_type_arrow,
    ACTIONS(106), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [547] = 1,
    ACTIONS(108), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      sym__regular_identifier,
      anon_sym_DASH_GT,
  [555] = 3,
    ACTIONS(112), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(110), 2,
      anon_sym_EQ,
      anon_sym_DOT,
    STATE(22), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [567] = 4,
    ACTIONS(115), 1,
      anon_sym_EQ,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    STATE(9), 1,
      sym_kw_equals,
    STATE(22), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [581] = 4,
    ACTIONS(119), 1,
      sym__regular_identifier,
    ACTIONS(121), 1,
      anon_sym_DASH_GT,
    STATE(10), 1,
      sym_type_arrow,
    STATE(42), 2,
      sym_regular_identifier,
      aux_sym_literal_function_repeat1,
  [595] = 4,
    ACTIONS(119), 1,
      sym__regular_identifier,
    ACTIONS(121), 1,
      anon_sym_DASH_GT,
    STATE(7), 1,
      sym_type_arrow,
    STATE(42), 2,
      sym_regular_identifier,
      aux_sym_literal_function_repeat1,
  [609] = 4,
    ACTIONS(115), 1,
      anon_sym_EQ,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    STATE(6), 1,
      sym_kw_equals,
    STATE(23), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [623] = 2,
    ACTIONS(125), 2,
      sym__regular_identifier,
      anon_sym_DASH_GT,
    ACTIONS(123), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [633] = 1,
    ACTIONS(83), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [640] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    ACTIONS(98), 1,
      ts_builtin_sym_end,
    STATE(35), 1,
      aux_sym_type_repeat1,
    STATE(83), 1,
      sym_type_arrow,
  [653] = 1,
    ACTIONS(127), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
  [660] = 4,
    ACTIONS(104), 1,
      sym__eol,
    ACTIONS(129), 1,
      anon_sym_DASH_GT,
    STATE(38), 1,
      aux_sym_type_repeat1,
    STATE(74), 1,
      sym_type_arrow,
  [673] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    STATE(36), 1,
      aux_sym_type_repeat1,
    STATE(83), 1,
      sym_type_arrow,
  [686] = 4,
    ACTIONS(106), 1,
      sym__eol,
    ACTIONS(129), 1,
      anon_sym_DASH_GT,
    STATE(31), 1,
      aux_sym_type_repeat1,
    STATE(74), 1,
      sym_type_arrow,
  [699] = 3,
    ACTIONS(131), 1,
      anon_sym_COMMA,
    STATE(34), 1,
      aux_sym_literal_list_repeat1,
    ACTIONS(134), 2,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [710] = 4,
    ACTIONS(94), 1,
      ts_builtin_sym_end,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    STATE(37), 1,
      aux_sym_type_repeat1,
    STATE(83), 1,
      sym_type_arrow,
  [723] = 4,
    ACTIONS(96), 1,
      anon_sym_DASH_GT,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
    STATE(37), 1,
      aux_sym_type_repeat1,
    STATE(83), 1,
      sym_type_arrow,
  [736] = 4,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    ACTIONS(85), 1,
      anon_sym_DASH_GT,
    STATE(37), 1,
      aux_sym_type_repeat1,
    STATE(83), 1,
      sym_type_arrow,
  [749] = 4,
    ACTIONS(83), 1,
      sym__eol,
    ACTIONS(136), 1,
      anon_sym_DASH_GT,
    STATE(38), 1,
      aux_sym_type_repeat1,
    STATE(74), 1,
      sym_type_arrow,
  [762] = 3,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(139), 1,
      anon_sym_DOT,
    STATE(22), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [773] = 3,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(141), 1,
      anon_sym_DOT,
    STATE(22), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [784] = 4,
    ACTIONS(98), 1,
      sym__eol,
    ACTIONS(129), 1,
      anon_sym_DASH_GT,
    STATE(43), 1,
      aux_sym_type_repeat1,
    STATE(74), 1,
      sym_type_arrow,
  [797] = 3,
    ACTIONS(143), 1,
      sym__regular_identifier,
    ACTIONS(146), 1,
      anon_sym_DASH_GT,
    STATE(42), 2,
      sym_regular_identifier,
      aux_sym_literal_function_repeat1,
  [808] = 4,
    ACTIONS(94), 1,
      sym__eol,
    ACTIONS(129), 1,
      anon_sym_DASH_GT,
    STATE(38), 1,
      aux_sym_type_repeat1,
    STATE(74), 1,
      sym_type_arrow,
  [821] = 3,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(148), 1,
      anon_sym_DOT,
    STATE(22), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [832] = 1,
    ACTIONS(150), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [838] = 1,
    ACTIONS(152), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [844] = 2,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    STATE(39), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [852] = 2,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    STATE(40), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [860] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(156), 1,
      anon_sym_RPAREN,
    STATE(34), 1,
      aux_sym_literal_list_repeat1,
  [870] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(158), 1,
      anon_sym_RBRACK,
    STATE(34), 1,
      aux_sym_literal_list_repeat1,
  [880] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(160), 1,
      anon_sym_RBRACK,
    STATE(60), 1,
      aux_sym_literal_list_repeat1,
  [890] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(162), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_literal_list_repeat1,
  [900] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(164), 1,
      anon_sym_RPAREN,
    STATE(62), 1,
      aux_sym_literal_list_repeat1,
  [910] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(166), 1,
      anon_sym_RBRACK,
    STATE(50), 1,
      aux_sym_literal_list_repeat1,
  [920] = 2,
    ACTIONS(108), 1,
      anon_sym_COLON,
    ACTIONS(168), 2,
      anon_sym_EQ,
      sym__lowercase_regular_identifier,
  [928] = 3,
    ACTIONS(170), 1,
      sym__regular_identifier,
    STATE(26), 1,
      sym_name,
    STATE(94), 1,
      sym_term_definition,
  [938] = 1,
    ACTIONS(172), 3,
      anon_sym_EQ,
      sym__lowercase_regular_identifier,
      anon_sym_DOT,
  [944] = 1,
    ACTIONS(174), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [950] = 1,
    ACTIONS(176), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [956] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(178), 1,
      anon_sym_RBRACK,
    STATE(34), 1,
      aux_sym_literal_list_repeat1,
  [966] = 2,
    ACTIONS(182), 1,
      anon_sym_,
    ACTIONS(180), 2,
      anon_sym_forall,
      sym__regular_identifier,
  [974] = 3,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    ACTIONS(184), 1,
      anon_sym_RPAREN,
    STATE(34), 1,
      aux_sym_literal_list_repeat1,
  [984] = 1,
    ACTIONS(186), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [990] = 2,
    ACTIONS(117), 1,
      sym__lowercase_regular_identifier,
    STATE(44), 2,
      sym_type_variable,
      aux_sym_term_definition_repeat1,
  [998] = 1,
    ACTIONS(188), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [1004] = 1,
    ACTIONS(190), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [1010] = 1,
    ACTIONS(134), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [1016] = 1,
    ACTIONS(108), 3,
      ts_builtin_sym_end,
      sym__regular_identifier,
      anon_sym_DASH_GT,
  [1022] = 1,
    ACTIONS(192), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [1028] = 1,
    ACTIONS(194), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
  [1034] = 2,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
    ACTIONS(125), 2,
      sym__regular_identifier,
      anon_sym_DASH_GT,
  [1042] = 2,
    ACTIONS(196), 1,
      sym__regular_identifier,
    STATE(33), 1,
      sym_type_name,
  [1049] = 2,
    ACTIONS(198), 1,
      anon_sym_DASH_DASH,
    ACTIONS(200), 1,
      anon_sym_DASH_DASH_DASH,
  [1056] = 2,
    ACTIONS(196), 1,
      sym__regular_identifier,
    STATE(84), 1,
      sym_type_name,
  [1063] = 2,
    ACTIONS(202), 1,
      anon_sym_COLON,
    STATE(14), 1,
      sym_type_signature_colon,
  [1070] = 2,
    ACTIONS(204), 1,
      sym__regular_identifier,
    STATE(20), 1,
      sym_type_name,
  [1077] = 2,
    ACTIONS(204), 1,
      sym__regular_identifier,
    STATE(28), 1,
      sym_type_name,
  [1084] = 1,
    ACTIONS(168), 2,
      anon_sym_EQ,
      sym__lowercase_regular_identifier,
  [1089] = 1,
    ACTIONS(127), 2,
      ts_builtin_sym_end,
      anon_sym_DASH_GT,
  [1094] = 2,
    ACTIONS(127), 1,
      sym__eol,
    ACTIONS(206), 1,
      anon_sym_DASH_GT,
  [1101] = 1,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      anon_sym_DASH_GT,
  [1106] = 2,
    ACTIONS(208), 1,
      sym__regular_identifier,
    STATE(32), 1,
      sym_type_name,
  [1113] = 2,
    ACTIONS(208), 1,
      sym__regular_identifier,
    STATE(81), 1,
      sym_type_name,
  [1120] = 2,
    ACTIONS(83), 1,
      sym__eol,
    ACTIONS(210), 1,
      anon_sym_DASH_GT,
  [1127] = 1,
    ACTIONS(174), 1,
      ts_builtin_sym_end,
  [1131] = 1,
    ACTIONS(212), 1,
      anon_sym_RBRACE_RBRACE,
  [1135] = 1,
    ACTIONS(214), 1,
      sym__eol,
  [1139] = 1,
    ACTIONS(216), 1,
      ts_builtin_sym_end,
  [1143] = 1,
    ACTIONS(75), 1,
      sym__regular_identifier,
  [1147] = 1,
    ACTIONS(150), 1,
      ts_builtin_sym_end,
  [1151] = 1,
    ACTIONS(186), 1,
      ts_builtin_sym_end,
  [1155] = 1,
    ACTIONS(188), 1,
      ts_builtin_sym_end,
  [1159] = 1,
    ACTIONS(218), 1,
      ts_builtin_sym_end,
  [1163] = 1,
    ACTIONS(220), 1,
      ts_builtin_sym_end,
  [1167] = 1,
    ACTIONS(190), 1,
      ts_builtin_sym_end,
  [1171] = 1,
    ACTIONS(222), 1,
      sym__eol,
  [1175] = 1,
    ACTIONS(224), 1,
      ts_builtin_sym_end,
  [1179] = 1,
    ACTIONS(226), 1,
      aux_sym_comment_line_token1,
  [1183] = 1,
    ACTIONS(228), 1,
      ts_builtin_sym_end,
  [1187] = 1,
    ACTIONS(230), 1,
      aux_sym_comment_fold_token1,
  [1191] = 1,
    ACTIONS(232), 1,
      anon_sym_DASH_RBRACE,
  [1195] = 1,
    ACTIONS(234), 1,
      sym__lowercase_regular_identifier,
  [1199] = 1,
    ACTIONS(236), 1,
      ts_builtin_sym_end,
  [1203] = 1,
    ACTIONS(238), 1,
      sym__regular_identifier,
  [1207] = 1,
    ACTIONS(240), 1,
      ts_builtin_sym_end,
  [1211] = 1,
    ACTIONS(242), 1,
      ts_builtin_sym_end,
  [1215] = 1,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
  [1219] = 1,
    ACTIONS(244), 1,
      ts_builtin_sym_end,
  [1223] = 1,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
  [1227] = 1,
    ACTIONS(246), 1,
      aux_sym_comment_multiline_token1,
  [1231] = 1,
    ACTIONS(194), 1,
      ts_builtin_sym_end,
  [1235] = 1,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
  [1239] = 1,
    ACTIONS(248), 1,
      aux_sym_comment_multiline_token1,
  [1243] = 1,
    ACTIONS(250), 1,
      ts_builtin_sym_end,
  [1247] = 1,
    ACTIONS(252), 1,
      sym__eol,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 88,
  [SMALL_STATE(5)] = 132,
  [SMALL_STATE(6)] = 176,
  [SMALL_STATE(7)] = 217,
  [SMALL_STATE(8)] = 258,
  [SMALL_STATE(9)] = 299,
  [SMALL_STATE(10)] = 340,
  [SMALL_STATE(11)] = 381,
  [SMALL_STATE(12)] = 398,
  [SMALL_STATE(13)] = 415,
  [SMALL_STATE(14)] = 430,
  [SMALL_STATE(15)] = 449,
  [SMALL_STATE(16)] = 464,
  [SMALL_STATE(17)] = 479,
  [SMALL_STATE(18)] = 498,
  [SMALL_STATE(19)] = 517,
  [SMALL_STATE(20)] = 532,
  [SMALL_STATE(21)] = 547,
  [SMALL_STATE(22)] = 555,
  [SMALL_STATE(23)] = 567,
  [SMALL_STATE(24)] = 581,
  [SMALL_STATE(25)] = 595,
  [SMALL_STATE(26)] = 609,
  [SMALL_STATE(27)] = 623,
  [SMALL_STATE(28)] = 633,
  [SMALL_STATE(29)] = 640,
  [SMALL_STATE(30)] = 653,
  [SMALL_STATE(31)] = 660,
  [SMALL_STATE(32)] = 673,
  [SMALL_STATE(33)] = 686,
  [SMALL_STATE(34)] = 699,
  [SMALL_STATE(35)] = 710,
  [SMALL_STATE(36)] = 723,
  [SMALL_STATE(37)] = 736,
  [SMALL_STATE(38)] = 749,
  [SMALL_STATE(39)] = 762,
  [SMALL_STATE(40)] = 773,
  [SMALL_STATE(41)] = 784,
  [SMALL_STATE(42)] = 797,
  [SMALL_STATE(43)] = 808,
  [SMALL_STATE(44)] = 821,
  [SMALL_STATE(45)] = 832,
  [SMALL_STATE(46)] = 838,
  [SMALL_STATE(47)] = 844,
  [SMALL_STATE(48)] = 852,
  [SMALL_STATE(49)] = 860,
  [SMALL_STATE(50)] = 870,
  [SMALL_STATE(51)] = 880,
  [SMALL_STATE(52)] = 890,
  [SMALL_STATE(53)] = 900,
  [SMALL_STATE(54)] = 910,
  [SMALL_STATE(55)] = 920,
  [SMALL_STATE(56)] = 928,
  [SMALL_STATE(57)] = 938,
  [SMALL_STATE(58)] = 944,
  [SMALL_STATE(59)] = 950,
  [SMALL_STATE(60)] = 956,
  [SMALL_STATE(61)] = 966,
  [SMALL_STATE(62)] = 974,
  [SMALL_STATE(63)] = 984,
  [SMALL_STATE(64)] = 990,
  [SMALL_STATE(65)] = 998,
  [SMALL_STATE(66)] = 1004,
  [SMALL_STATE(67)] = 1010,
  [SMALL_STATE(68)] = 1016,
  [SMALL_STATE(69)] = 1022,
  [SMALL_STATE(70)] = 1028,
  [SMALL_STATE(71)] = 1034,
  [SMALL_STATE(72)] = 1042,
  [SMALL_STATE(73)] = 1049,
  [SMALL_STATE(74)] = 1056,
  [SMALL_STATE(75)] = 1063,
  [SMALL_STATE(76)] = 1070,
  [SMALL_STATE(77)] = 1077,
  [SMALL_STATE(78)] = 1084,
  [SMALL_STATE(79)] = 1089,
  [SMALL_STATE(80)] = 1094,
  [SMALL_STATE(81)] = 1101,
  [SMALL_STATE(82)] = 1106,
  [SMALL_STATE(83)] = 1113,
  [SMALL_STATE(84)] = 1120,
  [SMALL_STATE(85)] = 1127,
  [SMALL_STATE(86)] = 1131,
  [SMALL_STATE(87)] = 1135,
  [SMALL_STATE(88)] = 1139,
  [SMALL_STATE(89)] = 1143,
  [SMALL_STATE(90)] = 1147,
  [SMALL_STATE(91)] = 1151,
  [SMALL_STATE(92)] = 1155,
  [SMALL_STATE(93)] = 1159,
  [SMALL_STATE(94)] = 1163,
  [SMALL_STATE(95)] = 1167,
  [SMALL_STATE(96)] = 1171,
  [SMALL_STATE(97)] = 1175,
  [SMALL_STATE(98)] = 1179,
  [SMALL_STATE(99)] = 1183,
  [SMALL_STATE(100)] = 1187,
  [SMALL_STATE(101)] = 1191,
  [SMALL_STATE(102)] = 1195,
  [SMALL_STATE(103)] = 1199,
  [SMALL_STATE(104)] = 1203,
  [SMALL_STATE(105)] = 1207,
  [SMALL_STATE(106)] = 1211,
  [SMALL_STATE(107)] = 1215,
  [SMALL_STATE(108)] = 1219,
  [SMALL_STATE(109)] = 1223,
  [SMALL_STATE(110)] = 1227,
  [SMALL_STATE(111)] = 1231,
  [SMALL_STATE(112)] = 1235,
  [SMALL_STATE(113)] = 1239,
  [SMALL_STATE(114)] = 1243,
  [SMALL_STATE(115)] = 1247,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arrow, 1),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_arrow, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kw_equals, 1),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_kw_equals, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_repeat1, 2), SHIFT_REPEAT(89),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 2),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 5),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 4),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_identifier, 1),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_term_definition_repeat1, 2),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_term_definition_repeat1, 2), SHIFT_REPEAT(57),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_literal_function_repeat1, 1),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_name, 1),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_literal_list_repeat1, 2), SHIFT_REPEAT(8),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_literal_list_repeat1, 2),
  [136] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_type_repeat1, 2), SHIFT_REPEAT(89),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [143] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_literal_function_repeat1, 2), SHIFT_REPEAT(21),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_literal_function_repeat1, 2),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_function, 3),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_typelink, 2),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 1),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_variable, 1),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_tuple, 4),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_list, 4),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_signature_colon, 1),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_signature_colon, 1),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_tuple, 3),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_list, 3),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_boolean, 1),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_list, 2),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal_tuple, 2),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_name, 1),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_type_repeat1, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_multiline, 3),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_documentation_block, 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_declaration, 2),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_definition, 3),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_line, 4),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kw_forall, 1),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_declaration, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_signature, 4),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unison, 1),
  [242] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_definition, 4),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_fold, 4),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_unison_external_scanner_create(void);
void tree_sitter_unison_external_scanner_destroy(void *);
bool tree_sitter_unison_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_unison_external_scanner_serialize(void *, char *);
void tree_sitter_unison_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_unison(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_unison_external_scanner_create,
      tree_sitter_unison_external_scanner_destroy,
      tree_sitter_unison_external_scanner_scan,
      tree_sitter_unison_external_scanner_serialize,
      tree_sitter_unison_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
