//alias('([], _) = x', $.DESTRUCTURE)//
const {
  sep1,
  block,
  open_block_with,
  openBlockWith,
  layoutBlock,
} = require("./util");

module.exports = {
  _statement: ($) =>
    choice(
      alias($._binding, $.term_declaration),
      $.destructuring_bind, // TODO this is a problem where things gravitate toward this instead of block term for RHS of a KW_EQUALS
      $._block_term,
    ),
  term_definition2: ($) =>
    prec.right(seq($._lhs, openBlockWith($, $.kw_equals), $.__block)),

  __block: ($) =>
    seq(
      optional(
        seq(sep1($._layout_semicolon, $.use_clause), $._layout_semicolon),
      ),
      // terminated($, $._statement),
      seq(
        prec.right(sep1($._layout_semicolon, choice($._statement))),
        optional($._layout_semicolon),
      ),
      $._layout_end,
    ),

  __layout_block: ($) =>
    prec.right(
      seq(
        optional(
          seq(sep1($._layout_semicolon, $.use_clause), $._layout_semicolon),
        ),
        seq(
          sep1($._layout_semicolon, $._statement),
          optional($._layout_semicolon),
        ),
        optional($._layout_end),
      ),
    ),

  binding: ($) => $._binding,
  documented_binding: ($) => seq($.doc_block, $._layout_semicolon, $._binding),
  _binding: ($) =>
    seq(
      optional($.type_signature),
      alias($.term_definition2, $.term_definition),
    ),
  destructuring_bind: ($) =>
    choice(
      seq(
        choice($.parenthesized_or_tuple_pattern),
        openBlockWith($, $.kw_equals),
        $.__layout_block,
      ),
    ),

  _block_term: ($) => choice($.literal_function, $._infix_app_or_boolean_op),
  literal_function: ($) => lam($, $._term),
  literal_function2: ($) => lam($, $._term2),
  _term: ($) => $._term2,
  _term2: ($) =>
    choice(alias($.literal_function2, $.literal_function), $._term3),
  _term3: ($) =>
    prec.right(
      seq(
        $._infix_app_or_boolean_op,
        optional(seq($.type_signature_colon, $._computation_type)),
      ),
    ),
  _term4: ($) => repeat1($._term_leaf),

  _infix_app_or_boolean_op: ($) =>
    prec.right(sep1($._generic_infix_app, choice($._term4))),
  _generic_infix_app: ($) => choice($.and, $.or, $._infix),
  _infix: ($) => seq($._hq_qualified_infix_term, optional($._layout_semicolon)),
};

lam = ($, term) =>
  seq($._prefix_definition_name, alias("->", $.arrow_symbol), term);
