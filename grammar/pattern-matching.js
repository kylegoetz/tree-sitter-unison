const { sep, sep1, layoutBlock, openBlockWith } = require('./util')
const { lowercase_varid } = require('./regex')

module.exports = {
  _pattern_matching: $ =>
    choice(
      alias($._match_with, $.match_expression),
      alias($._lam_case, $.match_expression_lambda),
    ),

  _match_with: $ =>
    prec.right(
      seq(
        openBlockWith($, $.match),
        field('scrutinee', $._term),
        optional($._layout_end),
        $.with,
        optional(seq($._layout_start, $._match_cases)),
        optional($._layout_end),
      ),
    ),

  _lam_case: $ =>
    prec.right(
      seq($.cases, $._layout_start, $._match_cases, optional($._layout_end)),
    ),

  _match_cases: $ => prec.right(sep1($._layout_semicolon, $.pattern_case)),

  /**
   * Case examples:
   * 5 -> "foo"
   * foo | foo == 1 -> "one"
         | otherwise -> "not one"
   */
  pattern_case: $ => seq($._pattern_root, prec.right($._pattern_rhs)),
  /**
   * "A case's RHS is either one or more guards, or a single unguarded block"
   * (from Unison's TermParser.hs)
   */
  _pattern_rhs: $ =>
    prec.right(
      choice(
        seq(
          $._guard_layout_start,
          sep1($._layout_semicolon, $.guarded_block),
          $._layout_end,
        ),
        layoutBlock($, $.arrow_symbol),
      ),
    ),

  _literal_pattern: $ =>
    choice($.literal_boolean, $.nat, $.int, $.literal_char, $.literal_text),

  guard: $ => choice($._infix_app_or_boolean_op, $.otherwise),

  guarded_block: $ =>
    prec.right(seq($.pipe, $.guard, layoutBlock($, $.arrow_symbol))),

  _pattern_infix_app: $ =>
    choice(alias('++', $.concat), alias('+:', $.cons), alias(':+', $.snoc)),
  _pattern_root: $ =>
    sep1(
      $._pattern_infix_app,
      sep1(
        alias(',', $.comma),
        alias(choice($._pattern_leaf$, $._hqNamey$), $.pattern),
      ),
    ),
  _hqNamey$: $ => seq($._hqNamey, repeat($._pattern_leaf)),
  _hqNamey: $ =>
    seq(
      $.var_or_nullary_ctor,
      optional(seq(alias('@', $.at_token), $._pattern_leaf)),
    ),
  _pattern_leaf: $ => choice($._hqNamey, $._pattern_leaf$),
  _pattern_leaf$: $ =>
    prec(
      2,
      choice(
        // $.var_or_as,
        $.var_or_nullary_ctor,
        $._literal_pattern,
        alias('_', $.blank_pattern),
        $.literal_list_pattern,
        $.parenthesized_or_tuple_pattern,
        $.effect_pattern,
      ),
    ),

  // Note: Unfortunately the SEMI is disabled here because leaving it in creates a parsing error where
  literal_list_pattern: $ =>
    choice(
      seq(
        '[',
        sep(alias(',', $.comma), $._pattern_root),
        // $._layout_end,
        ']',
      ),
    ),
  parenthesized_or_tuple_pattern: $ =>
    seq(
      openBlockWith($, alias('(', $.open_parens)),
      sep(alias(',', $.comma), choice($._pattern_root)),
      $._layout_end,
      alias(')', $.close_parens),
    ),

  effect_pure: $ => $._pattern_root,
  effect_bind: $ =>
    seq(repeat($._pattern_leaf), alias('->', $.effect_arrow), $._pattern_root),

  effect_pattern: $ =>
    seq(
      openBlockWith($, '{'),
      choice($.effect_pure, $.effect_bind),
      $._layout_end,
      '}',
    ),
}
