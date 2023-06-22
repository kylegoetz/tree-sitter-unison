const { parens } = require('./util')
const regex = require('./regex')

module.exports = {
  // _prefix_op: $ => seq('(', choice($.operator, $._symboly_id_with_path), ')'),
  _prefix_op: $ => parens($._op),
  
  _function_name: $ => choice(
    // $._identifier, 
    $.wordy_id,
    seq($.path, token.immediate(regex.varid)),
    // $._wordy_id_with_path,
    $._prefix_op,
  ),
    
  _function_param: $ => choice(
    prec.left($._expression),
    $._prefix_op,
  ),
    
  partial_application: $ => $._prefix_function_application,
    
  /**
   * In Unison, all fns are unary. An n-ary function is modeled as either
   * 1. unary function that returns a partially-applied function; or
   * 2. unary function that takes a tuple as the argument.
   *
   * This function name can be a `varid` or `(symop)`.
   */
  _prefix_function_application: $ => choice(
    seq(field('function_name', $._function_name), $._function_param),
    seq($._prefix_function_application, $._function_param),
  ),
  
  _op: $ => choice($.operator, seq($.path, alias(token.immediate(regex.symboly_id), $.operator))),
  
  // p1 + p2
  _infix_op_application: $ => prec.right(seq(
    $._expression, 
    $._op,
    // choice(
      // $.operator,
      // $._symboly_id_with_path
    // ), 
    $._expression,
  )),
  
  function_application: $ => choice(
    // '(+) 5 2',
    $._prefix_function_application,
    $._infix_op_application,
  ),
}

// module.exports = {
  // _prefix_op: $ => seq('(', choice($.operator, $._symboly_id_with_path), ')'),
  // _function_param: $ => choice(
  //   prec.left($._expression),
  //   $._prefix_op,
  // ),
  
  // _function_name: $ => choice(
  //   $._identifier, 
  //   $._prefix_op,
  // ),
  
//   partial_application: $ => $._prefix_function_application,
  
  // /**
  //  * In Unison, all fns are unary. An n-ary function is modeled as either
  //  * 1. unary function that returns a partially-applied function; or
  //  * 2. unary function that takes a tuple as the argument.
  //  *
  //  * This function name can be a `varid` or `(symop)`.
  //  */
  // _prefix_function_application: $ => choice(
  //   seq(field('function_name', $._function_name), $._function_param),
  //   seq($._prefix_function_application, $._function_param),
  // ),
  
  // // p1 + p2
  // _infix_op_application: $ => prec.right(seq(
  //   $._expression, 
  //   choice($.operator, $._symboly_id_with_path), 
  //   $._expression,
  // )),
  
//   function_application: $ => choice(
//     // '(+) 5 2',
//     $._prefix_function_application,
//     $._infix_op_application,
//   ),
//  