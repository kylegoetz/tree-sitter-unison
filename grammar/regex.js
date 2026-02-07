const composeRegex = (...res) =>
  new RegExp(res.map(_ => `(${_.source})`).join('|'), 'u')

//1F400 and 1FAFF

// id = /[_a-z\p{Emoji}][_!'a-z\p{Emoji}]*/

const varid = /[_a-z\u{1f400}-\u{1faff}]([_!'a-z0-9\u{1f400}-\u{1faff}])*/iu
const VARID = varid
const LCASE_VARID = /[_a-z\u{1f400}-\u{1faff}][_!'a-z0-9\u{1f400}-\u{1faff}]*/u
// const VARID = new RegExp("[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*", "u")

// `=` and `|` and `!` are not operators
const ONE_SYMBOL = /[$%^&*\-+<>~\\\/:]/

const SYM_CLASS_NO_PIPE = '[!$%^&*\-=+<>~\\\/:]'

// `||` and `&&` and `->` are not operators
const TWO_SYMBOL_MINUS_NOT_ARROW = /-[!$%^&*\-=+<~\\\/|:]/
const TWO_SYMBOL_AND_NOT_DOUBLEAND = /&[!$%^*\-=+<>~\\\/|:]/
const TWO_SYMBOL_AND_NOT_DOUBLEAND2 = /[!$%^*\-=+<>~\\\/|:]&/
const TWO_SYMBOL_OR_NOT_DOUBLEOR = /\|[!$%^&*\-=+<>~\\\/:]/
const TWO_SYMBOL_OR_NOT_DOUBLEOR2 = /[!$%^&*\-=+<>~\\\/:]\|/
const TWO_SYMBOL_REST = /[!$%^*=+<>~\\\/:]{2}/
const TWO_SYMBOL = composeRegex(
  TWO_SYMBOL_MINUS_NOT_ARROW,
  TWO_SYMBOL_AND_NOT_DOUBLEAND,
  TWO_SYMBOL_AND_NOT_DOUBLEAND2,
  TWO_SYMBOL_OR_NOT_DOUBLEOR,
  TWO_SYMBOL_OR_NOT_DOUBLEOR2,
  TWO_SYMBOL_REST,
)
// anything 3+ symbols is an operator
const THREE_SYMBOL_OR_MORE = /[!$%^&*\-=+<>~\\/|:]{3,}/
// const SYMBOLIC_PATH_SEGMENT = /[!$%^&*\-=+<>~\\/|:]{3,}/ ///[!$%^&*\-+:]+/
const SYMBOLIC_PATH_SEGMENT = composeRegex(
  ONE_SYMBOL,
  TWO_SYMBOL,
  THREE_SYMBOL_OR_MORE,
)

// const NON_TERMINAL_PATH_SEGMENT = /[+]/ //ONE_SYMBOL  // composeRegex(/*VARID,*/ SYMBOLIC_PATH_SEGMENT) //SYMBOLIC_PATH_SEGMENT //composeRegex([WORDY_PATH_SEGMENT, SYMBOLIC_PATH_SEGMENT])

// const PATH = new RegExp(`\.?((${NON_TERMINAL_PATH_SEGMENT.source})\.){1,}`, 'u') // new RegExp(NON_TERMINAL_PATH_SEGMENT.source + '.') //new RegExp(`\.?((${NON_TERMINAL_PATH_SEGMENT.source})\.){1,}`, 'u')
// const NON_TERMINAL_PATH_SEGMENT = /foo/
const NON_TERMINAL_PATH_SEGMENT = composeRegex(VARID, SYMBOLIC_PATH_SEGMENT)
const path =
  /\.?((([_a-zA-Z\u{1f400}-\u{1faff}][_!'a-zA-Z0-9\u{1f400}-\u{1faff}]+)|([$%^&*\-+<>~\\\/:])|(-[!$%^&*\-=+<~\\\/|:])|([!$%^*=+<>~\\\/:]{2})|(&[!$%^*\-=+<>~\\\/|:])|(\|[!$%^&*\-=+<>~\\\/:])|([!$%^&*\-=+<>~\\/|:]{3,}))\.)+/u

module.exports = {
  path,
  varid,
  lowercase_varid: LCASE_VARID,
  symboly_id: SYMBOLIC_PATH_SEGMENT,
}
