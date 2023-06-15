const literals = require('./literal')
const { KEYWORD } = require('./precedences')

module.exports = {
  _expression: $ => prec.left(choice(
    // 'x + foo 8 102.0 +4',
    $.literal_function,
    $.exp_let,
    $.exp_if,
    $.handler,
    $.function_application,
    $._literal,
    prec(-1, $._identifier),
    $._pattern_matching,
    // $.operator_as_para meter,

    $.parenthetical_exp,
    $._boolean_exp,
  )),
  
  operator_as_parameter: $ => seq('(',$.operator, ')'),
  parenthetical_exp: $ => prec(-10, seq(
    '(',
    $._expression,
    optional(seq($.type_signature_colon, $._value_type)),
    ')'
  )),
  
  use: $ => prec(KEYWORD, 'use'),
  use_clause: $ => prec.right(seq($.use, $.namespace, repeat($._identifier))),
}