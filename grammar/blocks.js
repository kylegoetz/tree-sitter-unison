const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')
const { sep, layouted } = require('./util')

module.exports = {
  ...funcApp,
  
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
  multiline_block: $ => seq(
    optional(seq(sep1($._layout_semicolon, $._statement))),
    // sep($.semi, choice($.statement, $.expression)),
    // sep($.semi, $.statement),
    // choice('x + foo 8 102.0 +4', $._expression),
    // $._expression,
    $.expression,
    // $.literal_function,
  ),
  _block: $ => seq(
    $.layout_start,
    $.multiline_block,
    $.layout_end,
  ),
  _block: $ => layouted($, $._statement),
}