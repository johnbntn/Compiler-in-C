# Compiler-in-C

I'll be making a compiler using C that will compile a simple programming language that I'll be calling Little C. The compiler will target Intel x86-64 bit architecture. To assemble the code, I use NASM for Ubuntu.

Compilers can be thought of as 3 directives:
1. Lexical Analysis (lexer)
2. Parsing (parser)
3. Assembling (assembler)

## Usage
To use the compiler run:
`./jlcc /PathToFile`
The assembly code will be in the `out.s` file. To generate a binary, run:
`./asm out.s`
## Testing
To test the compiler with the tests in `Tests/Units` run `./tester`. To add tests, edit the `tester.c` file and run `make tester` to recompile.
## Future Updates
In the future, I want to add functionality for Docker.

For more information on the language, refer to the [documentation](Docs/)