#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 38
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 56
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum {
  sym__eol = 1,
  anon_sym_DASH_DASH = 2,
  aux_sym_comment_token1 = 3,
  anon_sym_forall = 4,
  anon_sym_ = 5,
  anon_sym_EQ = 6,
  anon_sym_COLON = 7,
  sym__lowercase_regular_identifier = 8,
  sym__regular_identifier = 9,
  anon_sym_DASH_GT = 10,
  anon_sym_DOT = 11,
  anon_sym_SQUOTE = 12,
  anon_sym_do = 13,
  anon_sym_PIPE = 14,
  anon_sym_BANG = 15,
  anon_sym_BQUOTE = 16,
  anon_sym_if = 17,
  anon_sym_then = 18,
  anon_sym_else = 19,
  anon_sym_handle = 20,
  anon_sym_unique = 21,
  anon_sym_structural = 22,
  anon_sym_where = 23,
  anon_sym_use = 24,
  anon_sym_AMP_AMP = 25,
  anon_sym_PIPE_PIPE = 26,
  anon_sym_true = 27,
  anon_sym_false = 28,
  anon_sym_type = 29,
  anon_sym_ability = 30,
  anon_sym_alias = 31,
  anon_sym_let = 32,
  anon_sym_namespace = 33,
  anon_sym_cases = 34,
  anon_sym_match = 35,
  anon_sym_with = 36,
  anon_sym_termLink = 37,
  anon_sym_typeLink = 38,
  sym_unison = 39,
  sym_comment = 40,
  sym_kw_forall = 41,
  sym_kw_equals = 42,
  sym_type_signature_colon = 43,
  sym_type_signature = 44,
  sym_type_name = 45,
  sym_name = 46,
  sym_expression = 47,
  sym_term_definition = 48,
  sym_term_declaration = 49,
  sym_regular_identifier = 50,
  sym_type_variable = 51,
  sym_type_arrow = 52,
  sym_type = 53,
  aux_sym_type_repeat1 = 54,
  aux_sym_type_repeat2 = 55,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__eol] = "_eol",
  [anon_sym_DASH_DASH] = "--",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_forall] = "forall",
  [anon_sym_] = "∀",
  [anon_sym_EQ] = "=",
  [anon_sym_COLON] = ":",
  [sym__lowercase_regular_identifier] = "_lowercase_regular_identifier",
  [sym__regular_identifier] = "_regular_identifier",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_DOT] = ".",
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
  [anon_sym_use] = "use",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_type] = "type",
  [anon_sym_ability] = "ability",
  [anon_sym_alias] = "alias",
  [anon_sym_let] = "let",
  [anon_sym_namespace] = "namespace",
  [anon_sym_cases] = "cases",
  [anon_sym_match] = "match",
  [anon_sym_with] = "with",
  [anon_sym_termLink] = "termLink",
  [anon_sym_typeLink] = "typeLink",
  [sym_unison] = "unison",
  [sym_comment] = "comment",
  [sym_kw_forall] = "kw_forall",
  [sym_kw_equals] = "kw_equals",
  [sym_type_signature_colon] = "type_signature_colon",
  [sym_type_signature] = "type_signature",
  [sym_type_name] = "type_name",
  [sym_name] = "name",
  [sym_expression] = "expression",
  [sym_term_definition] = "term_definition",
  [sym_term_declaration] = "term_declaration",
  [sym_regular_identifier] = "regular_identifier",
  [sym_type_variable] = "type_variable",
  [sym_type_arrow] = "type_arrow",
  [sym_type] = "type",
  [aux_sym_type_repeat1] = "type_repeat1",
  [aux_sym_type_repeat2] = "type_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__eol] = sym__eol,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_forall] = anon_sym_forall,
  [anon_sym_] = anon_sym_,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym__lowercase_regular_identifier] = sym__lowercase_regular_identifier,
  [sym__regular_identifier] = sym__regular_identifier,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_DOT] = anon_sym_DOT,
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
  [anon_sym_use] = anon_sym_use,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_ability] = anon_sym_ability,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_namespace] = anon_sym_namespace,
  [anon_sym_cases] = anon_sym_cases,
  [anon_sym_match] = anon_sym_match,
  [anon_sym_with] = anon_sym_with,
  [anon_sym_termLink] = anon_sym_termLink,
  [anon_sym_typeLink] = anon_sym_typeLink,
  [sym_unison] = sym_unison,
  [sym_comment] = sym_comment,
  [sym_kw_forall] = sym_kw_forall,
  [sym_kw_equals] = sym_kw_equals,
  [sym_type_signature_colon] = sym_type_signature_colon,
  [sym_type_signature] = sym_type_signature,
  [sym_type_name] = sym_type_name,
  [sym_name] = sym_name,
  [sym_expression] = sym_expression,
  [sym_term_definition] = sym_term_definition,
  [sym_term_declaration] = sym_term_declaration,
  [sym_regular_identifier] = sym_regular_identifier,
  [sym_type_variable] = sym_type_variable,
  [sym_type_arrow] = sym_type_arrow,
  [sym_type] = sym_type,
  [aux_sym_type_repeat1] = aux_sym_type_repeat1,
  [aux_sym_type_repeat2] = aux_sym_type_repeat2,
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
  [aux_sym_comment_token1] = {
    .visible = false,
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
  [anon_sym_use] = {
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
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
  [anon_sym_termLink] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_typeLink] = {
    .visible = true,
    .named = false,
  },
  [sym_unison] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
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
  [sym_expression] = {
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
  [aux_sym_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_repeat2] = {
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
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(12);
      if (lookahead == '!') ADVANCE(111);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == '.') ADVANCE(107);
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '`') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'c') ADVANCE(23);
      if (lookahead == 'd') ADVANCE(78);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == 'f') ADVANCE(31);
      if (lookahead == 'h') ADVANCE(24);
      if (lookahead == 'i') ADVANCE(52);
      if (lookahead == 'l') ADVANCE(46);
      if (lookahead == 'm') ADVANCE(28);
      if (lookahead == 'n') ADVANCE(25);
      if (lookahead == 's') ADVANCE(98);
      if (lookahead == 't') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(77);
      if (lookahead == 'w') ADVANCE(55);
      if (lookahead == '|') ADVANCE(110);
      if (lookahead == 8704) ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 3:
      if (lookahead == '&') ADVANCE(121);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(14);
      if (lookahead == '>') ADVANCE(106);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(107);
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(106);
      END_STATE();
    case 10:
      if (lookahead == 'f') ADVANCE(79);
      if (lookahead == 8704) ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 11:
      if (eof) ADVANCE(12);
      if (lookahead == '!') ADVANCE(111);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(108);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == ':') ADVANCE(20);
      if (lookahead == '=') ADVANCE(19);
      if (lookahead == '`') ADVANCE(112);
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'c') ADVANCE(23);
      if (lookahead == 'd') ADVANCE(78);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == 'f') ADVANCE(31);
      if (lookahead == 'h') ADVANCE(24);
      if (lookahead == 'i') ADVANCE(52);
      if (lookahead == 'l') ADVANCE(46);
      if (lookahead == 'm') ADVANCE(28);
      if (lookahead == 'n') ADVANCE(25);
      if (lookahead == 's') ADVANCE(98);
      if (lookahead == 't') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(77);
      if (lookahead == 'w') ADVANCE(55);
      if (lookahead == '|') ADVANCE(110);
      if (lookahead == 8704) ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym__eol);
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(1);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_forall);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym__lowercase_regular_identifier);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'L') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'a') ADVANCE(70);
      if (lookahead == 'o') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'b') ADVANCE(57);
      if (lookahead == 'l') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'c') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'c') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'c') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'd') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(83);
      if (lookahead == 'h') ADVANCE(47);
      if (lookahead == 'r') ADVANCE(101);
      if (lookahead == 'y') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'e') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'f') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'h') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'h') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'h') ADVANCE(51);
      if (lookahead == 'i') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'i') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'k') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'k') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'l') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'm') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'm') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'n') ADVANCE(56);
      if (lookahead == 's') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'o') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'o') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'p') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'p') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'q') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'r') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 's') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 't') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'u') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'u') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'u') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'u') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (lookahead == 'y') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__regular_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_do);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(122);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_then);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_handle);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_unique);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_structural);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_where);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_use);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_type);
      if (lookahead == 'L') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_ability);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_alias);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_namespace);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_cases);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_match);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_with);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_termLink);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_typeLink);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(105);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 6},
  [2] = {.lex_state = 10},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 10},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 7},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 6},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 6},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_forall] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym__regular_identifier] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
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
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_ability] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_namespace] = ACTIONS(1),
    [anon_sym_cases] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym_with] = ACTIONS(1),
    [anon_sym_termLink] = ACTIONS(1),
    [anon_sym_typeLink] = ACTIONS(1),
  },
  [1] = {
    [sym_unison] = STATE(36),
    [sym_comment] = STATE(35),
    [sym_type_signature] = STATE(10),
    [sym_name] = STATE(20),
    [sym_term_definition] = STATE(30),
    [sym_term_declaration] = STATE(35),
    [sym_regular_identifier] = STATE(14),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__regular_identifier] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      anon_sym_forall,
    ACTIONS(9), 1,
      anon_sym_,
    ACTIONS(11), 1,
      sym__regular_identifier,
    STATE(9), 1,
      sym_type_name,
    STATE(11), 1,
      sym_kw_forall,
    STATE(24), 1,
      sym_type,
  [19] = 4,
    ACTIONS(13), 1,
      sym__eol,
    ACTIONS(15), 1,
      anon_sym_DASH_GT,
    STATE(5), 1,
      aux_sym_type_repeat2,
    STATE(15), 1,
      sym_type_arrow,
  [32] = 4,
    ACTIONS(15), 1,
      anon_sym_DASH_GT,
    ACTIONS(17), 1,
      sym__eol,
    STATE(3), 1,
      aux_sym_type_repeat2,
    STATE(15), 1,
      sym_type_arrow,
  [45] = 4,
    ACTIONS(19), 1,
      sym__eol,
    ACTIONS(21), 1,
      anon_sym_DASH_GT,
    STATE(5), 1,
      aux_sym_type_repeat2,
    STATE(15), 1,
      sym_type_arrow,
  [58] = 3,
    ACTIONS(24), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(27), 1,
      anon_sym_DOT,
    STATE(6), 2,
      sym_type_variable,
      aux_sym_type_repeat1,
  [69] = 4,
    ACTIONS(15), 1,
      anon_sym_DASH_GT,
    ACTIONS(29), 1,
      sym__eol,
    STATE(5), 1,
      aux_sym_type_repeat2,
    STATE(15), 1,
      sym_type_arrow,
  [82] = 3,
    ACTIONS(31), 1,
      sym__lowercase_regular_identifier,
    ACTIONS(33), 1,
      anon_sym_DOT,
    STATE(6), 2,
      sym_type_variable,
      aux_sym_type_repeat1,
  [93] = 4,
    ACTIONS(15), 1,
      anon_sym_DASH_GT,
    ACTIONS(35), 1,
      sym__eol,
    STATE(7), 1,
      aux_sym_type_repeat2,
    STATE(15), 1,
      sym_type_arrow,
  [106] = 3,
    ACTIONS(37), 1,
      sym__regular_identifier,
    STATE(20), 1,
      sym_name,
    STATE(25), 1,
      sym_term_definition,
  [116] = 2,
    ACTIONS(31), 1,
      sym__lowercase_regular_identifier,
    STATE(8), 2,
      sym_type_variable,
      aux_sym_type_repeat1,
  [124] = 2,
    ACTIONS(41), 1,
      anon_sym_,
    ACTIONS(39), 2,
      anon_sym_forall,
      sym__regular_identifier,
  [132] = 1,
    ACTIONS(43), 3,
      anon_sym_EQ,
      sym__lowercase_regular_identifier,
      anon_sym_DOT,
  [138] = 2,
    ACTIONS(45), 1,
      anon_sym_COLON,
    STATE(2), 1,
      sym_type_signature_colon,
  [145] = 2,
    ACTIONS(47), 1,
      sym__regular_identifier,
    STATE(18), 1,
      sym_type_name,
  [152] = 2,
    ACTIONS(49), 1,
      anon_sym_EQ,
    STATE(19), 1,
      sym_kw_equals,
  [159] = 2,
    ACTIONS(51), 1,
      anon_sym_COLON,
    ACTIONS(53), 1,
      sym__lowercase_regular_identifier,
  [166] = 2,
    ACTIONS(19), 1,
      sym__eol,
    ACTIONS(55), 1,
      anon_sym_DASH_GT,
  [173] = 2,
    ACTIONS(57), 1,
      aux_sym_comment_token1,
    STATE(26), 1,
      sym_expression,
  [180] = 2,
    ACTIONS(31), 1,
      sym__lowercase_regular_identifier,
    STATE(16), 1,
      sym_type_variable,
  [187] = 2,
    ACTIONS(59), 1,
      sym__eol,
    ACTIONS(61), 1,
      anon_sym_DASH_GT,
  [194] = 2,
    ACTIONS(47), 1,
      sym__regular_identifier,
    STATE(4), 1,
      sym_type_name,
  [201] = 1,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
  [205] = 1,
    ACTIONS(65), 1,
      sym__eol,
  [209] = 1,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
  [213] = 1,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
  [217] = 1,
    ACTIONS(71), 1,
      sym__eol,
  [221] = 1,
    ACTIONS(73), 1,
      sym__regular_identifier,
  [225] = 1,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
  [229] = 1,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
  [233] = 1,
    ACTIONS(79), 1,
      sym__regular_identifier,
  [237] = 1,
    ACTIONS(53), 1,
      sym__lowercase_regular_identifier,
  [241] = 1,
    ACTIONS(81), 1,
      aux_sym_comment_token1,
  [245] = 1,
    ACTIONS(83), 1,
      sym__lowercase_regular_identifier,
  [249] = 1,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
  [253] = 1,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
  [257] = 1,
    ACTIONS(89), 1,
      aux_sym_comment_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 45,
  [SMALL_STATE(6)] = 58,
  [SMALL_STATE(7)] = 69,
  [SMALL_STATE(8)] = 82,
  [SMALL_STATE(9)] = 93,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 116,
  [SMALL_STATE(12)] = 124,
  [SMALL_STATE(13)] = 132,
  [SMALL_STATE(14)] = 138,
  [SMALL_STATE(15)] = 145,
  [SMALL_STATE(16)] = 152,
  [SMALL_STATE(17)] = 159,
  [SMALL_STATE(18)] = 166,
  [SMALL_STATE(19)] = 173,
  [SMALL_STATE(20)] = 180,
  [SMALL_STATE(21)] = 187,
  [SMALL_STATE(22)] = 194,
  [SMALL_STATE(23)] = 201,
  [SMALL_STATE(24)] = 205,
  [SMALL_STATE(25)] = 209,
  [SMALL_STATE(26)] = 213,
  [SMALL_STATE(27)] = 217,
  [SMALL_STATE(28)] = 221,
  [SMALL_STATE(29)] = 225,
  [SMALL_STATE(30)] = 229,
  [SMALL_STATE(31)] = 233,
  [SMALL_STATE(32)] = 237,
  [SMALL_STATE(33)] = 241,
  [SMALL_STATE(34)] = 245,
  [SMALL_STATE(35)] = 249,
  [SMALL_STATE(36)] = 253,
  [SMALL_STATE(37)] = 257,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 5),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_repeat2, 2),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_type_repeat2, 2), SHIFT_REPEAT(28),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_repeat1, 2), SHIFT_REPEAT(13),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_repeat1, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 2),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_signature_colon, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_signature_colon, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_variable, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_identifier, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name, 1),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_type_repeat2, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_name, 1),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_name, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_declaration, 2),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_definition, 4),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arrow, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term_declaration, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_signature, 4),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kw_forall, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unison, 1),
  [87] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kw_equals, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
