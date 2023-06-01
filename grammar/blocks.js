const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')
const { sep } = require('./util')

module.exports = {
  ...funcApp,
  
  /**
   * Let:
   * let [block]
   * Examples:
   * x = let y = 5
   *         z = 1
   *         y + z
   */
  kw_let: _ => 'let',
  exp_let: $ => seq($.kw_let, $._block),
  
  kw_if: $ => prec(KEYWORD, 'if'),
  kw_then: $ => prec(KEYWORD, 'then'),
  kw_else: $ => prec(KEYWORD, 'else'),
  
  /**
   *
   */
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
  
  _semi: $ => $._layout_semicolon,
  _multiline_block: $ => seq(
    optional(seq(sep1($._semi, $._statement), $._semi)),
    $._expression,
  ),
  
  _block: $ => seq(
    $._layout_start,
    $._multiline_block,
    $._layout_end,
  ),
}