const { sep } = require('./util')

module.exports = {
  type_declaration: $ => prec.right(seq(
    $._type_lhs,
    $.kw_equals,
    optional($._type_rhs),
  )),
  
  structural_kw: $ => 'structural',
  unique_kw: $ => 'unique',
  type_kw: $ => 'type',
  pipe: $ => '|',
  type_name: $ => $._varid,
  // type_argument: $ => $._lcase_varid,
  type_argument: $ => $._varid, // TODO lowercase only?
  
  type_constructor: $ => prec.right(seq(
    // /\.?([a-z]+\.)[a-z]+/,
    $.varid,
    // $.identifier,
    // optional(seq(sep1(token.immediate('.'), $._immediate_varid), $._immediate_dot)),
    // $.type_name,
    repeat($.type_argument),
  )),
  
  _parenthetical_data_constructor: $ => seq(
    '(',
    choice($.list_constructor, $.tuple_constructor, $._standard_constructor),
    ')',
  ),
  
  list_constructor: $ => seq(
    '[',
    $.data_constructor,
    ']'
  ),
  tuple_constructor: $ => seq(
    '(',
    sep(',', $.data_constructor),
    ')'
  ),
  // simple_constructor: $ => prec.left($.type_name),
  _standard_constructor: $ => prec.right(seq(
    $.type_name,
    repeat(choice($.type_argument, /*$.simple_constructor,*/ $.list_constructor, $.tuple_constructor, alias($._parenthetical_data_constructor, $.data_constructor)))
  )),
  
  data_constructor: $ => prec.right(choice(
    $.list_constructor,
    $.tuple_constructor,
    // $.simple_constructor,
    $._standard_constructor,
  )),
  
  /**
   * Need to account for:
   * Foo
   * Foo a
   * Foo Nat
   * Foo (Option Nat)
   * Foo (Option a)
   * Foo Bar (Option a)
   */
  // data_constructor: $ => prec.right(seq(
  //   $.type_name,
  //   // 'Text Nat (Set Genre)'
  //   repeat(choice($.type_argument, $.type_name, $._parenthetical_data_constructor)),
  // )),
  
  _type_lhs: $ => seq(
    choice($.structural_kw, $.unique_kw),
    $.type_kw,
    $.type_constructor
  ),
  
  _type_rhs: $ => sep1($.pipe, $.data_constructor),
}