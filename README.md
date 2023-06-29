# Tree sitter for Unison

This tree sitter grammar uses some logic borrowed from the Haskell tree sitter grammar, particularly the way it handles indentation tracking for code blocks.

Every feature of the Unison language is implemented here.

If you have recommendations for improvements, create an issue, please. Thank you!

* [2023-06-28] v1 released. All Unison entities parsed, but doc blocks are only parsed as a doc block without breaking them down further into sections, etc.