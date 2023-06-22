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
  imm_wordy_id: $ => token.immediate(regex.varid),
  
  symboly_id: $ => regex.symboly_id,
  imm_symboly_id: $ => token.immediate(regex.symboly_id),
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
    alias(regex.symboly_id, $.operator),
    $.__identifier,
  ),
  path: $ => regex.path,
  
  // _symboly_id_with_path: $ => seq(optional($.path), alias(token.immediate(regex.symboly_id), $.operator)),
  // _wordy_id_with_path: $ => seq(
  //   optional($.path), 
  //   choice(/*'square', */alias(token.immediate(regex.varid), $.wordy_id))
  // ),
  // _wordy_id_with_path: $ => maybe_with_path($, /*alias(regex.varid, $.wordy_id)*/$.wordy_id),
  // _wordy_id_with_path: $ => choice(
    // seq($.path, $.imm_wordy_id),
    // $.wordy_id,
  // ),
  // _symboly_id_with_path: $ => maybe_with_path($, alias(regex.symboly_id, $.operator)),
  
  __identifier: $ => prec.left(choice(
    seq($.path, alias($.imm_wordy_id, $.wordy_id)),
    $.wordy_id,
    seq($.path, alias($.imm_symboly_id, $.operator)),
    alias($.symboly_id, $.operator),
    // $._wordy_id_with_path,
    // $._symboly_id_with_path,
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

const maybe_with_path = ($, rule, maybeAlias) => choice(
  seq($.path, token.immediate(rule)),
  rule,
)