const literals = require('./literal')
const _let = require('./let')

module.exports = {
  _expression: $ => prec.left(choice(
    $.exp_let,
    // prec('exp_if', $.exp_if),
    $.function_application,
    // $._infix_op_application,
    $._literal,
    $.regular_identifier,
  )),
  // ...literals,
  ..._let,
  
  
  namespace: $ => $._regular_identifier,
  use_clause: $ => 'TODO',
  // use_clause: $ => seq('use', $.namespace, repeat($.regular_identifier)),
}