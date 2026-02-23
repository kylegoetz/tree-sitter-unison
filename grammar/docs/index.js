/**
 * Top-level module for managing doc syntax
 */
module.exports = {
  _doc_top: $ =>
    choice(
      $.doc_section,
      $.doc_eval,
      $.doc_example_block,
      $.doc_code_block,
      $._doc_list,
      $.doc_paragraph,
    ),
  doc_paragraph: $ => repeat1('TODO paragraph'),
  doc_section: $ => 'TODO doc_section',
  _doc_list: $ => choice($.doc_bulleted_list, $.doc_numbered_list),
  doc_eval: $ => $.unison,
  doc_example_block: $ => $.unison,
  doc_code_block: $ => $.unison,
  doc_column: $ => seq($.doc_paragraph, optional($.doc_list)),
  _doc_leaf: $ =>
    choice(
      $.doc_link,
      $.doc_named_link,
      $.doc_example_code,
      $.doc_bold,
      $.doc_italic,
      $.doc_strikethrough,
      $.doc_verbatim,
      $.doc_code,
      $.doc_source,
      $.doc_folded_source,
      $.doc_eval_inline,
      $.doc_signature,
      $.doc_signature_inline,
      $._doc_word,
      $.doc_group,
    ),
  // doc_embed_link: $ => 'TODO doc_embed_link',
}
