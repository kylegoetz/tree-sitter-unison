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
  _type_lhs: $ => seq(
    optional(choice($.structural, $.unique)),
    $.type_kw,
    $.type_constructor
  ),

  _type_rhs: $ => sep1($.pipe, choice($._value_type, $.record)),

  // Record type
  record: $ => seq(
    '{',
    sep(',', $.record_field),
    optional(','),
    '}',
  ),
  record_field: $ => seq(alias($.wordy_id, $.field_name), ':', field('type', $._value_type)),
}
