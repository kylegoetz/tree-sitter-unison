module.exports = {
  
  _statement: $ => choice(
    $.term_definition,
    $._expression,
    $.use_clause
  ),
  
}