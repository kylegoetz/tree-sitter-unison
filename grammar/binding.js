module.exports = {
  /**
   * Destructuring binding
   */
  destructuring_bind: $ => seq(
    // $._pattern_lhs,
    choice(
      seq('(', $.constructor_or_variable_pattern, ')'),
      $.tuple_pattern,
    ),
    $.kw_equals,
    $._block,
  )
}