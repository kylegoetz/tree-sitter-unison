module.exports = {
  watch_expression: ($) =>
    seq(
      $._watch_start,
      choice(alias($.binding, $.term_declaration), $._block_term),
    ),
  test_watch_expression: ($) =>
    seq(choice("test>", "test.io>"), $.watch_expression),
};
