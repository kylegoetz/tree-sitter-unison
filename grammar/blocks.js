const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')

module.exports = {
  ...funcApp,
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
  
  
    
  stmt: $ => $._statement,
  
  _block: $ => prec.left(seq(
    repeat($.stmt),
    $._expression
  )),
}