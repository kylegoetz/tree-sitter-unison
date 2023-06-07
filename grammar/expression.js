const literals = require('./literal')
const { KEYWORD } = require('./precedences')

module.exports = {
  _expression: $ => prec.left(choice(
    $.literal_function,
    $.exp_let,
    $.exp_if,
    $.function_application,
    $._literal,
    prec(-1, $._identifier),
    // $.operator_as_para meter,

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
  use_clause: $ => prec.right(seq($.use, $.namespace, repeat($._identifier))),
}