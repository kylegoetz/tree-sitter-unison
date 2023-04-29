#/usr/bin/env node --trace-warnings --unhandled-rejections=strict

const fs = require('fs')
const Parser = require('web-tree-sitter')

if (process.argv.length < 3) {
  console.log('Usage: script/tree-sitter-parse.js <unison-file..>')
  process.exit(1)
}

Parser.init().then(() => {
  Parser.Language.load('tree-sitter-unison.wasm').then((Unison) => {
    const parser = new Parser
    parser.setLanguage(Unison)
    process.argv.slice(2).forEach(filename => {
      const source = fs.readFileSync(filename, 'utf8')
      const tree = parser.parse(source)
    })
  })
})
