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
  _lhs: $ => prec('_lhs', seq(field('name', $._prefix_definition_name), repeat(field('param', $.wordy_id)))),
  term_definition: $ => seq(
    $._lhs,
    $.kw_equals,
    $._block,
    // choice($._expression, $._block),//$._block, // works with $._expression for simple things
  ),

  // Haskell stuff
  _term: $ => $._term2,
  _term2: $ => choice(seq($._prefix_definition_name, $.arrow_symbol, $._term2), $._term3),
  _term3: $ => seq($._infix_app_or_boolean_op, optional(seq($.type_signature_colon, $._computation_type))),
  // _term3: $ => seq(choice($._infix_op_application, $._boolean_exp), optional(seq($.type_signature_colon, $._computation_type))),
}