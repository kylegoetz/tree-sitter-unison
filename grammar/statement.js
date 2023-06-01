module.exports = {
  
  _statement: $ => prec.right(choice(
    $.term_declaration,
    $._expression,
    $.use_clause
  )),
  
}