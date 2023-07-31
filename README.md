# Tree sitter for Unison

This tree sitter grammar uses some logic borrowed from the Haskell tree sitter grammar, particularly the way it handles indentation tracking for code blocks.

Every feature of the Unison language is implemented here.

If you have recommendations for improvements, create an issue, please. Thank you!

* [2023-07-28] v1.0.2 released.
  * Fixes #39 - term declarations now take both path-prefixed wordy ids as well as path-prefixed symboly ids that are in parentheses.
* [2023-07-26] v1.0.1 released. No idea why previous package version got screwed up and labeled as 0.9.x. Previous version allowed documentation blocks anywhere. They are only supposed to be allowed right before term definitions (as "anonymous documentation blocks") or as a type of expression.
* [2023-06-28] v1 released. All Unison entities parsed, but doc blocks are only parsed as a doc block without breaking them down further into sections, etc.