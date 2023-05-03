module.exports = {
  comment_line: $ => seq($._eol, '--', /[^-]?.*/, $._eol),
  comment_multiline: $ => seq('{-', /.*/m, '-}'),
  comment_fold: $ => seq($._eol, '---', $._eol, /.+/m),
  comment_documentation_block: $ => seq('{{', /.*/, '}}'),
}