const sep = (sep, rule) => optional(seq(rule, repeat(seq(sep, rule))))

sep1 = (sep, rule) => seq(rule, repeat(seq(sep, rule)))

sep2 = (sep, rule) => seq(rule, repeat1(seq(sep, rule)))

braces = (...rule) => seq('{', ...rule, '}')

parens = (...rule) => seq('(', ...rule, ')')

paren$ = ($, ...rule) => seq('(', $._layout_start, ...rule, $._layout_end, ')')

/**
 * Wrap a repeated rule with semicolon rules.
 * Between any two occurences of a rule in a layout, if no explicit semicolon is encountered, delegate to the scanner
 * to determine heuristically where a statement or decl may end.
 * After the last repetition, the semicolon is optional.
 * The dynamic precision is needed because of some irregularities with standalone deriving decls and data deriving
 * clauses.
 */
terminated = ($, rule) =>
  prec.right(
    seq(
      prec.right(sep1(prec.right(choice(';', $._layout_semicolon)), rule)),
      optional(choice(';', $._layout_semicolon)),
    ),
  )

layouted_braces = rule => braces(sep(';', rule), optional(';'))

open_block_with = ($, opener) =>
  seq(
    opener,
    $._layout_start,
    optional(terminated($, $.use_clause)),
    terminated($, $._statement),
    optional($._layout_end),
  )

openBlockWith = ($, opener) => seq(opener, $._layout_start)

layoutBlock = ($, opener) =>
  seq(
    opener,
    $._layout_start,
    // optional(terminated($, $.use_clause)),
    // repeat($.use_clause),
    // optional($._layout_semicolon),
    sep1(
      $._layout_semicolon,
      choice($._statement, terminated($, $.use_clause)),
    ),
    // optional($._layout_semicolon),
    // terminated($, $._statement),
    $._layout_end,
  )

const block = ($, opener) =>
  seq(
    opener,
    $._layout_start,
    optional(seq(sep1($._layout_semicolon, $.use_clause), $._layout_semicolon)),
    // repeat(choice('s = 0', 's > 0')),
    // terminated($, $._statement),
    sep1($._layout_semicolon, $._statement),
    $._layout_end,
    // sep1(
    //   alias($._layout_semicolon, $.TERMS_STATEMENT_SEMI),
    //   $._statement,
    // ),
    // optional($._layout_semicolon),
    // optional($._layout_end),
  )

// open_block_with = ($, opener, start_type) => seq(
//   // start_type ?? $._layout_start,//$._layout_start,
//   terminated($, opener),
//   $._layout_start,
//   optional(terminated($, $._statement)),
//   // optional(terminated($, rule)),
//   $._layout_end,
// )

/**
 * Wrap a repeated rule in a layout.
 * This is used for `where`, `let`, `of` and `do`, and the toplevel module.
 * The `_layout_start` rule is picked up by the scanner and causes the current column (or indent, for newline
 * layouts) to be recorded.
 * When a `_layout_end` or `_layout_semicolon` is encountered by the scanner, the recorded indent is compared to the
 * current one to make a decision.
 * If explicit braces are provided, the scanner isn't relevant.
 */
layouted = ($, rule) =>
  choice(
    // layouted_braces(rule),
    seq($._layout_start, terminated($, rule), $._layout_end),
    rule,
  )

// guardLayouted = seq()

layouted_without_end = ($, rule) =>
  choice(
    layouted_braces(rule),
    seq($._layout_start, optional(terminated($, rule))),
  )

// layout_block = ($, keyword) => seq(open_block_with($, keyword));

module.exports = {
  block,
  layoutBlock,
  layouted,
  layouted_without_end,
  open_block_with,
  openBlockWith,
  parens,
  paren$,
  sep,
  sep1,
  sep2,
  terminated,
}
