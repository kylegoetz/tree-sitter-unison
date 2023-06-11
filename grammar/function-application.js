module.exports = {
  _prefix_op: $ => seq('(', $.operator, ')'),
  _function_param: $ => choice(
    prec.left($._expression),
    $._prefix_op,
    // seq('(',$.operator,')'),
  ),
  
  _function_name: $ => choice(
    $._identifier, 
    $._prefix_op,
    // $._parenthesized_operator,
    // alias($._parenthesized_operator, $.operator),
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
  
  // p1 + p2
  _infix_op_application: $ => prec.right(seq(
    $._expression, 
    $.operator, 
    $._expression,
  )),
    
  function_application: $ => choice(
    // '(+) 5 2',
    
    $._prefix_function_application,
    $._infix_op_application,
  ),
}