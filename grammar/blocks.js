module.exports = {
  expression: $ => $._expression,
  
  
  operator_expression: $ => seq(
    $._expression,
    $.operator,
    $._expression
  ),
  
  // myFun p1 p2 p3
  function_name: $ => $._regular_identifier,
  function_param: $ => $._expression,
  _function_application: $ => prec.left(seq(
    alias($._regular_identifier, $.function_name), 
    repeat1(alias(prec.right($._expression), $.function_param))
  )),
  
  // p1 + p2
  _infix_op_application: $ => prec.left(seq($._expression, $.operator, $._expression)),
  
  // (+) p1 p2
  _prefix_op_application: $ => prec.left(seq('(', $.operator, ')', $._expression, $._expression)),
  
  function_application: $ => choice(
    $._function_application,
    $._infix_op_application,
    $._prefix_op_application,
  ),
  _block: $ => seq(
    repeat($._statement),
    $._expression,
  ),
}