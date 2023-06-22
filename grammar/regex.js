const VARID = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u

const SYMBOLY_ID_START_EQ = /=[!$%^&*-=+<>.~\\/|:]+/
const SYMBOLY_ID_NO_START_EQ = /[!$%^&*-+<>.~\\/|:][!$%^&*-=+<>.~\\/|:]+/

module.exports = {
  path: new RegExp(`\\.?(${VARID.source}\\.)+`, 'u'),
  namespace: new RegExp(`\\.?(${VARID.source}\\.)*${VARID.source}`, 'u'),
  varid: VARID,
  lowercase_varid: new RegExp(VARID.source.toLowerCase(), 'u'),
  // symboly_id: /[!$%^&*-=+<>.~\\/|:]+/,
  symboly_id: new RegExp(`(${SYMBOLY_ID_START_EQ.source})|(${SYMBOLY_ID_NO_START_EQ.source})`)
}