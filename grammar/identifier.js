// const { sep } = require('./util')
const regex = require('./regex')

// const varid_pattern = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u
// const lowercase_varid_pattern = /[a-z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u
// const unicode = '\u{1F400}-\u{1FAFF}'
// const alpha = 'a-zA-Z'
// const initials = `[${alpha}_${unicode}]`
// const noninitials = `[${alpha}_!'${unicode}]`

// const varid_str = `\.?(${initials}${noninitials}*\.)*${initials}${noninitials}*`
// const varid_re = RegExp(varid_str, 'u')

// const varid = /\.?([a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*\.)*[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u


module.exports = {  
  wordy_id: $ => regex.varid,
  symboly_id: $ => regex.symboly_id,
  // symboly_id: $ => $.operator,
  
  /**
   * Accounts for qualified, unqualified (and absolute) identfiers,
   * wordy, and symboly.
   * `foo`
   * `++`
   * `Nat.++`
   * .Foo.bar`
   */
  _identifier: $ => choice(
    $.wordy_id,
    regex.symboly_id,
    $.__identifier,
  ),
  path: $ => regex.path,
  
  _symboly_id_with_path: $ => seq(optional($.path), alias(token.immediate(regex.symboly_id), $.operator)),
  _wordy_id_with_path: $ => seq(optional($.path), alias(token.immediate(regex.varid), $.wordy_id)),
  
  __identifier: $ => prec.left(choice(
    $._wordy_id_with_path,
    $._symboly_id_with_path,
  )),
  
  // __identifier: $ => seq(
  //   optional($.path/*field('namespace', regex.path)*/),
  //   choice(
  //     alias(token.immediate(regex.varid), $.wordy_id),
  //     alias(token.immediate(regex.symboly_id), $.symboly_id),
  //   ),
  // ),
    
  namespace: $ => token(regex.namespace),
  
}