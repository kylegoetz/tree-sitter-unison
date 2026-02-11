# Change Log

All notable changes to this project will be documented in this file.

## [3.0.0] - 2026-02-

### Fixed

- GH-144 - guarded blocks layout works
- GH-145 - effect pattern matching of form { a -> b } parse
- GH-146 - sometimes destructuring bind at EOL not recognized
- GH-147 - case where in-line comment not recognized
- GH-151 - destructuring bind of form `a@(...)` parses
- GH-152 - pattern matching RHS allows use clause anywhere
- GH-154 - pattern LHS can be made up of comma-delimited patterns
- GH-155 - match/with does not require any patterns
- GH-156 - if/then/else blocks allow use clause anywhere
- GH-157 - `if_exp` layout issues
- GH-160 - pattern case can have as notation
- do block with destructuring bind works

### New

- The "->" in an effect is now a named node, `effect_arrow`.
- A `var_or_nullary_ctor` may have a new child node, `regular_identifier`
- the formerly anonymous match/with node is now named: `match_expression`
- the formerly anonymous lambda pattern matching (cases ...) is now named `match_expression_lambda`
- `exp_if` now wraps the if/then/else blocks in `if_block`, `then_block`, and `else_block`
- some `var_or_nullary_ctor` will be seen as `var_or_as` now (prompts future change of the former to just `nullary_ctor`)
- `pattern` has been renamed `pattern_case` to reflect Unison terminology and to allow an anonymous node to be renamed `pattern` (the children of a pattern's LHS, formerly calld `_pattern_candidates`)
- The above means that `destructuring_bind`s will often have `pattern` now wrapping `var_or_nullary_ctor`. The same goes for descendants of `effect_pattern`.

## [2.1.3] - 2026-02-04

### Fixed

- GH-141 - use clauses can occuur anywhere in a block, not just the first line

## [2.1.2] - 2026-02-04

### Fixed

- GH-140 - function literals allow multiple parameters

## [2.1.1] - 2026-02-02

### Fixed

- GH-139 - regex no longer fails for identifiers containing an underscore followed by numbers in their path

## [2.1.0] - 2026-01-27

### Fixed

- GH-134 - multiline literals handled correctly when opened by more than three double quotation marks

### New

- GH-114 - namespace pragma (@skykanin)
- GH-135 - doc block can precede use_clause now, and such a use_clause is wrapped in `documented_use_clause` with existing `doc_block` and `use_clause` children (@fmguerreiro)

## [2.0.1] - 2025-03-05

### Fixed

- GH-121 - improved match/case block layout end detection

## [2.0.0] - 2024-11-06

### New

- GH-50 - term rewrite blocks, including adding
  - reserved keyword leafs `term` ("term"), `signature` ("signature"), `rewrite` ("rewrite"), `dot` ("."), and `rewrite_arrow` ("==>")
  - named nodes `rewrite_case`, `rewrite_term`, `rewrite_type`, and `rewrite_block`. The fourth is an entire rewrite block beginning with `@rewrite`, and it, inter alia, includes at least one of the other three as a child node
- GH-85 - a built-in hash is a single unit, no longer `*PATH_SEGMENT . REGULAR_ID`
- GH-86 - add `force`, in which `x()` is parsed as `(force (regular_identifier) (unit))`
- GH-90 - liberal recognition of `_layout_semicolon` at ends of lines with equal indentation levels, which helps with parsing in many places
- GH-91 - infix symops can have namespace/path prefix

### Fixed

- GH-80 - parsing folds of more than three hyphens
- GH-84 - Symbols in paths now work
- GH-85 - built-ins are now just `built_in_hash` without any child nodes
- GH-92 - test watch expressions can only have `test` and `test.io` as prefix for `>`
- GH-95 - doc blocks can only appear two ways (syntax sugar before a top-level `binding` and in similar places as a `literal`)
- GH-96 - enable built-in hashes
- GH-97 - separate a term `binding` from a top-level `binding` (latter has the doc block syntax sugar)
- GH-98 - +4 is correctly tokenized as `int` rather than `symboly_id . nat`
- #?? - pattern matching guards now are part of a layouted block
- GH-103 - `match` scrutinee now correctly categorized as `_term` rather than `_expression`
- GH-105 - two-char symbols ending in `&` or `|` now parse as two-char symbols

### Changed

- `wordy_id` now called `regular_identifier` in most places
- `namespace` now includes `path` and optional `regular_identifier`/`operator` child nodes
- `wordy_id` has been changed to `ability_name` and `type_argument` in ability declarations
- `wordy_id` has been changed to `constructor_name` in ability constructors
- `colon` has been added as a named token in ability constructors
- `wordy_id` has been changed to `field_name` in record fields
- `guard` has been renamed `guarded_block`
- the actual guard of a guarded block is its own node now, called `guard`, and can be the parent of various nodes
- `ability_pattern` has been renamed `effect_pattern` to be in line with UCM codebase terminology
- `effect_pattern` now contains either a (new) `effect_pure` or `effect_bind`. The difference is as that between `{ x }` and `{ x -> y }`, respectively
- `constructor_or_variable_pattern` has been bifurcated into `ctor` and `var_or_as` because they have subtly different rules than anticipated previously so cannot be handled together
- the list infix patterns have been flattened, so for example `init_last_tail_pattern ( left side . right side )` is now `left side . snoc . right side`. The sructure can be deduced, while now the infix operator is a named node. Another example is `head_tail_list_pattern (left . right)` is now `left cons right`.
- a prefix `operator` (which is surrounded by parentheses) is now called `prefix_operator` instead of just `operator`
- the introduction of named nodes for `[`, `]`, `(`, and `)`: `open_bracket`, `close_bracket`, `open_parens`, `close_parens`
- the introduction of named node `comma` in tuple patterns

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
