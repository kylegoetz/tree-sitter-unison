module.exports = {
  // comment_line: $ => seq('--', optional(token.immediate(/[^-].*/)), /(\r)?\n/),

  // TODO can appear anywhere 
  // comment_multiline: $ => /{-([\s\S]|.)*?-}/m,
  // comment_multiline: $ => seq('{-', /.*/m, '-}'),
  
  // TODO can this appear anywhere?
  // comment_documentation_block: $ => seq('{{', /.*/m, '}}'),
  // comment_documentation_block: $ => /\{\{.*}}/m,
}