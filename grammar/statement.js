module.exports = {
  
  _statement: $ => prec.right(choice(
    $.term_definition,
    $._expression,
    $.use_clause
  )),
  
}