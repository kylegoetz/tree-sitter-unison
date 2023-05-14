const { sep } = require('./util')

module.exports = {
  type_declaration: $ => prec.left(seq(
    $._type_lhs,
    $.kw_equals,
    $._type_rhs
  )),
  
  structural_kw: $ => 'structural',
  unique_kw: $ => 'unique',
  type_kw: $ => 'type',
  pipe: $ => '|',
  type_name: $ => $._regular_identifier,
  type_argument: $ => $._lowercase_regular_identifier,
  
  type_constructor: $ => prec.right(seq(
    $.type_name,
    repeat(choice($.type_argument, $.type_constructor)),
  )),
  
  data_constructor: $ => prec.right(seq(
    $.type_name,
    repeat(choice($.type_argument, $.data_constructor))
  )),
  
  _type_lhs: $ => seq(
    choice($.structural_kw, $.unique_kw),
    $.type_kw,
    $.type_constructor
  ),
  
  _type_rhs: $ => seq(
    sep1($.pipe, $.data_constructor),
  ),
}