const { sep } = require('./util')
const regex = require('./regex')

const varid_pattern = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u
const lowercase_varid_pattern = /[a-z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u
const unicode = '\u{1F400}-\u{1FAFF}'
const alpha = 'a-zA-Z'
const initials = `[${alpha}_${unicode}]`
const noninitials = `[${alpha}_!'${unicode}]`

const varid_str = `\.?(${initials}${noninitials}*\.)*${initials}${noninitials}*`
const varid_re = RegExp(varid_str, 'u')

const varid = /\.?([a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*\.)*[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u


module.exports = {
  _varid: $ => varid,
  // _varid: $ => varid_pattern,
  _lcase_varid: $ => lowercase_varid_pattern,
  // _immediate_varid: $ => token.immediate(varid_pattern),
  _immediate_varid: $ => token.immediate(varid),
  _immediate_dot: $ => token.immediate('.'),
  
  // Foo.bar <-- Foo(ns) bar(name)
  qualifier: $ => prec.right(seq(
    optional($._immediate_dot),
    $._varid,
    optional(seq(
      $._immediate_dot,
      sep1(token.immediate('.'), $._immediate_varid)
    )),
  )),
  
  // _namespace_qualified: $ => seq(
    // $.qualifier,
    // $._immediate_dot,
    // choice($.regular_identifier, $.operator)
  // ),
  
  varid: $ => $._varid,
  
  // .Foo.bar <-- dot(abs qualifier) Foo(ns) bar(name)
  // _absolutely_qualified: $ => seq(
    // optional(seq($._immediate_dot,
    // $.qualifier,
    // $._immediate_dot)),
    // choice($.varid, $.operator),
  // ),
  
  // (.)Foo.bar(#asd09afj) <-- dot(abs qualifier) Foo(ns) bar(name) asd...(hash literal)
  // identifier: $ => seq(
  //   optional(seq($.qualifier, $._immediate_dot)),
  //   choice($.varid, $.operator),
  //   optional($.literal_hash),
  // ),
  
  identifier: $ => choice(
    seq(new RegExp(`${regex.varid}\\.`, 'u'), token.immediate(regex.varid)),
    regex.varid,
  ),
  
  namespace: $ => regex.namespace,
  
  // identifier: $ => choice(
    // $._namespace_qualified,
    // $._absolutely_qualified,
    // optional($.literal_hash),
  // ),
}