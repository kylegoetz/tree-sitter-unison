const { KEYWORD } = require('./precedences')

module.exports = { 
  _boolean_exp: $ => prec.left('_boolean_exp', seq($._expression, choice($.or, $.and), $._expression)),
  
  kw_if: $ => prec(KEYWORD, 'if'),
  kw_then: $ => prec(KEYWORD, 'then'),
  kw_else: $ => prec(KEYWORD, 'else'),
  
  /**
   * if [block] then [block] else [block]
   */
  exp_if: $ => prec.left(KEYWORD, seq(
    $.kw_if,
    field('if_block', $._block),
    $.kw_then,
    field('then_block', $._block),
    $.kw_else,
    field('else_block', $._block),
  )),
}