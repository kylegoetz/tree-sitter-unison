const { parens } = require('./util')
const regex = require('./regex')

module.exports = {
  _prefix_op: $ => parens($._op),
  
  _function_name: $ => choice(
    $.wordy_id,
    seq($.path, alias(token.immediate(regex.varid), $.wordy_id)),
    $._prefix_op,
  ),
    
  _function_param: $ => choice(
    prec.left($._expression),
    $._prefix_op,
  ),
    
  partial_application: $ => $._prefix_function_application,
    
  /**
   * In Unison, all fns are unary. An n-ary function is modeled as either
   * 1. unary function that returns a partially-applied function; or
   * 2. unary function that takes a tuple as the argument.
   *
   * This function name can be a `varid` or `(symop)`.
   */
  _prefix_function_application: $ => choice(
    seq(field('function_name', $._function_name), $._function_param),
    seq($._prefix_function_application, $._function_param),
  ),
  
  _op: $ => choice($.operator, seq($.path, alias(token.immediate(regex.symboly_id), $.operator))),
  
  // p1 + p2
  _infix_op_application: $ => prec.right(seq(
    $._expression, 
    $._op,
    $._expression,
  )),
  
  function_application: $ => choice(
    $._prefix_function_application,
    $._infix_op_application,
  ),
}