const { layouted } = require("./util");
const regex = require("./regex");

module.exports = {
  /**
   * x : Nat <-- type signature
   * x = 5 <-- term definition
   */


  /**
   * x = 5
   * myFun p1 ... pn = p1 + ... + pn
   */
  _lhs: ($) => choice($._infix_lhs, $._prefix_lhs),
  // _lhs: ($) =>
  //   prec(
  //     "_lhs",
  //     seq(
  //       field("name", $._prefix_definition_name),
  //       repeat(field("param", alias($.wordy_id, $.regular_identifier))),
  //     ),
  //   ),

  _infix_lhs: ($) =>
    seq(
      field("param", $._prefix_definition_name),
      // " ", // TODO This is a hack to prevent `foo>` from being parsed as PARAM . OP (i.e., the start of an infix function application)
      field("name", $._symboly_definition_name),
      field("param", $._prefix_definition_name),
    ),
  _prefix_lhs: ($) =>
    seq(
      field("name", $._prefix_definition_name),
      repeat(field("param", alias($.wordy_id, $.regular_identifier))),
    ),

  // term_definition: ($) =>
  //   seq(
  //     $._lhs,
  //     open_block_with($, $.kw_equals),
  //     // $.kw_equals,
  //     // $._block,
  //     // choice($._expression, $._block),//$._block, // works with $._expression for simple things
  //   ),
};
