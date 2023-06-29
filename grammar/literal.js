const { sep } = require('./util')
const regex = require('./regex')

module.exports = {
  _literal: $ => choice(
    $.literal_text,
    $.nat,
    $.int,
    $.float,
    $.literal_char,
    $.literal_boolean,
    $.literal_byte,
    // $.literal_hash,
    $.literal_list,
    $.literal_function,
    $.tuple_or_parenthesized,
    $.literal_termlink,
    $.literal_typelink,
    $.unit,
  ),
  unit: $ => '()',
  // literal_text: $ => /".+?"/,
  literal_text: _ => 
    choice(
      seq(
        '"',
        repeat(choice(
          /[^\\"\n]/,
          /\\(\^)?./,
          /\\\n\s*\\/,
        )),
        '"',
      ),
      seq(
        '"""', 
        repeat(choice(
          '"',
          /[^\\"\n]/,
          /\\(\^)?./,
          /\\\n\s*\\/,
        )),
        '"""'
      ),
    ),
  
  // Range: [0, 18446744073709551615]
  
  // Range: [-9223372036854775808, 9223372036854775807]
  
  literal_char: $ => choice(/\?./u, /\?\\[0abfnrtvs\'"]/),
  literal_boolean: $ => choice("true", "false"),
  literal_byte: $ => /0xs[0-9a-fA-F]+/,
  // _term_definition_hash: $ => /#[0-9a-v]+/,
  // _cyclically_recursive_hash: $ => /#[0-9a-v]+\.[0-9a-v]+/,
  // _data_constructor_hash: $ => /#[0-9a-v]+#[0-9a-v]+/,
  // _cyclically_recursive_data_constructor_hash: $ => seq($._cyclically_recursive_hash, token.immediate(/#[0-9a-v]+/)),
  // _builtin_reference: $ => seq(
    // /##/, 
    // optional(token.immediate(regex.path)),
    // choice(token.immediate(regex.varid), token.immediate(regex.symboly_id)),
  // ),
  // literal_hash: $ => choice(
    // $._term_definition_hash,
    // $._cyclically_recursive_hash,
    // $._data_constructor_hash,
    // $._cyclically_recursive_data_constructor_hash,
    // $._builtin_reference,
  // ),
  literal_list: $ => seq('[', sep(',', $._expression), ']'),
  
  // myFn p1 p2 p3 -> exp
  // lambda_arrow: $ => prec(2, '->'),
  func_name: $ => prec.left(regex.varid),
  func_param: $ => prec.left(regex.varid),
  literal_function: $ => prec('literal_function', seq(
    field('lhs', repeat1(prec.left(field('param', $.wordy_id)))),
    $.arrow_symbol, 
    $._expression // func body
  )),
  
  
  tuple_or_parenthesized: $ => seq('(', sep1(',', $._expression), ')'),
  // term: $ => $._regular_identifier,
  literal_termlink: $ => seq($.kw_termlink, $._hash_qualified),
  literal_typelink: $ => seq($.kw_typelink, $._hash_qualified),
}