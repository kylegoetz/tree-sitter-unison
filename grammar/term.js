module.exports = {
  /**
   * x : Nat <-- type signature
   * x = 5 <-- term definition
   */
  term_declaration: $ => seq(
    optional($.type_signature),
    $.term_definition
  ),
  
  _fn: $ => prec.right(seq(
    $.varid,
    repeat($._lcase_varid)
  )),
  
  /**
    * x = 5
    */
  term_definition: $ => seq(
    choice($.varid, $._fn), // x OR myFun p1 p2
    $.kw_equals,
    $._block,
  ),
}