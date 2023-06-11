module.exports = {
  
  _statement: $ => prec.left(choice(
    $.term_declaration,
    $._expression,
    $.use_clause
  )),
  
}