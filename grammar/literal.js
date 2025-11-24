const { sep, sep1 } = require("./util");
const regex = require("./regex");

module.exports = {
  _literal: ($) =>
    choice(
      $.literal_text,
      $.nat,
      $.int,
      $.float,
      $.literal_char,
      $.literal_boolean,
      $.literal_byte,
      $.literal_hex,
      // $.literal_hash,
      $.literal_list,
      $.literal_function,
      $.tuple_or_parenthesized,
      $.literal_termlink,
      $.literal_typelink,
      $.unit,
    ),
  unit: ($) => "()",
  // literal_text: $ => /".+?"/,

  nat: ($) => /[0-9]+/,
  int: ($) => /[+-][0-9]+/,
  float: ($) => /[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?/,

  literal_text: (_) =>
    choice(
      // /"(?:\\"|.)*?"/, // <-- this fails for the one line if/else test by parsing a longer string than it should
      seq('"', repeat(choice(/[^\\"\n]/, /\\(\^)?./, /\\\n\s*\\/)), '"'),
      seq(
        '"""',
        repeat(choice('"', /[^\\"\n]/, /\\(\^)?./, /\\\n\s*\\/)),
        '"""',
      ),
    ),

  // Range: [0, 18446744073709551615]

  // Range: [-9223372036854775808, 9223372036854775807]

  literal_char: ($) => choice(
    /\?\\[0abfnrtvs\'"\\]/,
    /\?=./u,
    /\?[^\\=]/u,
  ),
  literal_boolean: ($) => choice("true", "false"),
  literal_byte: ($) => /0xs[0-9a-fA-F]+/,
  literal_hex: ($) => /0x[0-9a-fA-F]+/,
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
  // literal_list: ($) => seq("[", sep(",", $._expression), "]"),

  // myFn p1 p2 p3 -> exp
  // lambda_arrow: $ => prec(2, '->'),
  // func_name: ($) => prec.left(regex.varid),
  // func_param: ($) => prec.left(regex.varid),
  // literal_function: ($) =>
  //   prec(
  //     "literal_function",
  //     seq(
  //       field(
  //         "lhs",
  //         repeat1(
  //           prec.left(field("param", alias($.wordy_id, $.regular_identifier))),
  //         ),
  //       ),
  //       $.arrow_symbol,
  //       $._expression, // func body
  //     ),
  //   ),

  /*
  parenthesized_or_tuple_pattern: ($) =>
    seq(
      openBlockWith($, "("),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      sep1(",", $._pattern_root),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      $._layout_end,
      ")",
    ),
  */

  tuple_or_parenthesized: ($) => seq(openBlockWith($, '('), sep(',', $._term), $._layout_end, ')'),
  // seq("(", sep1(",", choice(/*alias("0: Int", $.tmp),*/ $._term)), ")"),
  // term: $ => $._regular_identifier,
  literal_termlink: ($) => seq($.kw_termlink, $._hash_qualified),
  literal_typelink: ($) => seq($.kw_typelink, $._hash_qualified),
};
