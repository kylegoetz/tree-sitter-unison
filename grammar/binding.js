module.exports = {
  /**
   * Destructuring binding
   */
  destructuring_bind: $ => seq(
    $._pattern_lhs,
    $.kw_equals,
    $._block,
  )
}