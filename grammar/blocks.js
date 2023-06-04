const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')
const { sep } = require('./util')

module.exports = {
  ...funcApp,
  
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
  
  // semi: $ => $._layout_semicolon,
  // layout_start: $ => $._layout_start,
  // layout_end: $ => $._layout_end,
  // statement: $ => $._statement,
  // expression: $ => $._expression,
  _multiline_block: $ => seq(
    optional(seq(sep1($._layout_semicolon, $._statement))),
    $._expression,
  ),
  _block: $ => seq(
    $._layout_start,
    $._multiline_block,
    $._layout_end,
  ),
}