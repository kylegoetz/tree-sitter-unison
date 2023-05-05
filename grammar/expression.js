const literals = require('./literal')

module.exports = {
    
  assignment: $ => seq($.regular_identifier, $.kw_equals, $._literal),
  _expression: $ => prec('_expression', choice(
    $.exp_let,
    $.functional_expression,
    // $.assignment,
    $._literal,
    $.regular_identifier,
  )),
  ...literals,
  
  
  namespace: $ => $._regular_identifier,
  use_clause: $ => 'TODO',
  // use_clause: $ => seq('use', $.namespace, repeat($.regular_identifier)),
  
}