module.exports = {
  /**
   * No preceding whitespace allowed.
   */
  comment_line: $ => seq('--', optional(token.immediate(/[^-].*/)), $._eol),
  
  // TODO can this appear anywhere in code?
  // comment_multiline: $ => seq('{-', /.*/m, '-}'),
  
  /*
   * No preceding whitespace, and `---` can have no trailing chars.
   * Goes until EOF.
   */
  comment_fold: $ => seq('---', $._eol, /.+/m),
  
  // TODO can this appear anywhere?
  comment_documentation_block: $ => seq('{{', /.*/, '}}'),
}