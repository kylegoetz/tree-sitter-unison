const { layouted, sep, sep1, openBlockWith } = require('./util')

module.exports = {


  // _pattern_matching: $ => seq(
  //   choice(
  //     seq($.match, field('scrutinee', $._expression), $.with),
  //     $.cases),
  //   layouted($, $.pattern)),

  // _pattern_matching: $ => seq(
    // choice(alias($._match_with, $.match_with), $.cases),
    // layouted($, $.pattern),
  // ),
  _pattern_matching: $ => choice($._match_with, $._lam_case),

  _match_with: $ => prec.right(seq(
    openBlockWith($, $.match),
    field('scrutinee', $._expression),
    optional($._layout_end),
    openBlockWith($, $.with),
    $._match_cases,
    optional($._layout_end),
  )),

  _lam_case: $ => prec.right(seq(
    openBlockWith($, $.cases),
    $._match_cases,
    optional($._layout_end),
  )),

  _match_cases: $ => prec.right(sep1($._layout_semicolon, $.pattern)),

  /**
   * Pattern examples:
   * 5 -> "foo"
   * foo | foo == 1 -> "one"
         | otherwise -> "not one"
   */
  // pattern: $ => seq($._pattern_lhs, $._pattern_rhs),
  pattern: $ => seq($._pattern_root, $._pattern_rhs),

  /**
   * Without typechecking, we cannot know whether a single wordy_id is an identifier or constructor pattern with 0-arity, so
   * we only have a constructor pattern here as an option, no wordy_id pattern.
   */
  _pattern_lhs: $ => prec.right(choice(
    alias('_', $.blank_pattern), // unbound
    $._literal_pattern, // literal
    $.as_pattern, // varOrAs
    $.constructor_or_variable_pattern, // nullaryCtor, varOrAs
    $._list_pattern, // seq literal
    $.tuple_pattern, //parenthesizedOrTuplePattern
    $.ability_pattern, // effect
  )),

  /**
   * "A pattern's RHS is either one or more guards, or a single unguarded block"
   * (from Unison's TermParser.hs)
   */
  _pattern_rhs: $ => choice(
    open_block_with($, $.arrow_symbol),
    layouted($, $.guarded_block),
    // seq($._layout_start, layouted($, $.guarded_block), $._layout_end),
  ),

  _literal_pattern: $ => choice( // Observe Float is not allowed.
    $.literal_boolean,
    $.nat,
    $.int,
    $.literal_char,
    $.literal_text,
  ),
  as_pattern: $ => prec.left(seq(
    alias($.wordy_id, $.regular_identifier),
    $.as,
    $._pattern_lhs)),

  constructor_or_variable_pattern: $ => prec.right('constructor_or_variable_pattern', seq(
    alias($._hash_qualified, $.hq),
    repeat(prec.left($._pattern_lhs)),
  )),

  _list_pattern: $ => choice(
    $.head_tail_list_pattern,
    $.init_last_tail_pattern,
    $.literal_list_pattern,
    $.concat_list_pattern,
  ),
  tuple_pattern: $ => seq('(', sep(',', $._pattern_lhs), ')'),
  ability_pattern: $ => choice(
    seq('{', $._pattern_lhs, '}'),
  ),

  /**
   * A list pattern can be one of the following:
   * head [List.]+: tail
   * init [List.]:+ last
   * [p_1, p2, ..., p_n] where p_i is a PATTERN
   * part1 [List.]++ part2 where one of part1 and part2 must be a list of known length, e.g.
   *   [x, y] ++ rest
   *   start ++ [x, y]
   *   BUT NOT a ++ b
   *   TODO: pare this pattern down to something like choice(seq('head', '++', LIST_LITERAL), ...) instead of seq(choice($.wordy_id, $.list_literal, '++', ...))
   */
  head_tail_list_pattern: $ => prec.right(seq($._pattern_lhs, '+:' /*(List\.)?\+:*/, $._pattern_lhs)),
  init_last_tail_pattern: $ => prec.right(seq($._pattern_lhs, /(List\.)?:\+/, $._pattern_lhs)),
  literal_list_pattern: $ => seq('[', sep(',', $._pattern_lhs), ']'),
  concat_list_pattern: $ => prec.right(seq($._pattern_lhs, /(List\.)?\+\+/, $._pattern_lhs)),
  /**
   * A guard can be one of the following:
   * - | BOOL_EXPR (OPEN) -> BLOCK (CLOSE)
   * - | OTHERWISE (OPEN) -> BLOCK (CLOSE)
   */
  // guard: $ => prec.right(seq(
  //   $.pipe,
  //   choice($._infix_op_application, $.otherwise),
  //   open_block_with($, $.arrow_symbol, $._start_before_arrow))),
  guard: $ => choice($._expression, $.otherwise),

  guarded_block: $ => seq($.pipe, $.guard, open_block_with($, $.arrow_symbol)),

  _pattern_root: $ => sep1($.pattern_infix_app, $._pattern_candidates),
  pattern_infix_app: $ => choice('++', '+:', ':+'),
  _pattern_constructor: $ => seq($.ctor, 'x', /* prec.right(repeat1($._pattern_leaf))*/),
  ctor: $ => alias($._hq_qualified_prefix_term, $.ctor_name),
  _pattern_candidates: $ => choice(
    // 'x',
    $._pattern_constructor,
    // $._pattern_leaf,
  ),
  varOrAs: $ => seq(alias($.wordy_id, $.regular_identifier), optional(seq(alias('@', $.at_token), $._pattern_leaf))),
  // wordy_pattern_name: $ => alias($.wordy_id, $.regular_identifier),
  unbound: $ => '_',
  seqLiteral: $ => 'TODO',
  parenthesizedOrTuplePattern: $ => 'TODO',
  effect: $ => seq(
    openBlockWith($,'{'),
    'TODO'
  ),
  _pattern_leaf: $ => choice(
    $._literal_pattern,
    // 'x',
    $.varOrAs,
    $.unbound,
    $.seqLiteral,
    $.parenthesizedOrTuplePattern,
    $.effect,
  )



}
