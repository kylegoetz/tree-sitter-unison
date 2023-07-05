const VARID = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u

const SYMBOLY_LIST = '!$%^&*-=+<>.~\\/|:'

// `=` and `|` are not operators
const ONE_SYMBOL = /[$%^&*-+<>.~\\/:]/

// `||` and `&&` and `->` are not operators
const TWO_SYMBOL_NO_BOOL = /(-[!$%^&*-=+<.~\\/|:])|(&[!$%^*-=+<>.~\\/|:])|(\|[!$%^&*-=+<>.~\\/:])|[!$%^&*-=+<>.~\\/|:]{2}/

// anything 3+ symbols is an operator
const THREE_SYMBOL_OR_MORE = /[!$%^&*-=+<>.~\\/|:]{3,}/

module.exports = {
  path: new RegExp(`\\.?(${VARID.source}\\.)+`, 'u'),
  namespace: new RegExp(`\\.?(${VARID.source}\\.)*${VARID.source}`, 'u'),
  varid: VARID,
  lowercase_varid: new RegExp(VARID.source.toLowerCase(), 'u'),
  symboly_id: new RegExp(`(${ONE_SYMBOL.source})|(${TWO_SYMBOL_NO_BOOL.source})|(${THREE_SYMBOL_OR_MORE.source})`),  
}