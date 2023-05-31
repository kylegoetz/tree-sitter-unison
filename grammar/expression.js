const literals = require('./literal')
const _let = require('./let')
const { KEYWORD } = require('./precedences')

module.exports = {
  _expression: $ => prec.left(choice(
    $.exp_let,
    $.exp_if,
    $._literal,
    $.identifier,
    // $.operator_as_parameter,
    // 'y',
    // 'z',
    $.function_application,
    $.parenthetical_exp,
    // $._infix_op_application,
    // $.regular_identifier,
  )),
  // ...literals,
  ..._let,
  
  operator_as_parameter: $ => seq('(',$.operator, ')'),
  parenthetical_exp: $ => prec(-10, seq(
    '(',
    $._expression,
    ')'
  )),
  
  use: $ => prec(KEYWORD, 'use'),
  use_clause: $ => prec.right(seq($.use, $.namespace, repeat($.identifier))),
}