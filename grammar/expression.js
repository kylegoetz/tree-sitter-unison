const literals = require('./literal')
const _let = require('./let')

module.exports = {
  _expression: $ => prec.left(choice(
    $.exp_let,
    $.exp_if,
    $.function_application,
    $.parenthetical_exp,
    // $._infix_op_application,
    $._literal,
    $.regular_identifier,
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