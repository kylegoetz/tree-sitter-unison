const {
  sep,
  sep1,
} = require('./util')
const regex = require('./regex')

module.exports = {
  type_declaration: $ => prec.right(seq(
    $._type_lhs,
    choice(
      seq('=', optional($._type_rhs)),
      $.gadt,
    ),
  )),

  type_name: $ => $._identifier,
  type_argument: $ => token(regex.lowercase_varid), // TODO lowercase only?

  type_constructor: $ => prec.right(seq(
    $.type_name,
    repeat($.type_argument),
  )),
  _type_lhs: $ => seq(
    optional(choice('structural', 'unique')),
    'type',
    $.type_constructor
  ),

  _type_rhs: $ => sep1('|', choice($._value_type, $.record)),

  // Record type
  record: $ => seq(
    '{',
    sep(',', $.record_field),
    optional(','),
    '}',
  ),
  record_field: $ => seq(alias($.wordy_id, $.field_name), ':', field('type', $._value_type)),

  gadt: $ => seq(
    'where',
    $._layout_start,
    sep($._layout_semicolon, $.gadt_constructor),
    $._layout_end,
  ),

  _gadt_type: $ => choice($._effect, $._type2a),

  gadt_constructor: $ => seq(
    alias($._prefix_definition_name, $.data_constructor),
    ':',
    optional($.forall),
    repeat(seq(alias($._gadt_type, $.constructor_argument), '->')),
    alias($._gadt_type, $.constructor_return_type),
  ),
}
