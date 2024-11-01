const { sep, sep1 } = require("./util");

module.exports = {
  _statement: ($) =>
    choice(
      prec(2, alias($.binding, $.term_declaration)),
      $.destructuring_bind,
      prec(1, $._block_term),
    ),

  term_definition2: ($) => seq(block($, $.kw_equals)),

  binding: ($) =>
    choice(
      // "s: Int\n    s = (0: Int)",
      seq(
        optional(seq($.doc_block, $._layout_semicolon)),
        optional($.type_signature),
        alias($.term_definition2, $.term_definition),
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
      choice(
        // alias("0: Int", $.tmp2),
        seq(
          choice($._infix_app_or_boolean_op),
          optional(seq($.type_signature_colon, $._computation_type)),
        ),
      ),
    ),
  _term4: ($) => prec.right(repeat1($._term_leaf)),

  _infix_app_or_boolean_op: ($) =>
    prec.right(sep1($._generic_infix_app, $._term4)),
  _generic_infix_app: ($) => choice("&&", "||", $._infix),
  _infix: ($) => seq($._hq_qualified_infix_term, optional($._layout_semicolon)),
};

lam = ($, term) =>
  seq($._prefix_definition_name, alias("->", $.arrow_symbol), term);

const block = ($, opener) =>
  seq(
    opener,
    $._layout_start,
    // openBlockWith(opener),
    // repeat(seq($.use_clause, $._layout_semicolon)),
    sep1($._layout_semicolon, $.use_clause),
    optional($._layout_semicolon),
    // sep($._layout_semicolon, $.use_clause),
    // optional($._layout_semi)
    prec.right(sep1($._layout_semicolon, choice(/*"s: Int",*/ $._statement))),
    optional($._layout_semicolon),
    $._layout_end,
  );
