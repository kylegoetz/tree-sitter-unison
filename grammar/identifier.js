const regex = require('./regex')
const { parens } = require('./util')

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
  
  _hq_qualified_wordy_id: $ => seq(
    choice(
      $.wordy_id,
      seq($.path, alias($.imm_wordy_id, $.wordy_id)),
    ),
    optional(alias($.imm_hash_qualifier, $.hash_qualifier)),
  ),
  
  _hq_qualified_symboly_id: $ => seq(
    choice(
      $.operator,
      seq($.path, alias($.imm_symboly_id, $.operator)),
    ),
    optional(alias($.imm_hash_qualifier, $.hash_qualifier)),
  ),
  
  _hq_qualified_prefix_term: $ => choice(
    $._hq_qualified_wordy_id,
    parens($._hq_qualified_symboly_id),
  ),
  
  _hq_qualified_infix_term: $ => $._hq_qualified_symboly_id,

  built_in_hash: $ => seq(
    '##',
    optional(alias(token.immediate(regex.path), $.path)),
    choice(
      alias($.imm_wordy_id, $.wordy_id),
      alias($.imm_symboly_id, $.operator),
    )
  ),
  
  _prefix_definition_name: $ => choice(
    $._wordy_definition_name,
    parens($._symboly_definition_name),
  ),
  _wordy_definition_name: $ => choice(
      $.wordy_id,
      seq($.path, alias($.imm_wordy_id, $.wordy_id)),
  ),
  _symboly_definition_name: $ => choice(
      $.operator,
      seq($.path, alias($.imm_symboly_id, $.operator)),
  ),
}