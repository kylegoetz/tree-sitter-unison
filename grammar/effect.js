const { sep, sep1 } = require('./util')

module.exports = {
    
    // { E1, E2, ..., En }
    _effect_block: $ => seq(
        $._layout_start,
        sep(',', alias($._value_type, $.effect)),
        $._layout_end,
    ),
    _effect_inline: $ => sep1(',', alias($._value_type, $.effect)),
    
    _effect_list: $ => seq(
        '{',
            optional($._effect_inline),
        // optional(choice($.effect_inline, $._effect_block)),
        '}',
    ),
    
    /** 
     * Cannot have effects except as the RHS of an arrow
     * Int
     * Text
     * value_type -> value_type
     * value_type -> {...} value_type
     * value_type -> { ... } ()
     */
    forall: $ => seq($.kw_forall, repeat($.wordy_id), '.'),
    _value_type: $ => seq(
        optional($.forall), 
        $._type1
    ),
    parenthesized: $ => seq('(', $._value_type, ')'),
    _value_type_leaf: $ => choice(
        $.parenthesized,
        $._type_atom,
        $.sequence_type,
    ),
    // Optional, Optional#abc, woot, #abc
    immediate_hash: $ => token.immediate(/#[a-zA-Z0-9]+/),
    // unit: $ => '()',
    
    // TODO refer back to hashes again. Can it also be ##builtin hash?
    _type_atom: $ => choice(
        $._hash_qualified,
        // seq($.wordy_id, optional($.immediate_hash)),
        // seq(/#[0-9a-zA-Z]+/),
        $.unit,
    ),
    // [Int], [A -> B], etc.
    sequence_type: $ => seq(
        '[',
        choice(
            seq($._layout_start, $._value_type, $._layout_end),
            $._value_type,
        ),
        ']',
    ),
    _type1: $ => choice($._arrow, $._type2a),
    _type2a: $ => choice($.delayed, $._type2),
    _type2: $ => seq(
        $._value_type_leaf,
        repeat(choice($._effect_list, $._value_type_leaf)),
    ),
    delayed: $ => seq(
        "'",
        choice($._effect, $._type2a),
    ),
    arrow_symbol: $ => '->',
    
    // { E1, E2, ..., En } T
    _effect: $ => seq($._effect_list, $._type2),
    
    // [{ E1, E2, ..., En }] T
    _computation_type: $ => prec.left(choice($._effect, $._value_type)),
    
    // T -> [{ E1, E2 }] U
    _arrow: $ => seq($._value_type, $.arrow_symbol, $._computation_type),
    
    /**
     * body of an effect/ability declaration:
     * INLINE: name [p1 p2 ... pn] where [constructor, constructor, ...]
     * OR
     * BLOCK: name [p1 p2 ... pn] where
         [constructor]
         [constructor]
         ...
     */
    _ebody: $ => seq(
        field('type_name', $._identifier),
        repeat(field('type_arg', $.wordy_id)),
        $.where,
        choice(
            seq($._layout_start, sep1($._layout_semicolon, $.constructor), $._layout_end),
            sep1(',', $.constructor),
        ),
    ),

    /**
     * Matches the following:
     * - foo : { E1, E2 } T
     * - foo : A -> { E1, E2 } T
     */
    constructor: $ => seq(
        field('name', $.wordy_id),
        ':',
        field('type', choice($._arrow, $._computation_type)),
    ),
    
    /**
     * Top-level entity.
     * unique ability Throw a where
     *   throw: e ->{ Throw e } a
     */
    effect_declaration: $ => seq(
        choice($.structural, $.unique),
        $.ability,
        $._ebody,
    )
}