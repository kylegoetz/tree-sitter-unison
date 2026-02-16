module.exports = {
  _watch_expression: $ => choice($.doc_block, alias($._binding, $.term_declaration), $._block_term),
  watch_expression: ($) =>
    seq(
      $._watch_start,
      $._layout_start,
      $._watch_expression,
      optional($._layout_end),
    ),
  test_watch_expression: ($) =>
    seq(choice("test>", "test.io>"), $._watch_expression),
};
