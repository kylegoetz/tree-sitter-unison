const { layouted, sep } = require('./util')

module.exports = {
  
  _pattern_matching: $ => seq(
    choice(
      seq($.match, field('scrutinee', $._expression), $.with),
      $.cases),
    layouted($, $.pattern)),
  
  _literal_pattern: $ => choice( // Observe Float is not allowed.
    $.literal_boolean,
    $.nat,
    $.int,
    $.literal_char,
    $.literal_text,
  ),
  as_pattern: $ => prec.left(seq($.wordy_id, $.as, $._pattern_lhs)),
  blank_pattern: $ => '_',
  
  constructor_or_variable_pattern: $ => prec.right(seq(
    prec(2, $._identifier),
    // $.wordy_id,
    // $.wordy_id,
    // sep(' ', $.wordy_id),
    optional(repeat1(prec.right(1, choice($.wordy_id, $._pattern_lhs)))), 
    // $.wordy_id,
    // $.wordy_id,
    // 'x y', 
    // sep(' ', $.wordy_id),
    // repeat(prec.left($._pattern_lhs)),
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
  head_tail_list_pattern: $ => prec.left(seq($._pattern_lhs, /(List\.)?\+:/, $._pattern_lhs)),
  init_last_tail_pattern: $ => seq($._pattern_lhs, /(List\.)?:\+/, $._pattern_rhs),
  literal_list_pattern: $ => seq('[', sep(',', $._pattern_lhs), ']'),
  concat_list_pattern: $ => seq($._pattern_lhs, /(List\.)?\+\+/, $._pattern_rhs),
  /**
   * A guard can be one of the following:
   * - | BOOL_EXPR -> BLOCK
   * - | OTHERWISE -> BLOCK
   */
  guard: $ => seq($.pipe, choice($._expression, $.otherwise), $.arrow_symbol, $._block),
  
  _unguarded_block: $ => seq($._layout_start, $.arrow_symbol, $._block, $._layout_end),
  // _unguarded_block: $ => prec(-1, layouted($, seq($.arrow_symbol, $._block)),
  
  /**
   * "A pattern's RHS is either one or more guards, or a single unguarded block"
   * (from Unison's TermParser.hs)
   */
  _pattern_rhs: $ => choice(
    $._unguarded_block,
    layouted($, $.guard),
  ),
  
  /**
   * Without typechecking, we cannot know whether a single wordy_id is an identifier or constructor pattern with 0-arity, so
   * we only have a constructor pattern here as an option, no wordy_id pattern.
   */
  _pattern_lhs: $ => choice(
    $.blank_pattern, // blank pattern
    $._literal_pattern,
    $.as_pattern,
    $.constructor_or_variable_pattern,
    $._list_pattern,
    prec(2, $.tuple_pattern),
    $.ability_pattern,
    prec(1, seq('(', $._pattern_lhs, ')')),
  ),
  
  /**
   * Pattern examples:
   * 5 -> "foo"
   * foo | foo == 1 -> "one"
         | otherwise -> "not one"
   */
  start: $ => $._layout_start,
  end: $ => $._layout_end,
  // pattern: $ => seq(
  //   field('lhs', $._pattern_lhs),
  //   field('rhs', choice(
  //     $._unguarded_block,
  //     // layouted($, $.guard),
  //   )),
  // ),
  
  pattern: $ => choice(
    seq($._pattern_lhs, $.arrow_symbol, $._block),
    // seq($._pattern_lhs, $._layout_start, '|', $._layout_end),
    // seq($._pattern_lhs, layouted($, $.guard)),
  ),
}