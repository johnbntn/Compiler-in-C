# Compiler-in-C

I'll be making a compiler using C that will compile a simple programming language that I'll be calling Little C.
Compilers can be thought of as 4 directives:
1. Lexical Analysis (lexer)
2. Parsing (parser)
3. Assembling (assembler)

## Usage
To use the compiler run:
`./jlcc /PathToFile`
The assembly code will be in the `out.s` file. To generate a binary, run:
`./asm out.s`
## Testing
To test the compiler with the tests in `Tests/Units` run `./tester`. To add tests, edit the `tester.c` file and run `make tester` to recompiler.

For more information on the language, refer to the [documentation](Docs/)