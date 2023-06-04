module.exports = {
  /**
   * Let:
   * let [block]
   * Examples:
   * x = let y = 5
   *         z = 1
   *         y + z
   */
  kw_let: _ => 'let',
  expression: $ => $._expression,
  exp_let: $ => seq(
    $.kw_let, 
    $._layout_start, 
    // $.term_definition,
    $.expression,
    $._layout_semicolon, 
    $.term_definition,
    $._layout_semicolon, 
    $._expression,
    $._layout_end
  ),
}