module.exports = {
  if_block: $ => seq('if', $.__block),
  then_block: $ => seq('then', $.__block),
  else_block: $ =>
    seq(
      'else',
      seq(
        $._layout_start,
        repeat(seq(choice($._statement, $.use_clause), $._layout_semicolon)),
        $.block_term,
        optional($._layout_end),
      ),
    ),
  // Note: do not convert this to use layoutBlock because there is an infinite loop when running `tree-sitter generate`
  exp_if: $ => prec.right(seq($.if_block, $.then_block, $.else_block)),
}
