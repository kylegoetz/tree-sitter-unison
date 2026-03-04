const { parenthesized, sep, sep1 } = require('./util')
const regex = require('./regex')

module.exports = {
  _literal: $ =>
    choice(
      $.literal_text,
      $.nat,
      $.int,
      $.float,
      $.literal_char,
      $.literal_boolean,
      $.literal_byte,
      $.literal_hex,
      $.literal_list,
      $.literal_function,
      $.tuple_or_parenthesized,
      $.literal_termlink,
      $.literal_typelink,
      $.unit,
    ),
  unit: $ => '()',

  nat: $ => /[0-9]+/,
  int: $ => /[+-][0-9]+/,
  float: $ => /[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?/,
  literal_char: $ => choice(/\?./u, /\?\\[0abfnrtvs\'"]/),
  literal_boolean: $ => choice('true', 'false'),
  literal_byte: $ => /0xs[0-9a-fA-F]+/,
  literal_hex: $ => /0x[0-9a-fA-F]+/,
  tuple_or_parenthesized: $ => prec.dynamic(3, parenthesized($, $._term)),
  literal_termlink: $ => seq($.kw_termlink, $._hash_qualified),
  literal_typelink: $ => seq($.kw_typelink, $._hash_qualified),
}
