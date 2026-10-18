const { parenthesized } = require('./util')

module.exports = {
  unit: $ => '()',

  nat: $ => /[0-9]+/,
  int: $ => /[+-][0-9]+/,
  float: $ => /[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?/,
  literal_char: $ => choice(/\?./u, /\?\\[0abfnrtvs\'"\\]/, /\?\r?\n/),
  literal_boolean: $ => choice('true', 'false'),
  literal_byte: $ => /0xs[0-9a-fA-F]+/,
  literal_hex: $ => /0x[0-9a-fA-F]+/,
  tuple_or_parenthesized: $ => prec.dynamic(3, parenthesized($, $._term)),
  literal_termlink: $ => seq($.kw_termlink, $._hash_qualified),
  literal_typelink: $ => seq($.kw_typelink, $._hash_qualified),
}
