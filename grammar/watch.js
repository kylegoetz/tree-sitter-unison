module.exports = {
  _watch_expression: $ => choice($.doc_block, alias($._binding, $.term_declaration), $._block_term),
  watch_expression: ($) =>
    seq(
      $._watch_start,
      $._watch_expression
    ),
  test_watch_expression: ($) =>
    seq(choice("test>", "test.io>"), $._watch_expression),
};
