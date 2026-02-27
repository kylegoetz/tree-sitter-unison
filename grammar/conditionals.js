const { KEYWORD } = require('./precedences')

module.exports = {
  _boolean_exp: $ =>
    prec.left(
      '_boolean_exp',
      seq($._expression, choice($.or, $.and), $._expression),
    ),

  kw_if: $ => prec(KEYWORD, 'if'),
  kw_then: $ => prec(KEYWORD, 'then'),
  kw_else: $ => prec(KEYWORD, 'else'),
  if_block: $ => seq($.kw_if, $.__block),
  then_block: $ => seq($.kw_then, $.__block),
  else_block: $ =>
    seq(
      $.kw_else,
      seq(
        $._layout_start,
        repeat(seq(choice($._statement, $.use_clause), $._layout_semicolon)),
        $.block_term,
        optional($._layout_end),
      ),
    ),
  // Note: do not convert this to use layoutBlock because there is an infinite loop when running `tree-sitter generate`
  exp_if: $ => prec.right(seq($.if_block, $.then_block, $.else_block)),
}
