const { openBlockWith, block, open_block_with, layoutBlock, sep, sep1 } = require("./util");

module.exports = {
  delay_quote: ($) => seq("'", $._term_leaf),


  bang: ($) => seq("!", $._term_leaf),
  delay_block: $ => layoutBlock($, $.do),

  _number: $ => choice($.float, $.nat, $.int),
  _link: $ => choice($.literal_termlink, $.literal_typelink),
  _term_leaf: ($) =>
      choice(
        $.force,
        $._hq_qualified_prefix_term,
        $.literal_text,
        $.literal_char,
        $._number,
        $.literal_byte,
        $.literal_hex,
        $.literal_boolean,
        $._link,
        $.tuple_or_parenthesized,
        $._keyword_block,
        $.literal_list,
        $.delay_quote,
        $.delay_block,
        $.bang,
        $.doc_block,
      ),
  literal_list: $ => seq(
    alias('[', $.open_bracket),
    sep(',', $._term),
    alias(']', $.close_bracket),
  ),
  _keyword_block: ($) =>
    choice(
      $.exp_let,
      $.handler,
      $.rewrite_block,
      $.exp_if,
      $._pattern_matching, // this is match and lam case
    ),

  // Note: do not convert this to use layoutBlock because there is an infinite loop when running `tree-sitter generate`
  exp_if: $ =>
    prec.right(
      seq(
        openBlockWith($, $.kw_if),
        $.__block,
        openBlockWith($, $.kw_then),
        $.__block,
        openBlockWith($, $.kw_else),
        $.__block,
      ),
    ),

  // foo()
  force: $ => seq($._hq_qualified_prefix_term, alias('()', $.unit)),
};

// const list = ($) => $ => seq('[', ']')

// const block = ($, opener) =>
//   seq(
//     opener,
//     $._layout_start,
//     // openBlockWith(opener),
//     // repeat($.use_clause),
//     sep1(alias($._layout_semicolon, $.DELAY_SEMI), choice(/*"s: Int",*/ $._statement)),
//     $._layout_end,
//   );
