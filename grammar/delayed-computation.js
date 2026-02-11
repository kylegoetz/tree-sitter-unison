const {
  openBlockWith,
  block,
  open_block_with,
  layoutBlock,
  sep,
  sep1,
} = require('./util')

module.exports = {
  delay_quote: $ => seq("'", $._term_leaf),

  bang: $ => seq('!', $._term_leaf),
  delay_block: $ => prec.right(layoutBlock($, $.do)),

  _number: $ => choice($.float, $.nat, $.int),
  _link: $ => choice($.literal_termlink, $.literal_typelink),
  _term_leaf: $ =>
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
      $.unit,
    ),
  literal_list: $ =>
    seq(
      alias('[', $.open_bracket),
      $._layout_start,
      sep(seq(optional($._layout_semicolon), alias(',', $.comma)), $._term),
      $._layout_end,
      alias(']', $.close_bracket),
    ),
  _keyword_block: $ =>
    choice(
      $.exp_let,
      $.handler,
      $.rewrite_block,
      $.exp_if,
      $._pattern_matching, // this is match and lam case
    ),

  force: $ =>
    seq($._hq_qualified_prefix_term, alias(token.immediate('()'), $.unit)),
}
