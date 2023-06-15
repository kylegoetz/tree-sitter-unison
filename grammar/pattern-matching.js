const { layouted } = require('./util')

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
  as_pattern: $ => seq($.wordy_id, $.as, $._pattern_lhs),
  blank_pattern: $ => '_',
  constructor_pattern: $ => seq($._identifier, seq($._pattern_lhs)),
  list_pattern: $ => 'TODO list',
  tuple_pattern: $ => 'TODO tuple',
  ability_pattern: $ => choice(
    seq('{', $._pattern_lhs, '}'),
  ),
  
  /**
   * A guard can be one of the following:
   * - | BOOL_EXPR -> BLOCK
   * - | OTHERWISE -> BLOCK
   */
  guard: $ => seq($.pipe, choice($._expression, $.otherwise), $.arrow_symbol, $._block),
  
  _unguarded_block: $ => seq($._layout_start, $.arrow_symbol, $._block, $._layout_end),
  
  /**
   * "A pattern's RHS is either one or more guards, or a single unguarded block"
   * (from Unison's TermParser.hs)
   */
  _pattern_rhs: $ => choice(
    $._unguarded_block,
    layouted($, $.guard),
  ),
  
  _pattern_lhs: $ => choice(
    $.blank_pattern, // blank pattern
    $._literal_pattern,
    $.wordy_id,
    $.as_pattern,
    $.constructor_pattern,
    $.list_pattern,
    $.tuple_pattern,
    $.ability_pattern,
  ),
  
  /**
   * Pattern examples:
   * 5 -> "foo"
   * foo | foo == 1 -> "one"
         | otherwise -> "not one"
   */
  start: $ => $._layout_start,
  end: $ => $._layout_end,
  pattern: $ => seq(
    field('lhs', $._pattern_lhs),
    field('rhs', choice(
      $._unguarded_block,
      layouted($, $.guard),
    )),
  ),
}