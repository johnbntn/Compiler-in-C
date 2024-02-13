# Compiler-in-C

I'll be making a compiler using C that will compile a simple programming language.
Compilers can be thought of as 3 directives:
1. Lexical Analysis (lexer)
2. Parsing (parser)
3. Assembling (assembler)

As of right now, I have created a basic lexer that recognizes arithmetic operators +,-,*,/ and integers.

## Lexical Analysis

Lexical analysis is the process of breaking down code into segments called tokens, allowing the computer to process them. Telling the computer what tokens mean allows it to process them.

A file containing:
~~~
 4 +
57
*
3 / 8
~~~

Will output:
~~~
Token intlit, value 4
Token +
Token intlit, value 57
Token *
Token intlit, value 3
Token /
Token intlit, value 8
~~~

Note that a lexer does not actually tell your computer how to run a program, merely creates the building blocks. Parsing and assembling take these tokens and communicate them to the cpu according to a set of rules defined in the parser, allowing for the intended output.