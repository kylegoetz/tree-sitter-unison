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
}
