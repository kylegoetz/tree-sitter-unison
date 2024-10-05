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
// const term$ = require('./grammar/revised-term')


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
    [$._value_type],
    [$._type2],
    [$._type1, $.constructor],
    [$._prefix_function_application, $.function_application],
    [$._literal, $._expression],
    [$._infix_op_application, $.literal_function],
    [$.imm_symboly_id, $._op],
    [$._literal, $._literal_pattern],
    [$._expression, $.constructor_or_variable_pattern],
    [$.literal_list, $.literal_list_pattern],
    [$._identifier, $._wordy_definition_name, $.literal_function],
    [$._identifier, $._wordy_definition_name],
    [$._wordy_definition_name, $.literal_function],
    [$._identifier, $._wordy_definition_name, $.literal_function, $._lhs],
    [$._identifier, $._symboly_definition_name],
    [$._symboly_definition_name, $._op],
    // [$.path, $._wordy_definition_name],

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
    $.doc_block,
  ],
  rules: {
    unison: $ => repeat(
      choice(
        // alias($._identifier, $.id),
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
    // ...term$,



    type_signature: $ => seq(
      field('term_name', $._prefix_definition_name),
      $.type_signature_colon,
      alias($._value_type, $.term_type),
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

const composeRegex = (...res) => new RegExp(res.map(_ => `(${_.source})`).join('|'), 'u')
