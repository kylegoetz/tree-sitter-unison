//alias('([], _) = x', $.DESTRUCTURE)//
const {
  sep1,
  block,
  open_block_with,
  openBlockWith,
  layoutBlock,
} = require('./util')

module.exports = {
  _statement: $ =>
    choice(
      $.block_term,
      alias($._binding, $.term_declaration),
      $.destructuring_bind,
    ),
  term_definition2: $ => prec.right(seq($._lhs, layoutBlock($, $.kw_equals))),

  // This exists because of the if/then/else definition. See that definition for more info.
  __block: $ =>
    seq(
      $._layout_start,
      repeat(seq(choice($._statement, $.use_clause), $._layout_semicolon)),
      $.block_term,
      $._layout_end,
    ),

  binding: $ => $._binding,
  documented_binding: $ => seq($.doc_block, $._layout_semicolon, $._binding),
  _binding: $ =>
    seq(
      optional($.type_signature),
      alias($.term_definition2, $.term_definition),
    ),
  destructuring_bind: $ =>
    prec.dynamic(
      1,
      seq(
        choice(
          seq(
            alias($._hq_qualified_prefix_term, $.regular_identifier),
            alias('@', $.at_token),
            $._pattern_leaf,
          ),
          $.parenthesized_or_tuple_pattern,
        ),
        layoutBlock($, $.kw_equals),
      ),
    ),

  block_term: $ => choice($.literal_function, $._infix_app_or_boolean_op),
  literal_function: $ => lam($, $._term),
  literal_function2: $ => lam($, $._term2),
  _term: $ => $._term2,
  _term2: $ => choice(alias($.literal_function2, $.literal_function), $._term3),
  _term3: $ =>
    prec.right(
      seq(
        $._infix_app_or_boolean_op,
        optional(seq($.type_signature_colon, $._computation_type)),
      ),
    ),
  _term4: $ => repeat1($._term_leaf),

  _infix_app_or_boolean_op: $ =>
    prec.right(sep1($._generic_infix_app, choice($._term4))),
  _generic_infix_app: $ => choice($.and, $.or, $._infix),
  _infix: $ => seq($._hq_qualified_infix_term, optional($._layout_semicolon)),

  var_or_nullary_ctor: $ => $._hq_qualified_prefix_term,
}

lam = ($, term) =>
  seq(repeat1($._prefix_definition_name), alias('->', $.arrow_symbol), term)
