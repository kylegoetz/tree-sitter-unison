const { sep } = require('./util')

module.exports = {
  _expression: $ => prec('_expression', choice(
    $.literal_boolean,
    $.literal_byte,
    $.literal_nat,
    $.literal_int,
    $.literal_float,
    $.literal_text,
    $.literal_char,
    $.literal_list,
    $.literal_function,
    $.literal_tuple,
    // $.literal_termlink,
    $.literal_typelink,
    $.regular_identifier,
    // $.block
  )),
  literal_text: $ => /".+?"/,
  literal_nat: $ => /[0-9]{1,20}/,
  literal_int: $ => /[+-][0-9]+/,
  literal_float: $ => /[+-]?[0-9]*\.[0-9]+/,
  literal_char: $ => /\?./,
  literal_boolean: $ => choice("true", "false"),
  literal_byte: $ => /0xs[0-9abcdef]+/,
  // literal_hash
  literal_list: $ => seq('[', sep(',', $._expression), ']'),
  literal_function: $ => prec('literal_function', seq(repeat1($.regular_identifier), $.type_arrow, $._expression)),
  literal_tuple: $ => seq('(', sep(',', $._expression), ')'),
  // literal_termlink: $ => seq($.kw_termlink, $.term),
  literal_typelink: $ => seq($.kw_typelink, $.type),
  
  namespace: $ => $._regular_identifier,
  use_clause: $ => seq('use', $.namespace, repeat($.regular_identifier)),
  
  statement: $ => choice(
    $.term_definition,
    $._expression,
    $.use_clause
  ),
  
  // block: $ => seq(
    // repeat($.statement),
    // $._expression
  // )
  
  
}