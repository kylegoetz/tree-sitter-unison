const literals = require('./literal')
const { KEYWORD } = require('./precedences')

module.exports = {
  _expression: $ => prec.right(choice(
    $.rewrite_block,
    $.literal_function,
    $.exp_let,
    $.exp_if,
    $.handler,
    $.function_application,
    $._literal,
    $._hash_qualified,
    $._pattern_matching,
    $.parenthetical_exp,
    $._boolean_exp,
    $.delay_block,
    $.bang,
    $.doc_block,
  )),
  
  operator_as_parameter: $ => seq('(',$.operator, ')'),
  parenthetical_exp: $ => prec(-10, seq(
    '(',
    $._expression,
    optional(seq($.type_signature_colon, $._value_type)),
    ')'
  )),
  
  use: $ => prec(KEYWORD, 'use'),
  // use_clause: $ => prec.right(seq($.use, $.namespace, repeat($._identifier))),
  use_clause: $ => prec.left(seq(
    alias('use', $.use),
    $.namespace ,
    repeat(choice($.wordy_id, alias($.symboly_id, $.operator))),
    $._layout_semicolon)),
}