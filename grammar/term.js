const { layouted } = require('./util')
const regex = require('./regex')

module.exports = {
  /**
   * x : Nat <-- type signature
   * x = 5 <-- term definition
   */
  term_declaration: $ => prec(20, seq(
    optional($.doc_block),
    optional($.type_signature),
    $.term_definition
  )),

  /**
    * x = 5
    * myFun p1 ... pn = p1 + ... + pn
    */
  _lhs: $ => prec('_lhs', seq(field('name', $._prefix_definition_name), repeat(field('param', alias($.wordy_id, $.regular_identifier))))),
  term_definition: $ => seq(
    $._lhs,
    open_block_with($, $.kw_equals),
    // $.kw_equals,
    // $._block,
    // choice($._expression, $._block),//$._block, // works with $._expression for simple things
  ),
}
