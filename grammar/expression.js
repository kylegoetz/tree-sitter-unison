const literals = require("./literal");
const { KEYWORD } = require("./precedences");

module.exports = {
  _expression: ($) =>
    prec.right(
      choice(
        $.literal_function,
        $.exp_let,
        $.exp_if,
        $.handler,
        $.function_application,
        $._literal,
        $._hash_qualified,
        $._pattern_matching,
        $.parenthetical_exp,
        $._boolean_exp,
        $.delay_block,
        $.bang,
      ),
    ),

  operator_as_parameter: ($) => seq("(", $.operator, ")"),
  parenthetical_exp: ($) =>
    prec(
      -10,
      seq(
        "(",
        $._expression,
        optional(seq($.type_signature_colon, $._value_type)),
        ")",
      ),
    ),
};
