const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')

module.exports = {
  ...funcApp,
  expression: $ => $._expression,
  
  kw_if: $ => prec(KEYWORD, 'if'),
  kw_then: $ => prec(KEYWORD, 'then'),
  kw_else: $ => prec(KEYWORD, 'else'),
  
  exp_if: $ => prec.left(KEYWORD, seq(
    $.kw_if,
    field('if_block', $._block),
    $.kw_then,
    field('then_block', $._block),
    $.kw_else,
    field('else_block', $._block),
  )),
  
  operator_expression: $ => seq(
    $._expression,
    $.operator,
    $._expression
  ),
  
  _block: $ => seq(
    $._layout_start,
    optional(sep1(choice(';', $._layout_semicolon), $._statement)),
    $.expression,
    $._layout_end,
  ),
}