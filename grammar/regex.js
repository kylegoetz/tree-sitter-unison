const VARID = /[a-zA-Z_\u{1F400}-\u{1FAFF}][a-zA-Z0-9_!'\u{1F400}-\u{1FAFF}]*/u

module.exports = {
  namespace: new RegExp(`\\.?(${VARID.source}\\.)+`, 'u'),
  varid: VARID,
  lowercase_varid: new RegExp(VARID.source.toLowerCase(), 'u'),
}