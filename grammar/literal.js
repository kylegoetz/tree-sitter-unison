const { sep } = require('./util')

module.exports = {
  _literal: $ => choice(
    $.literal_text,
    $.nat,
    $.int,
    $.float,
    $.literal_char,
    $.literal_boolean,
    $.literal_byte,
    $.literal_hash,
    $.literal_list,
    $.literal_function,
    $.literal_tuple,
    $.literal_termlink,
    $.literal_typelink,
  ),
  literal_text: $ => /".+?"/,
  
  // Range: [0, 18446744073709551615]
  
  // Range: [-9223372036854775808, 9223372036854775807]
  
  literal_char: $ => /\?./,
  literal_boolean: $ => choice("true", "false"),
  literal_byte: $ => /0xs[0-9abcdef]+/,
  _term_definition_hash: $ => /#[0-9a-v]+/,
  _cyclically_recursive_hash: $ => /#[0-9a-v]+\.[0-9a-v]+/,
  _data_constructor_hash: $ => /#[0-9a-v]+#[0-9a-v]+/,
  _cyclically_recursive_data_constructor_hash: $ => seq($._cyclically_recursive_hash, token.immediate(/#[0-9a-v]+/)),
  _builtin_reference: $ => seq(/##/, $._regular_identifier),
  literal_hash: $ => choice(
    $._term_definition_hash,
    $._cyclically_recursive_hash,
    $._data_constructor_hash,
    $._cyclically_recursive_data_constructor_hash,
    $._builtin_reference,
  ),
  literal_list: $ => seq('[', sep(',', $._expression), ']'),
  
  // myFn p1 p2 p3 -> exp
  func_name: $ => prec.left($._regular_identifier),
  func_param: $ => prec.left($._regular_identifier),
  literal_function: $ => prec.right(seq(
    alias($._regular_identifier, $.func_name), // func name
    // prec.left(repeat(prec.left(alias($._regular_identifier, $.func_param)))), // func args
    $.type_arrow, 
    $._expression // func body
  )),
  
  
  literal_tuple: $ => seq('(', sep(',', $._expression), ')'),
  term: $ => $._regular_identifier,
  literal_termlink: $ => seq($.kw_termlink, $.term),
  literal_typelink: $ => seq($.kw_typelink, $.type),
}