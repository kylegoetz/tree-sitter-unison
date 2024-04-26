const { KEYWORD } = require('./precedences')
const funcApp = require('./function-application')
const { sep, layouted } = require('./util')

module.exports = {
  ...funcApp,
  
  operator_expression: $ => seq(
    $._expression,
    $.operator,
    $._expression
  ),
  
  multiline_block: $ => seq(
    optional(seq(sep1($._layout_semicolon, $._statement))),
    $._expression,
  ),

  _block: $ => seq(
    $.layout_start,
    $.multiline_block,
    $.layout_end,
  ),

    _block: $ => layouted($, $._statement),
  
  // let [sm_1] [sm_2] ... [sm_n] [exp]
  exp_let: $ => seq(
    $.kw_let, 
    $._block,
  ),
  
  // handle [block] with [block]
  handler: $ => seq(
        $.handle,
        $._block,
        $.with,
        $._block,
    ),
  rewrite_block: $ => seq($.rewrite, $._layout_start, terminated($, choice($.rewrite_term, $.rewrite_case, $.rewrite_type)), $._layout_end),
  rewrite_term: $ => seq($.term, $._lhs, $.superarrow , $._block),
  rewrite_case: $ => seq($.case, $._lhs, $.superarrow, $._block),
  rewrite_type: $ => seq($.signature, repeat1($._prefix_definition_name), $.typesig_dot , $._computation_type, $.superarrow, $._layout_start, $._computation_type, $._layout_end),
}