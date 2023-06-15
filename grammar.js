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
const pattern_matching = require('./grammar/pattern-matching')
const conditionals = require('./grammar/conditionals')
const reserved = require('./grammar/reserved')


module.exports = grammar({
  name: 'unison',
  precedences: $ => [
    // ['_literal', '_expression'],
    ['_expression', 'identifier'],
    ['term_definition', '_expression'],
    ['keyword', '_expression'],
    ['function_application', 'operator'], // `myFn a b + c` is equivalent to `((myFn a) b) + c`
    ['_infix_op_application', '_prefix_function_application'],
    ['literal_function', 'function_application'],
    ['_boolean_exp', 'literal_function'],
  ],
  conflicts: $ => [
    [$._function_param, $._function_name],
    [$._function_name, $._expression],
    [$._value_type],
    [$._type2],
    [$._type1, $.constructor],
    [$._identifier, $._lhs],
    [$._identifier, $.literal_function],
    [$.wordy_id, $.literal_function],
    [$.type],
    [$._prefix_function_application, $.function_application],
    // [$.identifier, $.binding_lhs],
    [$._identifier, $.type_name],
    [$.tuple_constructor, $.tuple_or_parenthesized],
    [$._literal, $._expression], 
    [$._identifier, $.literal_function, $._lhs],
    [$._infix_op_application, $.literal_function],
    [$._function_name, $._expression, $._lhs],
    [$.partial_application, $.function_application],
    [$._function_name, $._lhs],
    [$._identifier, $._pattern_lhs],
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
    $._parenthesized_operator,
  ],
  extras: $ => [
    /\\?\s/,
    $.comment,
    $.comment_multiline,
  ],
  rules: {
    unison: $ => repeat(
      choice(
        $.watch_expression,
        $.type_declaration,
        $.term_declaration,
        $.fold,
        $.comment_documentation_block,
        $.use_clause,
        alias($.effect_declaration, $.ability_declaration),
      ),
    ),
    
    ...reserved,
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
    ...pattern_matching,
    ...conditionals,
    
    watch_expression: $ => seq('>', $._expression),
    
    
    
    type_signature: $ => seq(
      field('term_name', $._identifier),
      $.type_signature_colon,
      $._value_type,
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
    
    // _reserved_kw: $ => choice(
    //   // '\'',
    //   // 'do',
    //   // '!',
    //   // '`',
    //   'alias',
    //   'namespace',
    //   'cases',
    //   'match',
    //   'with',
    // )
  },
})
