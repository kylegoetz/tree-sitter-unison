const regex = require('./regex')

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
  
  hash_qualifier: $ => seq(
    alias(/#[a-zA-Z0-9]+/, $.hash_prefix), 
    optional(alias($._dot, $.cyclic_index)),
    optional($.hash_cid),
  ),
  
  imm_hash_qualifier: $ => seq(
    alias(token.immediate(/#[a-zA-Z0-9]+/), $.hash_prefix),
    optional(alias($._dot, $.cyclic_index)),
    optional($.hash_cid),
  ),
  
  _hash_qualified: $ => choice(
    $._identifier,
    $.built_in_hash,
    $.hash_qualifier,
    seq(
      $._identifier, 
      alias($.imm_hash_qualifier, $.hash_qualifier),
    ),
  ),

  built_in_hash: $ => seq(
    '##',
    optional(alias(token.immediate(regex.path), $.path)),
    choice(
      alias($.imm_wordy_id, $.wordy_id),
      alias($.imm_symboly_id, $.operator),
    )
  ),
}