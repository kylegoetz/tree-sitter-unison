const { KEYWORD } = require("./precedences");
const funcApp = require("./function-application");
const { sep, layouted, layoutBlock } = require("./util");

module.exports = {
  ...funcApp,

  operator_expression: ($) => seq($._expression, $.operator, $._expression),

  multiline_block: ($) =>
    seq(optional(seq(sep1($._layout_semicolon, $._statement))), $._expression),

  // _block: $ => seq(
  //   $.layout_start,
  //   $.multiline_block,
  //   $.layout_end,
  // ),

  _block: ($) => layouted($, $._statement),

  // let [sm_1] [sm_2] ... [sm_n] [exp]
  // exp_let: $ => openBlockWith($.kw_let),
  // exp_let: $ => prec.right(seq($.kw_let, layouted_without_end($, $._statement))),
  exp_let: ($) => prec.right(layoutBlock($, $.kw_let)),
  // seq(
  //   open_block_with($, $.kw_let),
  //   // openBlockWith($, $.kw_let),
  //   // repeat(seq($.use_clause, $._layout_semicolon)),
  // ),
  // exp_let: $ => seq(
  //   $.kw_let,
  //   $._block,
  //
  // letBlock = label "let" $ (snd <$> layoutBlock "let")
  // layoutBlock s = block' False False s (openBlockWith s) optionalCloseBlock
  // ),

  // handle [block] with [block]
  handler: ($) => seq($.handle, $._block, $.with, $._block),
};
