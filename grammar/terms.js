const { sep1, block, open_block_with, openBlockWith, layoutBlock } = require("./util");

module.exports = {
  _statement: ($) =>
    choice(
      prec(3, alias($._binding, $.term_declaration)),
      prec.right(2, $._block_term),
      // $.destructuring_bind, // TODO this is a problem where things gravitate toward this instead of block term for RHS of a KW_EQUALS
    ),
  term_definition2: ($) => prec.right(seq(
    $._lhs,
    openBlockWith($, $.kw_equals),
    $.__block)),

  __block: $ => seq(
    optional(seq(sep1($._layout_semicolon, $.use_clause), $._layout_semicolon)),
    // terminated($, $._statement),
    seq(prec.right(sep1($._layout_semicolon, $._statement))/*, optional($._layout_semicolon)*/),
    $._layout_end
  ),

  binding: ($) =>
    seq(
      optional(seq($.doc_block, $._layout_semicolon)),
      $._binding,
    ),
  _binding: $ => seq(optional($.type_signature),
    alias($.term_definition2, $.term_definition)),
  destructuring_bind: $ => seq(
    $._pattern_root,
    block($, $.kw_equals)
  ),

  _block_term: ($) => choice($.literal_function, $._infix_app_or_boolean_op),
  literal_function: ($) => lam($, $._term),
  literal_function2: ($) => lam($, $._term2),
  _term: ($) => $._term2,
  _term2: ($) =>
    choice(alias($.literal_function2, $.literal_function), $._term3),
  _term3: ($) =>
    prec.right(seq(
      $._infix_app_or_boolean_op,
      optional(seq($.type_signature_colon, $._computation_type)),
    )),
  _term4: ($) => prec.right(repeat1(prec.right(choice($._hq_qualified_prefix_term, $._term_leaf)))),

  _infix_app_or_boolean_op: ($) =>
    prec.right(sep1($._generic_infix_app, $._term4)),
  _generic_infix_app: ($) => choice($.and, $.or, $._infix),
  _infix: ($) => seq($._hq_qualified_infix_term, optional($._layout_semicolon)),
};

lam = ($, term) =>
  seq($._prefix_definition_name, alias('->', $.arrow_symbol), term)
