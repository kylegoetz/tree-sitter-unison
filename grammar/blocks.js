module.exports = {
  kw_let: _ => 'let',
  expression: $ => $._expression,
  
  exp_let: $ => seq('let', layouted($, $._block)),
  
  // exp op exp
  functional_expression: $ => seq(
    $._expression, 
    $.operator, 
    $._expression
  ),
  
  _block: $ => seq(
    repeat($._statement),
    $._expression,
  ),
}