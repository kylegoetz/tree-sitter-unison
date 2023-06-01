const literals = require('./literal')
const { KEYWORD } = require('./precedences')

module.exports = {
  _expression: $ => prec.left(choice(
    $.exp_let,
    $.exp_if,
    $._literal,
    $.identifier,
    // $.operator_as_parameter,
    $.function_application,
    $.parenthetical_exp,
    // $.regular_identifier,
  )),
  
  operator_as_parameter: $ => seq('(',$.operator, ')'),
  parenthetical_exp: $ => prec(-10, seq(
    '(',
    $._expression,
    ')'
  )),
  
  use: $ => prec(KEYWORD, 'use'),
  use_clause: $ => prec.right(seq($.use, $.namespace, repeat($.identifier))),
}