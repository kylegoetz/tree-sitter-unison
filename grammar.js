const { sep } = require('./grammar/util')

module.exports = grammar({
  name: 'unison',
  rules: {
    unison: $ => seq(
      choice(
        $.term_declaration,
        $.comment,
        // $._reserved_kw,
      ),
    ),
    
    _eol: $ => /\r?\n/,
    
    comment: $ => seq('--', /.+/, $._eol),
    
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
    expression: $ => /.+/,
    
    term_definition: $ => seq(
      $.name,
      seq($.type_variable),
      $.kw_equals,
      $.expression
    ),
    
    term_declaration: $ => seq(
      optional($.type_signature),
      $.term_definition
    ),
    
    _lowercase_regular_identifier: $ => /[a-z]+/,
    regular_identifier: $ => $._regular_identifier,
    _regular_identifier: $ => /[a-zA-Z_0-9]+/,
    
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
      'termLink',
      'typeLink',
    )
  },
})
