# Tree sitter for Unison

This is a WIP. Does not pass all tests. Need more tests.

### To do:
- [x] use clause
- [x] pattern matching ([see here](https://github.com/kylegoetz/tree-sitter-unison/tree/patterns))
- [x] where
- [x] destructuring binds (depends on pattern matching)
- [x] record types
- [x] hash-qualifications for identifiers
- [ ] bring terminology more in line with documentation or the `*Parser.hs` terms (`wordy_id` vs `identifier`, `symboly_id` vs `operator`, etc.)
- [x] lazy functionality (`'`, `!`)
- [x] `alias` <-- no current implementation, merely a reserved keyword
- [x] `namespace` <-- no current implementatoin, merely a reserved keyword
- [x] `termLink`
- [x] `typeLink`
- [ ] complex tests using production code
- [ ] test escape sequences in Text literals
- [x] test watch expressions (`test>`)
- [ ] do we need to support lcase, ucase, or both for hashes in base32hex?
- [x] offload hash detection to C scanner bc JS has problems parsing the hash, cycle, and cid correctly.
- [ ] documentation (doc block)
- others?
