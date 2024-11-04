const { layouted, sep, sep1, openBlockWith, terminated } = require("./util");

module.exports = {
  _pattern_matching: ($) => choice($._match_with, $._lam_case),

  _match_with: ($) =>
    prec.right(
      seq(
        // "match",
        openBlockWith($, $.match),
        field("scrutinee", $._expression),
        optional($._layout_end),
        openBlockWith($, $.with),
        // $.with,
        // "a -> true",
        $._match_cases,
        optional($._layout_end),
      ),
    ),

  _lam_case: ($) =>
    prec.right(
      seq(openBlockWith($, $.cases), $._match_cases, optional($._layout_end)),
    ),

  _match_cases: ($) => prec.right(sep1($._layout_semicolon, $.pattern)),

  /**
   * Pattern examples:
   * 5 -> "foo"
   * foo | foo == 1 -> "one"
         | otherwise -> "not one"
   */
  pattern: ($) => seq(
    $._pattern_root, prec.right($._pattern_rhs)),

  /**
   * Without typechecking, we cannot know whether a single wordy_id is an identifier or constructor pattern with 0-arity, so
   * we only have a constructor pattern here as an option, no wordy_id pattern.
   */
  // _pattern_lhs: ($) =>
  //   prec.right(
  //     choice(
  //       alias("_", $.blank_pattern), // unbound
  //       $._literal_pattern, // literal
  //       $.as_pattern, // varOrAs
  //       $.constructor_or_variable_pattern, // nullaryCtor, varOrAs
  //       $._list_pattern, // seq literal
  //       $.tuple_pattern, //parenthesized_or_tuple_pattern
  //       $.ability_pattern, // effect
  //     ),
  //   ),

  /**
   * "A pattern's RHS is either one or more guards, or a single unguarded block"
   * (from Unison's TermParser.hs)
   */
  _pattern_rhs: ($) =>
    prec.right(choice(
      seq(
        $._guard_layout_start,
        sep1($._layout_semicolon, $.guarded_block),
        $._layout_end,
      ),
      // open_block_with($, $.arrow_symbol),
      seq(openBlockWith($, $.arrow_symbol), $.__block),
      // seq(
      //   $._layout_start,
      //   // terminated($, $.guarded_block),
      //   sep1($._layout_semicolon, $.guarded_block),
      //   // optional($._layout_semicolon),
      //   $._layout_end),
      // // prec.right(layouted($, $.guarded_block)), // TODO this is the problem child preventing `2 +: _` from being recognized as a pattern instead after the `2` the space is recognized as LAYOUT_START
      // // seq($._layout_start, layouted($, $.guarded_block), $._layout_end),
    )),

  _literal_pattern: ($) =>
    choice(
      // Observe Float is not allowed.
      alias("0", $.nat), // Strangely this code will not parse without this line: `> match x with 0 | 1 == 2 -> 123`
      $.literal_boolean,
      $.nat,
      $.int,
      $.literal_char,
      $.literal_text,
    ),
  // as_pattern: ($) =>
  //   prec.left(
  //     seq(alias($.wordy_id, $.regular_identifier), $.as, $._pattern_lhs),
  //   ),

  // constructor_or_variable_pattern: ($) =>
  //   prec.right(
  //     "constructor_or_variable_pattern",
  //     seq($._hash_qualified, repeat(prec.left($._pattern_lhs))),
  //   ),

  // _list_pattern: ($) =>
  //   choice(
  //     $.head_tail_list_pattern,
  //     $.init_last_tail_pattern,
  //     $.literal_list_pattern,
  //     $.concat_list_pattern,
  //   ),
  // tuple_pattern: ($) => seq("(", sep(",", $._pattern_lhs), ")"),
  // ability_pattern: ($) => choice(seq("{", $._pattern_lhs, "}")),

  /**
   * A list pattern can be one of the following:
   * head [List.]+: tail
   * init [List.]:+ last
   * [p_1, p2, ..., p_n] where p_i is a PATTERN
   * part1 [List.]++ part2 where one of part1 and part2 must be a list of known length, e.g.
   *   [x, y] ++ rest
   *   start ++ [x, y]
   *   BUT NOT a ++ b
   *   TODO: pare this pattern down to something like choice(seq('head', '++', LIST_LITERAL), ...) instead of seq(choice($.wordy_id, $.list_literal, '++', ...))
   */
  // head_tail_list_pattern: ($) =>
  //   prec.right(seq($._pattern_lhs, "+:" /*(List\.)?\+:*/, $._pattern_lhs)),
  // init_last_tail_pattern: ($) =>
  //   prec.right(seq($._pattern_lhs, /(List\.)?:\+/, $._pattern_lhs)),
  // // literal_list_pattern: ($) => seq("[", sep(",", $._pattern_lhs), "]"),
  // concat_list_pattern: ($) =>
  //   prec.right(seq($._pattern_lhs, /(List\.)?\+\+/, $._pattern_lhs)),
  /**
   * A guard can be one of the following:
   * - | BOOL_EXPR (OPEN) -> BLOCK (CLOSE)
   * - | OTHERWISE (OPEN) -> BLOCK (CLOSE)
   */
  // guard: $ => prec.right(seq(
  //   $.pipe,
  //   choice($._infix_op_application, $.otherwise),
  //   open_block_with($, $.arrow_symbol, $._start_before_arrow))),
  guard: ($) => choice($._expression, $.otherwise),

  guarded_block: ($) => prec.right(seq($.pipe, $.guard, open_block_with($, $.arrow_symbol))),

  _pattern_root: ($) =>
    seq(
      $._pattern_candidates,
      repeat(seq($._pattern_infix_app, $._pattern_candidates)),
    ),

  _pattern_infix_app: ($) =>
    choice(alias("++", $.concat), alias("+:", $.cons), alias(":+", $.snoc)),
  // _a: ($) => seq($._pattern_leaf, optional($._a)),
  _pattern_constructor: ($) => prec.right(seq(alias($._hq_qualified_prefix_term, $.ctor), repeat1($._pattern_leaf))),
  // ctor: ($) => prec.right($._hq_qualified_prefix_term),
  _pattern_candidates: ($) => choice($._pattern_constructor, $._pattern_leaf),

  /*
   *  NOTE: TermParser.hs says @leaf is optional but to simplify conflicts,
   * it is mandatory here. To compensate, wordy_id is allowed as a pattern.
   * By this we avoid a parse conflict between `var_or_as` and `_identifier`, which
   * otherwise are possible parent nodes for a bare `wordy_id`.
   *
   * Let `ctor` take care of a bare identifier.
   */
  var_or_as: ($) =>
    seq(
      alias($.wordy_id, $.regular_identifier),
      seq(alias("@", $.at_token), $._pattern_leaf),
    ),
  // unbound: ($) => "_",
  // Note: Unfortunately the SEMI is disabled here because leaving it in creates a parsing error where
  literal_list_pattern: ($) =>
    seq(
      "[",
      // openBlockWith($, "["),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      sep(seq(/*optional($._layout_semicolon),*/ ","), $._pattern_root),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      // $._layout_end,
      "]",
    ),
  parenthesized_or_tuple_pattern: ($) =>
    seq(
      openBlockWith($, "("),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      sep1(",", $._pattern_root),
      // repeat(prec.right(choice(",", $._layout_semicolon))),
      $._layout_end,
      ")",
    ),

  effect_pure: ($) => $._pattern_root,
  effect_bind: ($) =>
    seq($._hq_qualified_prefix_term, repeat1($._pattern_leaf), "->", $._pattern_root),

  effect_pattern: ($) =>
    seq(
      openBlockWith($, "{"),
      choice($.effect_pure, $.effect_bind),
      $._layout_end,
      "}",
    ),
  _pattern_leaf: ($) =>
    prec(2, choice(
      alias($.wordy_id, $.var_or_nullary_ctor),
      $.var_or_as,
      $._literal_pattern,
      alias("_", $.blank_pattern),
      $.literal_list_pattern,
      $.parenthesized_or_tuple_pattern,
      $.effect_pattern,
    )),
};
