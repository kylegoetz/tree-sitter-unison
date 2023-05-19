const { KEYWORD } = require('./precedences')

module.exports = {
  expression: $ => $._expression,
  
  kw_if: $ => prec(KEYWORD, 'if'),
  kw_then: $ => prec(KEYWORD, 'then'),
  kw_else: $ => prec(KEYWORD, 'else'),
  
  exp_if: $ => prec.left(seq(
    $.kw_if,
    field('if_block', choice($._expression, $._block)),
    $.kw_then,
    field('then_block', choice($._expression, $._block)),
    $.kw_else,
    field('else_block', choice($._expression, $._block)),
  )),
  
  // exp_if: $ => prec.left(seq(
  //   $.kw_if,
  //   // $._expression,
  //   choice($._expression, layouted($, $._block)),
  //   // choice(layouted($, $._block), $._expression),
  //   $.kw_then,
  //   $._expression,
  //   // choice($._expression, layouted($, $._block)),
  //   // choice(layouted($, $._block), $._expression),
  //   $.kw_else,
  //   // choice($._expression, layouted($, $._block)),
  // )),
  
  operator_expression: $ => seq(
    $._expression,
    $.operator,
    $._expression
  ),
  
  // myFun p1 p2 p3
  function_name: $ => $._regular_identifier,
  function_param: $ => $._expression,
  _function_application: $ => prec.right('_function_application', seq(
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
    
  stmt: $ => $._statement,
  // exp: $ => $._expression,
  empty: $ => '',
  _block: $ => prec.left(seq(
    repeat($._statement),
    $._expression,
    // $.empty,
    // optional($.fold),
  )),
}