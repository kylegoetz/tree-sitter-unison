const { KEYWORD } = require("./precedences");

module.exports = {
  use: ($) => prec(KEYWORD, "use"),
  use_clause: ($) =>
    prec.right(
      seq($.use, alias($._identifier, $.namespace), repeat($._identifier)),
    ),
  documented_use_clause: ($) =>
    seq($.doc_block, $._layout_semicolon, $.use_clause),
};
