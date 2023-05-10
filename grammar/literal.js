const { sep } = require('./util')

module.exports = {
  _literal: $ => choice(
    $.literal_text,
    $.literal_nat,
    $.literal_int,
    $.literal_float,
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
  literal_nat: $ => /[0-9]|[1-9][0-9]{1,14}|1000000000000000|10000000000000000|100000000000000000|1000000000000000000|1[0-8]000000000000000000|18[0-4]00000000000000000|184[0-4]0000000000000000|1844[0-6]000000000000000|18446[0-7]00000000000000|184467[0-4]0000000000000|1844674[0-4]000000000000|184467440[0-7]0000000000|1844674407[0-3]000000000|18446744073[0-7]00000000|1844674407370000000[0-9]|18446744073709[0-5]00000|184467440737095[0-5]0000|1844674407370955[0-2]000/,
  
  // Range: [-9223372036854775808, 9223372036854775807]
  literal_int: $ => /(-9223372036854775808)|([+-]([0-9]|[1-9][0-9]{1,14}|1000000000000000|10000000000000000|100000000000000000|[1-9]000000000000000000|9[0-2]00000000000000000|92[0-2]0000000000000000|922[0-3]000000000000000|9223[0-3]00000000000000|92233[0-7]0000000000000|922337[0-2]000000000000|92233720[0-3]0000000000|922337203[0-6]000000000|9223372036[0-8]00000000|92233720368[0-5]0000000|922337203685[0-4]000000|9223372036854[0-7]00000|92233720368547[0-7]0000|922337203685477[0-5]000|922337203685477[56]000))/,
  
  literal_float: $ => /[+-]?[0-9]*\.[0-9]+/,
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
  func_name: $ => $._regular_identifier,
  func_param: $ => $._regular_identifier,
  // literal_function: $ => prec.left(seq(
  //   $.func_name, // func name
  //   repeat($.func_param), // func args
  //   $.type_arrow, 
  //   $._expression // func body
  // )),
  
  
  literal_tuple: $ => seq('(', sep(',', $._expression), ')'),
  term: $ => $._regular_identifier,
  literal_termlink: $ => seq($.kw_termlink, $.term),
  literal_typelink: $ => seq($.kw_typelink, $.type),
}