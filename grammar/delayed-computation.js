const { openBlockWith, block, open_block_with, layoutBlock, sep, sep1 } = require("./util");

module.exports = {
  delay_quote: ($) => seq("'", $._term_leaf),

  delay_block: $ => prec.right(open_block_with($, $.do)),

  bang: ($) => seq("!", $._term_leaf),

  _number: $ => choice($.float, $.nat, $.int),
  _link: $ => choice($.literal_termlink, $.literal_typelink),
  _term_leaf: ($) =>
    prec.right(2,
      choice(
        $.force,
        prec(2, $._hq_qualified_prefix_term),
        $.literal_text,
        $.literal_char,
        $._number,
        $.literal_byte,
        $.literal_hex,
        $.literal_boolean,
        $._link,
        prec(1, $.tuple_or_parenthesized),
        $._keyword_block,
        $.literal_list,
        $.delay_quote,
        $.delay_block,
        $.bang,
        $.doc_block,
      ),
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
      $.exp_if,
      $._pattern_matching, // this is match and lam case
    ),


  exp_if: ($) => //'temporarily commented out for compilation sake during testing'
    // prec.right(seq(block($, $.kw_if), block($, $.kw_then), layoutBlock($, $.kw_else))),
    prec.right(seq(
      openBlockWith($, $.kw_if),
      $.__block,
      openBlockWith($, $.kw_then),
      $.__block,
      openBlockWith($, $.kw_else),
      $.__block)),

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
