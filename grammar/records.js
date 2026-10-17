const { sep, sep1 } = require('./util')

module.exports = {
  _record_comma: $ => choice(',', $._comma),
  record_literal: $ => seq('{', $._record_start, sep($._record_comma, $.record_literal_field), $._layout_end, '}'),
  record_literal_field: $ =>
    seq(alias($.wordy_id, $.field_name), ':', field('value', $._term)),

  record_pattern: $ => seq('{', $._record_start, sep($._record_comma, $.record_pattern_field), $._layout_end, '}'),
  record_pattern_field: $ => seq(
    alias($.wordy_id, $.field_name),
    ':',
    sep1($._pattern_infix_app, alias(choice($._pattern_leaf$, $._hqNamey$), $.pattern)),
  ),

  record_access: $ => prec.left(3, seq(
    field('record', $._term_leaf),
    alias($._record_access_at, $.at_token),
    alias($.wordy_id, $.field_name),
    optional(token.immediate('.set')),
  )),
  record_accessor: $ => prec(1, seq(
    '(', $._record_start,
    alias('@', $.at_token),
    alias($.imm_wordy_id, $.field_name),
    optional(token.immediate('.set')),
    $._layout_end, ')',
  )),
  record_field_read: $ => seq(
    alias($._record_read_at, $.at_token),
    alias($.imm_wordy_id, $.field_name),
  ),
  record_update: $ => prec.left(3, seq(
    field('record', $._term_leaf),
    alias($._record_access_at, $.at_token),
    '{', $._record_update_start, sep($._record_comma, $.record_literal_field), $._layout_end, '}',
  )),
}
