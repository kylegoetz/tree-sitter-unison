const regex = require('./regex')
const HASH_PREFIX = /#[0-9a-zA-Z]+/

const HASH_QUALIFIER = /#[0-9a-zA-Z]+(\.[0-9a-zA-Z]+)?(#[0-9a-zA-Z]+)?/

module.exports = {  
  wordy_id: $ => regex.varid,
  imm_wordy_id: $ => token.immediate(regex.varid),
  
  symboly_id: $ => regex.symboly_id,
  imm_symboly_id: $ => token.immediate(regex.symboly_id),
  
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
  
  __identifier: $ => prec.left(choice(
    seq($.path, alias($.imm_wordy_id, $.wordy_id)),
    $.wordy_id,
    seq($.path, alias($.imm_symboly_id, $.operator)),
    $.operator,
  )),
    
  namespace: $ => token(regex.namespace),
  
  _hash_qualified: $ => choice(
    $._identifier,
    $.built_in_hash,
    alias(HASH_QUALIFIER, $.hash_qualifier),
    seq($._identifier, alias(token.immediate(HASH_QUALIFIER), $.hash_qualifier)),
    // seq($.hash_prefix, optional($._hash_tail)),
    // seq($._identifier, seq(alias($.imm_hash_prefix, $.hash_prefix), optional($._hash_tail))),
  ),
  hash_prefix: _ => HASH_PREFIX,
  imm_hash_prefix: _ => token.immediate(HASH_PREFIX),
  hash_cycle: _ => token.immediate(/\.[0-9a-zA-Z]+/),
  hash_cid: _ => token.immediate(/#[0-9a-zA-Z]+/),
  // _hash_tail: $ => seq(optional($.hash_cycle), optional($.hash_cid)),
  _hash_tail: $ => choice(
    $.hash_cycle,
    $.hash_cid,
    seq($.hash_cycle, $.hash_cid),
  ),
  built_in_hash: $ => seq(
    '##',
    alias(token.immediate(regex.path), $.path),
    choice(
      alias($.imm_wordy_id, $.wordy_id),
      alias($.imm_symboly_id, $.operator),
    )
  ),
}

const maybe_with_path = ($, rule, maybeAlias) => choice(
  seq($.path, token.immediate(rule)),
  rule,
)