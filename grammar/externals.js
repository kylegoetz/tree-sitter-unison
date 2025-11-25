module.exports = ($) => [
  $._layout_semicolon,
  $._layout_start,
  $._layout_end,
  $._dot,
  $._where,
  $._varsym,
  $.comment,
  $.fold,
  $._comma,
  $._in,
  $._indent,
  $._empty,
  $.DEPRECATED_operator,
  $._parenthesized_operator,
  $._watch_start,
  $._start_before_arrow,
  $.hash_cid,
  $.doc_block,
  $._guard_layout_start, // This is required because otherwise TS can't tell the difference between PATTERNLEAF *(INFIX PATTERN LEAF) . PATTERN_RHS and PATTERNLEAF . PATTERN_RHS and greedily consumes a 0-width space after the first leaf as LAYOUT_START (proceeding to a failing typeguard path) and refuses to backtrack and try the *(INFIX PATTERNLEAF) path
  $.DUMMY,
  // $.pipe, // This is required in conjunction with GUARD_LAYOUT_START
];
