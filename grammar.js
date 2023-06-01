const { sep } = require('./grammar/util')
const misc = require('./grammar/misc')
const comments = require('./grammar/comments')
const expressions = require('./grammar/expression')
const blocks = require('./grammar/blocks')
const stmt = require('./grammar/statement')
const literals = require('./grammar/literal')
const types = require('./grammar/type')
const identifiers = require('./grammar/identifier')
const term = require('./grammar/term')
const regex = require('./grammar/regex')
const effects = require('./grammar/effect')


module.exports = grammar({
  name: 'unison',
  precedences: $ => [
    ['term_definition', '_expression'],
    ['keyword', '_expression'],
    ['function_application', 'operator'], // `myFn a b + c` is equivalent to `((myFn a) b) + c`
    ['_infix_op_application', '_prefix_function_application'],
  ],
  conflicts: $ => [
    [$.function_param, $._function_name],
    [$._function_name, $._expression],
    [$.value_type],
    [$.type2],
  ],
  externals: $ => [
    $._layout_semicolon,
    $._layout_start,
    $._layout_end,
    $._dot,
    $._where,
    $._varsym,
    $.comment,
    $.fold,
    $._comma,
    $._in,
    $._indent,
    $._empty,
    $.nat,
    $.int,
    $.float,
    $.operator,
  ],
  extras: $ => [
    /\\?\s/,
    $.comment,
    $.comment_multiline,
  ],
  rules: {
    unison: $ => repeat(
      choice(
        $.type_declaration,
        $.term_declaration,
        $.fold,
        $.comment_documentation_block,
        $.use_clause,
        $.effect_declaration,
      ),
    ),
    
    ...effects,
    ...identifiers,
    ...types,
    ...literals,
    ...misc,
    ...comments,
    ...blocks,
    ...expressions,
    ...stmt,
    ...term,
    
    kw_forall: $ => choice("forall", "∀"),
    kw_equals: $ => '=',
    
    type_signature_colon: $ => ':',
    type_signature: $ => seq(
      field('term_name', $.wordy_id),
      $.type_signature_colon,
      $.type,
    ),
    
    type_variable: $ => regex.lowercase_varid,
    type_arrow: $ => '->',
    
    type: $ => seq(
      optional(seq(
        $.kw_forall, 
        repeat1($.type_variable), 
        token.immediate('.')
      )), 
      sep1($.type_arrow, field('type_name', $.wordy_id)),
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
      // $.kw_forall,
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
      'namespace',
      'cases',
      'match',
      'with',
    )
  },
})
