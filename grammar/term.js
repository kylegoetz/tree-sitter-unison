const { layouted } = require('./util')
const regex = require('./regex')

module.exports = {
  /**
   * x : Nat <-- type signature
   * x = 5 <-- term definition
   */
  term_declaration: $ => prec(20, seq(
    optional($.type_signature),
    $.term_definition
  )),
  
  lcase: $ => regex.lowercase_varid,
  
  // fn: $ => prec.right(seq(
  //   field('func_name', $.varid),
  //   repeat(field('func_param', $.lcase))
  // )),
  
  // _lhs: $ => seq(
  //   $.varid,
  //   repeat($.lcase)
  // ),
  // _lhs: $ => repeat1($.wordy_id),
  
  /**
    * x = 5
    * myFun p1 ... pn = p1 + ... + pn
    */
  block: $ => $._block,
  // term_definition: $ => 'x = 1 + 2',
  _lhs: $ => seq($.wordy_id, repeat($.wordy_id)),
  term_definition: $ => seq(
    $._lhs,
    // field('lhs', seq(
    //   field('func_name', $.wordy_id),
    //   field('func_params', repeat($.wordy_id)))),
    $.kw_equals,
    $._block, // works with $._expression for simple things
  ),
}