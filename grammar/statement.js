module.exports = {
  
  _statement: $ => prec.left(choice(
    $.destructuring_bind,
    $.term_declaration,
    $._expression,
    $.use_clause,
  )),
  
}