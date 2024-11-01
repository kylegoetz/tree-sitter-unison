const types = require("./type");
const effects = require("./effect");

/**
 * There are five types of top-level patterns:
 * 1. bindings
 * 2. type definitions
 * 3. use clauses
 * 4. watch expressions
 *
 * This file contains everything related to type definitions.
 */
module.exports = {
  ...types,
  ...effects,
};
