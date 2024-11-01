const bindings = require("./terms");
const literals = require("./literal");
const term = require("./term");
const patterns = require("./pattern-matching");
const conditionals = require("./conditionals");
const destructuring = require("./binding");
const delayed = require("./delayed-computation");
const expression = require("./expression");
const blocks = require("./blocks");

/**
 * There are five types of top-level patterns:
 * 1. bindings
 * 2. type definitions
 * 3. use clauses
 * 4. watch expressions
 *
 * This file contains everything related to bindings.
 */
module.exports = {
  ...bindings,
  ...literals,
  ...term,
  ...patterns,
  ...conditionals,
  ...destructuring,
  ...delayed,
  ...expression,
  ...blocks,

  type_signature: ($) =>
    seq(
      field("term_name", $._prefix_definition_name),
      $.type_signature_colon,
      alias($._value_type, $.term_type),
      // $._layout_semicolon,
    ),
};
