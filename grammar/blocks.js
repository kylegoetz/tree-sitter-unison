const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')
const { sep } = require('./util')

module.exports = {
  ...funcApp,
  
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
  
  // _semi: $ => choice(';', $._layout_semicolon),
  _semi: $ => $._layout_semicolon,
  _multiline_block: $ => seq(
    optional(seq(sep($._semi, $._statement), $._semi)),
    $._expression,
  ),
  // __block: $ => choice(
    // $._multiline_block,
    // $._expression,
  // ),
  
  _block: $ => seq(
    $._layout_start,
    // $.__block,
    $._multiline_block,
    // optional(seq(sep1($._semi, $._statement), $._semi)),
    // $._expression,
    $._layout_end,
  ),
  // _block: $ => seq($._layout_start, optional(seq(sep1($._semi, $._statement), $._semi)), $._expression, $._layout_end),
}