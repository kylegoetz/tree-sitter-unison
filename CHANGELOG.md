# Change Log

All notable changes to this project will be documented in this file.

## [2.0.0] - 2024-10-05

### Fixed

- #82 - allow doc block wherever
- #84 - Symbols in paths now work
- #85 - built-ins are now just `built_in_hash` without any child nodes

### Changed

- `wordy_id` now called `regular_identifier` in most places
- `namespace` now includes `path` and optional `regular_identifier`/`operator` child nodes
- `wordy_id` has been changed to `ability_name` and `type_argument` in ability declarations
- `wordy_id` has been changed to `constructor_name` in ability constructors
- `colon` has been added as a named token in ability constructors
- `wordy_id` has been changed to `field_name` in record fields

## [1.1.4] - 2024-04-25

### Fixed

- #73 - Removed bounds checks (`atof`) for int, nat, float and now use JS rather than C to parse

## [1.1.3] - 2024-04-24

### Fixed

- #71 - Hashes now only validate for proper base32hex (i.e., fail if a letter after 'v' appears in the hash)
- #67 - fprintf conditionally included in scanner so WASM builds succeed

## [1.1.1] - 2024-04-13

### Fixed

- #57 - strncat instead of strcat to support WASM

## [1.1.0] - 2024-02-02

### Added

- #54 - Unison now defaults to "unique" for abilities and types, so we allow a tacit `unique` for them in the grammar
- #52 - Unison allows hex literals for natural numbers. This was not supported until [Felipe Guerreiro](https://github.com/fmguerreiro) filed a PR, and I got off my lazy kiester to test and merge it in.

### Fixed

- #55 - There were two sets of `unique` and `structural` keywords in the grammar, so they've been consolidated now. This might require updates to anything relying on the output of "unique_kw" and "structural_kw" for types, as they now output to "unique" and "structural" like abilities always have. Thank you to [@zetashift](https://github.com/zetashift) for reporting this!

## [1.0.2] - 2023-07-28

### Fixes

- #39 - term declarations now take both path-prefixed wordy ids as well as path-prefixed symboly ids that are in parentheses.

## [1.0.1] - 2023-07-26

### Fixes

- Previous version allowed documentation blocks anywhere. They are only supposed to be allowed right before term definitions (as "anonymous documentation blocks") or as a type of expression.

## [1.0.0] - 2023-06-28

All Unison entities parsed, but doc blocks are only parsed as a doc block without breaking them down further into sections, etc.
