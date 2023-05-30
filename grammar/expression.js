const literals = require('./literal')
const _let = require('./let')

module.exports = {
  _expression: $ => prec.left(choice(
    $.exp_let,
    $.exp_if,
    $._literal,
    $.identifier,
    $.function_application,
    $.parenthetical_exp,
    // $._infix_op_application,
    // $.regular_identifier,
  )),
  // ...literals,
  ..._let,
  
  parenthetical_exp: $ => prec(-10, seq(
    '(',
    $._expression,
    ')'
  )),
  
  
  // use_clause: $ => seq('use', $.namespace, repeat($.regular_identifier)),
}