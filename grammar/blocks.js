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

  // _block: $ => seq(
  //   $.layout_start,
  //   $.multiline_block,
  //   $.layout_end,
  // ),

    _block: $ => layouted($, $._statement),

  // let [sm_1] [sm_2] ... [sm_n] [exp]
  // exp_let: $ => openBlockWith($.kw_let),
  exp_let: $ => prec.right(seq($.kw_let, layouted_without_end($, $._statement))),
  // exp_let: $ => seq(
  //   $.kw_let,
  //   $._block,
  // ),

  // handle [block] with [block]
  handler: $ => seq(
        $.handle,
        $._block,
        $.with,
        $._block,
    )
}
