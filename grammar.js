const { sep } = require('./grammar/util')
const misc = require('./grammar/misc')
const comments = require('./grammar/comments')
const expressions = require('./grammar/expression')

module.exports = grammar({
  name: 'unison',
  precedences: $ => [
    ['literal_function', '_expression'],
  ],
  conflicts: $ => [
    // [$.block, $.statement],
    // [$.block, $.term_definition],
    // [$._expression, $.literal_function],
  ],
  externals: $ => [
    $._layout_semicolon,
    $._layout_start,
    $._layout_end,
  ],
  rules: {
    unison: $ => seq(
      choice(
        $.term_declaration,
        $.comment_line,
        $.comment_fold,
        $.comment_multiline,
        $.comment_documentation_block,
      ),
    ),
    
    ...misc,
    ...comments,
    ...expressions,
    
    // comment: $ => seq('--', /.+/, $._eol),
    
    kw_forall: $ => choice("forall", "∀"),
    kw_equals: $ => '=',
    
    type_signature_colon: $ => ':',
    
    type_signature: $ => seq(
      $.regular_identifier,
      $.type_signature_colon,
      $.type,
      $._eol,
    ),
    
    type_name: $ => $._regular_identifier,
    
    name: $ => $._regular_identifier,
    //expression: $ => /.+/,
    
    term_definition: $ => seq(
      $.name,
      repeat($.type_variable),
      $.kw_equals,
      $._expression
    ),
    
    term_declaration: $ => seq(
      optional($.type_signature),
      $.term_definition
    ),
    
    _lowercase_regular_identifier: $ => /[a-z]+/,
    regular_identifier: $ => $._regular_identifier,
    _regular_identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
    
    type_variable: $ => $._lowercase_regular_identifier,
    
    type_arrow: $ => '->',
    
    type: $ => seq(
      optional(seq(
        $.kw_forall, 
        repeat1($.type_variable), 
        token.immediate('.')
      )), 
      sep1($.type_arrow, $.type_name)
    ),
    
    kw_termlink: $ => 'termLink',
    kw_typelink: $ => 'typeLink',
    
    _reserved_kw: $ => choice(
      '=',
      ':',
      '->',
      '\'',
      'do',
      '|',
      '!',
      '`',
      'if',
      'then',
      'else',
      $.kw_forall,
      'handle',
      'unique',
      'structural',
      'where',
      'use',
      '&&',
      '||',
      'true',
      'false',
      'type',
      'ability',
      'alias',
      'let',
      'namespace',
      'cases',
      'match',
      'with',
      $.kw_termlink,
      $.kw_typelink,
    )
  },
})
