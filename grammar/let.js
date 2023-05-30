module.exports = {
  kw_let: _ => 'let',
  exp_let: $ => seq($.kw_let, $.block),
  
  block: $ => $._block,
}