const

sep = (sep, rule) => optional(seq(rule, repeat(seq(sep, rule))))

sep1 = (sep, rule) => seq(rule, repeat(seq(sep, rule)))

sep2 = (sep, rule) => seq(rule, repeat1(seq(sep, rule)))

terminated = ($, rule) => seq(
  sep1(prec.dynamic(1, choice(';', $._layout_semicolon)), rule),
  optional(choice(';', $._layout_semicolon)),
)

layouted = ($, rule) => seq(
  $._layout_start,
  optional(terminated($, rule)),
  $._layout_end,
)

module.exports = {
  layouted,
  sep,
  sep1,
  sep2,
}