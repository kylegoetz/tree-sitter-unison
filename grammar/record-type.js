const { sep } = require('./util')

module.exports = {
  record: $ => seq('{',$._record_fields_block,'}',),
  record_field: $ => seq(field('name', $.wordy_id), ':', field('type', $._value_type)),
  _record_fields_inline: $ => seq(sep1(',', $.record_field), optional(',')),
  _record_fields_block: $ => choice($._record_fields_inline, seq(
      $._layout_start,
      sep($._layout_semicolon, $._record_fields_inline),
      // optional($._layout_semicolon),
      $._layout_end,
  )),
}