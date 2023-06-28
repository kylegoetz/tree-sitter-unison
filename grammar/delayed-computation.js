module.exports = {
    delay_quote: $ => seq(
        '\'',
        $._term_leaf,
    ),

    delay_block: $ => seq($.do, $._block),

    bang: $ => seq('!', $._term_leaf),

    _term_leaf: $ => choice(
        $._hash_qualified,
        $.literal_text,
        $.literal_char,
        $.float,
        $.nat,
        $.int,
        $.literal_byte,
        $.literal_boolean,
        $.literal_termlink,
        $.literal_typelink,
        $.tuple_or_parenthesized,
        $._keyword_block,
        // list term?? TODO what is this?
        /**
         * list = Parser.seq Term.list -- []
         * term = term2
         * term2 = lam term2 <|> term3
         * term3 = infixAppOrBooleanOp ; optional (reserved ":" *> TypeParser.computationType)
         */
        $.delay_quote,
        $.delay_block,
        $.bang,
        $.doc_block,
        $.doc2_block,
    ),

    _keyword_block: $ => choice(
        $.exp_let,
        $.handler,
        $.exp_if,
        $._pattern_matching, // this is match and lam case
    )
}