const

sep = (sep, rule) => optional(seq(rule, repeat(seq(sep, rule))))

sep1 = (sep, rule) => seq(rule, repeat(seq(sep, rule)))

sep2 = (sep, rule) => seq(rule, repeat1(seq(sep, rule)))

braces = (...rule) => seq('{', ...rule, '}')

parens = (...rule) => seq('(', ...rule, ')')

/**
  * Wrap a repeated rule with semicolon rules.
  * Between any two occurences of a rule in a layout, if no explicit semicolon is encountered, delegate to the scanner
  * to determine heuristically where a statement or decl may end.
  * After the last repetition, the semicolon is optional.
  * The dynamic precision is needed because of some irregularities with standalone deriving decls and data deriving
  * clauses.
  */
terminated = ($, rule) => seq(
  sep1(prec.dynamic(1, choice(';', $._layout_semicolon)), rule),
  optional(choice(';', $._layout_semicolon)),
)

layouted_braces = rule => braces(sep(';', rule), optional(';')),


open_block_with = ($, opener, start_type) => seq(
  start_type ?? $._layout_start,//$._layout_start,
  terminated($, opener),
  optional(terminated($, $._statement)),
  // optional(terminated($, rule)), 
  $._layout_end,
)

/**
  * Wrap a repeated rule in a layout.
  * This is used for `where`, `let`, `of` and `do`, and the toplevel module.
  * The `_layout_start` rule is picked up by the scanner and causes the current column (or indent, for newline
  * layouts) to be recorded.
  * When a `_layout_end` or `_layout_semicolon` is encountered by the scanner, the recorded indent is compared to the
  * current one to make a decision.
  * If explicit braces are provided, the scanner isn't relevant.
  */
layouted = ($, rule) => choice(
  layouted_braces(rule),
  seq($._layout_start, optional(terminated($, rule)), $._layout_end),
  rule,
)

layouted_without_end = ($, rule) => choice(
  layouted_braces(rule),
  seq($._layout_start, optional(terminated($, rule))),
)

module.exports = {
  layouted,
  layouted_without_end,
  open_block_with,
  parens,
  sep,
  sep1,
  sep2,
}