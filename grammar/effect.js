const { sep, sep1 } = require('./util')

module.exports = {
    // { E1, E2, ..., En }
    effect_block: $ => seq(
        $._layout_start,
        sep(',', $.value_type),
        $._layout_end,
    ),
    effect_inline: $ => sep1(',', $.value_type),
    effect_list: $ => seq(
        '{',
        optional(choice($.effect_block, $.effect_inline)),
        '}',
    ),
    /** 
     * Cannot have effects except as the RHS of an arrow
     * Int
     * Text
     * value_type -> value_type
     * value_type -> {...} value_type
     */
    value_type: $ => choice(
      // 'e ->{Throw e} a',
      // 'e',
      seq(optional($.kw_forall), $._type1),
    ),
    value_type_leaf: $ => choice(
        seq('(', $.value_type, ')'),
        $.type_atom,
        $.sequence_type,
    ),
    // Optional, Optional#abc, woot, #abc
    immediate_hash: $ => token.immediate(/#[a-zA-Z0-9]+/),
    type_atom: $ => choice(
        seq($.wordy_id, optional($.immediate_hash)),
        seq($.literal_hash),
    ),
    // [Int], [A -> B], etc.
    sequence_type: $ => seq(
        '[',
        choice(
            seq($._layout_start, $.value_type, $._layout_end),
            $.value_type,
        ),
        ']',
    ),
    _type1: $ => choice($.arrow, $._type2a),
    _type2a: $ => choice($.delayed, $._type2),
    _type2: $ => seq(
        $.value_type_leaf,
        repeat(choice($.effect_list, $.value_type_leaf)),
    ),
    delayed: $ => seq(
        "'",
        choice($.effect, $._type2a),
    ),
    arrow_symbol: $ => '->',
    arrow: $ => 
        // 'e ->{Throw e} a',
        seq($.value_type, $.arrow_symbol, /*'{Throw e} a', */$.computation_type),
    
    // arrow: $ => 'e ->{Throw e} a',

    // { E1, E2, ..., En } T
    effect: $ => seq($.effect_list, $._type2),
    
    computation_type: $ => prec.left(choice($.effect, $.value_type)),
    
    /**
     * Effect/ability declarations:
     */
     // throw: $ => 'Throw',
     where: $ => 'where',
    _ebody: $ => seq(
        'Throw', //field('type_name', $.identifier),
        'e', //field('type_args', repeat($.wordy_id)),
        $.where,
        choice(
            sep1(',', $.constructor),
            seq($._layout_start, sep1($._semi, $.constructor), $._layout_end),
        ),
    ),

    // constructor: $ => 'throw : e ->{Throw e} a',
    constructor: $ => seq(
        field('name', $.wordy_id),
        ':',
        field('type', choice($.arrow, $.computation_type)),
        // field('type', 'e ->{Throw e} a'),
    ),
    
    structural: $ => 'structural',
    unique: $ => 'unique',
    ability: $ => 'ability',
    effect_declaration: $ => seq(
        choice($.structural, $.unique),
        $.ability,
        choice(
          // 'Throw e where throw : e ->{Throw e} a',
            // seq($._layout_start, $._ebody, $._layout_end),
            $._ebody,
        ),
    )
}