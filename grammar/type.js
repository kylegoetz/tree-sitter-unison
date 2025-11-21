const { sep } = require('./util')
const regex = require('./regex')

module.exports = {
  type_declaration: $ => prec.right(seq(
    $._type_lhs,
    $.kw_equals,
    optional($._type_rhs),
  )),

  type_name: $ => $._identifier,
  type_argument: $ => token(regex.lowercase_varid), // TODO lowercase only?

  type_constructor: $ => prec.right(seq(
    $.type_name,
    repeat($.type_argument),
  )),

  _parenthetical_data_constructor: $ => seq(
    '(',
    choice($.list_constructor, $.tuple_constructor, $._standard_constructor),
    ')',
  ),

  list_constructor: $ => seq(
    '[',
    $._data_constructor,
    ']'
  ),
  tuple_constructor: $ => seq(
    '(',
    sep(',', $._data_constructor),
    ')'
  ),
  _standard_constructor: $ => prec.right(seq(
    $.type_name,
    repeat(choice($.type_argument, $.list_constructor, $.tuple_constructor, alias($._parenthetical_data_constructor, $._data_constructor))),
  )),

  /**
   * Need to account for:
   * Foo
   * Foo a
   * Foo Nat
   * Foo (Option Nat)
   * Foo (Option a)
   * Foo Bar (Option a)
   * [Int] <- list
   * (Int, Nat, Float) <- tuple
   * { x : Nat, y : Nat } <- record
   */
  _data_constructor: $ => prec.right(choice(
    $.list_constructor,
    $.tuple_constructor,
    $._standard_constructor,
    $.record,
  )),


  _type_lhs: $ => seq(
    optional(choice($.structural, $.unique)),
    $.type_kw,
    $.type_constructor
  ),

  _type_rhs: $ => sep1($.pipe, choice($._value_type, $.record)),

  // Record type
  record: $ => seq('{', $._record_fields_block, '}',),
  record_field: $ => seq(alias($.wordy_id, $.field_name), ':', field('type', $._value_type)),
  _record_fields_inline: $ => seq(sep1(',', $.record_field), optional(',')),
  _record_fields_block: $ => choice($._record_fields_inline, seq(
    $._layout_start,
    sep($._layout_semicolon, $._record_fields_inline),
    $._layout_end,
  )),
}
