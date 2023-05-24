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

const IDENTIFIER_REGEX = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u

module.exports = grammar({
  name: 'unison',
  precedences: $ => [
    ['keyword', 'varid', '_regular_identifier'],
    ['keyword', '_expression'],
    ['function_application', 'operator'], // `myFn a b + c` is equivalent to `((myFn a) b) + c`
    ['_function_application', 'func_name', 'varid', 'regular_identifier'],
    ['_prefix_function_application', '_infix_op_application'],
  ],
  conflicts: $ => [

    [$.func_name, $._function_application, $.regular_identifier],
    // ['function_application', '_expression'],
  //   [$._expression, $.literal_function],
  //   [$.function_application],
  //   [$.exp_if, $.function_application],
  //   [$._expression, $.function_name]
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
  /** 
    * Be judicious using this. Even an empty array changes how whitespace
    * is parsed. $ => [] screws up existing, working grammar.
   **/
  extras: $ => [
    /\\?\s/,
    $.comment,
    // $.comment_line,
    $.comment_multiline,
  ],
  rules: {
    unison: $ => repeat(
      choice(
        $.type_declaration,
        $.term_declaration,
        // $.inline_comment,
        $.fold,
        $.comment_multiline,
        $.comment,
        $.comment_documentation_block,
      ),
    ),
    
    ...identifiers,
    ...types,
    ...literals,
    ...misc,
    ...comments,
    ...blocks,
    ...expressions,
    ...stmt,
    ...term,
    
    // fold: $ => $._fold,
    kw_forall: $ => choice("forall", "∀"),
    kw_equals: $ => '=',
    
    type_signature_colon: $ => ':',
    term_name: $ => $._regular_identifier,
    type_signature: $ => seq(
      $.term_name,
      $.type_signature_colon,
      $.type,
      // $._eol,
    ),
    
    type_name: $ => $._regular_identifier,
    
    name: $ => $._regular_identifier,
    // _term_rhs: $ => $._expression,
    
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
    
    _lowercase_regular_identifier: $ => LOWERCASE_IDENTIFIER_REGEX,
    regular_identifier: $ => prec.left($._regular_identifier),
    
    _regular_identifier: $ => prec.left(IDENTIFIER_REGEX),
    
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
      $.kw_let,
      'namespace',
      'cases',
      'match',
      'with',
      $.kw_termlink,
      $.kw_typelink,
    )
  },
})
