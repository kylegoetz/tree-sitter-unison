const bindings = require("./grammar/term-");
const types = require("./grammar/types");
const useClause = require("./grammar/use-clause");
const identifiers = require("./grammar/identifier");
const reserved = require("./grammar/reserved");
const watch = require("./grammar/watch");
const externals = require("./grammar/externals");
const conflicts = require("./grammar/conflicts");

module.exports = grammar({
  name: "unison",
  precedences: ($) => [
    ["_expression", "identifier"],
    ["term_definition", "_expression"],
    ["keyword", "_expression"],
    ["function_application", "operator"], // `myFn a b + c` is equivalent to `((myFn a) b) + c`
    ["_infix_op_application", "_prefix_function_application"],
    ["literal_function", "function_application"],
    ["_boolean_exp", "literal_function"],
    ["constructor_or_variable_pattern", "_lhs"],
  ],
  conflicts,
  externals,
  extras: ($) => [/\\?\s/, $.comment],
  rules: {
    unison: ($) =>
      repeat(
        choice(
          $.watch_expression,
          $.test_watch_expression,
          $.type_declaration,
          alias($.documented_binding, $.term_declaration),
          alias($.binding, $.term_declaration),
          $.fold,
          $.documented_use_clause,
          $.use_clause,
          alias($.effect_declaration, $.ability_declaration),
        ),
      ),
    ...bindings,
    ...types,
    ...useClause,
    ...reserved,
    ...identifiers,
    ...watch,
  },
});
