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
  // _varid: $ => varid,
  // _varid: $ => varid_pattern,
  // _lcase_varid: $ => lowercase_varid_pattern,
  // _immediate_varid: $ => token.immediate(varid_pattern),
  // _immediate_varid: $ => token.immediate(varid),
  // _immediate_dot: $ => token.immediate('.'),
  
  // Foo.bar <-- Foo(ns) bar(name)
  // qualifier: $ => prec.right(seq(
  //   optional($._immediate_dot),
  //   $._varid,
  //   optional(seq(
  //     $._immediate_dot,
  //     sep1(token.immediate('.'), $._immediate_varid)
  //   )),
  // )),
  
  // _namespace_qualified: $ => seq(
    // $.qualifier,
    // $._immediate_dot,
    // choice($.regular_identifier, $.operator)
  // ),
  
  // varid: $ => $._varid,
  
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
  
  wordy_id: $ => regex.varid,
  symboly_id: $ => $.operator,
  
  /**
   * Accounts for qualified, unqualified (and absolute) identfiers,
   * wordy, and symboly.
   * `foo`
   * `++`
   * `Nat.++`
   * .Foo.bar`
   */
  identifier: $ => choice(
    $.wordy_id,
    $._identifier,
  ),
  _identifier: $ => seq(
    optional(field('namespace', regex.path)),
    field('wordy_id', token.immediate(regex.varid)),
  ),
    
  namespace: $ => token(regex.namespace),
  
}