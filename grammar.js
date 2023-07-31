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
const destructuring_bind = require('./grammar/binding')
const delayed = require('./grammar/delayed-computation')
const doc = require('./grammar/doc')


module.exports = grammar({
  name: 'unison',
  precedences: $ => [
    ['_expression', 'identifier'],
    ['term_definition', '_expression'],
    ['keyword', '_expression'],
    ['function_application', 'operator'], // `myFn a b + c` is equivalent to `((myFn a) b) + c`
    ['_infix_op_application', '_prefix_function_application'],
    ['literal_function', 'function_application'],
    ['_boolean_exp', 'literal_function'],
    ['constructor_or_variable_pattern', '_lhs'],
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
    [$._identifier, $.type_name],
    [$.tuple_constructor, $.tuple_or_parenthesized],
    [$._literal, $._expression], 
    [$._identifier, $.literal_function, $._lhs],
    [$._infix_op_application, $.literal_function],
    [$._function_name, $._expression, $._lhs],
    [$.partial_application, $.function_application],
    [$._function_name, $._lhs],
    [$._identifier, $._pattern_lhs],
    [$._infix_op_application, $.watch_expression],
    [$.symboly_id, $._identifier],
    [$._identifier, $.__identifier],
    [$._identifier, $.__identifier, $.literal_function, $._function_name],
    [$._identifier, $.__identifier, $._function_name],
    [$.literal_function, $._function_name],
    [$.imm_wordy_id, $._function_name],
    [$._identifier, $.__identifier, $._pattern_lhs],
    [$.imm_symboly_id, $._prefix_op],
    [$._identifier, $.__identifier, $.literal_function],
    [$.__identifier, $._op],
    [$.imm_symboly_id, $._op],
    [$.head_tail_list_pattern, $.init_last_tail_pattern],
    [$.init_last_tail_pattern], // TODO maybe just make this right-associative?
    [$.constructor_or_variable_pattern],
    [$._literal, $._literal_pattern],
    [$._expression, $.constructor_or_variable_pattern],
    [$._identifier, $.__identifier, $._lhs],
    [$.literal_list, $.literal_list_pattern],
    [$._hash_qualified, $._expression],
    [$._hash_qualified, $._expression, $._lhs],
    [$._hash_qualified, $._expression, $.constructor_or_variable_pattern],
    [$._hash_qualified, $._expression, $.type_signature],
    [$._identifier, $.__identifier, $._wordy_definition_name, $.literal_function, $._function_name],
    [$._wordy_definition_name, $.literal_function, $._function_name],
    [$.__identifier, $._symboly_definition_name, $._op],
    [$.__identifier, $._wordy_definition_name],
    [$._identifier, $.__identifier, $._wordy_definition_name],
    [$.__identifier, $._symboly_definition_name],

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
    $._watch_start,
    $._start_before_arrow,
    $.hash_cid,
    $.doc_block,
  ],
  extras: $ => [
    /\\?\s/,
    $.comment,
  ],
  rules: {
    unison: $ => repeat(
      choice(
        $.watch_expression,
        $.test_watch_expression,
        $.type_declaration,
        $.term_declaration,
        $.fold,
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
    ...destructuring_bind,
    ...delayed,
    ...doc,
    
      
    
    type_signature: $ => seq(
      field('term_name', $._prefix_definition_name),
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
    
    _watch_expression: $ => prec.right(choice(
      $._expression,
      $.term_definition,
    )),
    watch_expression: $ => seq($._watch_start, $._watch_expression),
    test_watch_expression: $ => prec.right(seq($.wordy_id, token.immediate('>'), $._watch_expression)),
  }
})