const { KEYWORD } = require('./precedences')

module.exports = {
    handle: $ => prec(KEYWORD, 'handle'),
    with: $ => prec(KEYWORD, 'with'),
    handler: $ => seq(
        $.handle,
        $._block,
        $.with,
        $._block,
    )
}