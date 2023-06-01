module.exports = {
  function_param: $ => choice(
    prec.left($._expression),
    seq('(',$.operator,')'),
  ),
  
  _function_name: $ => choice(
    $.identifier,
    $.operator,
  ),
  
  /**
   * In Unison, all fns are unary. An n-ary function is modeled as either
   * 1. unary function that returns a partially-applied function; or
   * 2. unary function that takes a tuple as the argument.
   *
   * This function name can be a `varid` or `(symop)`.
   */
  _prefix_function_application: $ => choice(
    seq($._function_name, $.function_param),
    seq(field('partially_applied', $.function_application), $.function_param),
  ),
  
  // p1 + p2
  _infix_op_application: $ => prec.right(seq(
    $._expression, 
    $.operator, 
    $._expression,
  )),
    
  function_application: $ => prec(10, choice(
    $._prefix_function_application,
    $._infix_op_application,
  )),
}