# Lexer
Lexical analysis is the process of breaking down code into segments called tokens, allowing the computer to process them. Telling the computer what tokens mean allows it to process them.

For my lexer, a file containing:
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

Note that a lexer does not actually tell your computer how to run a program, merely creates the building blocks. Parsing, semantic analysis, and assembling take these tokens and communicate them to the cpu according to a set of rules defined in the parser and semantic analyzer, allowing for the intended output.
## Outline
### Headers
There are three header files, `data.h`, `decl.h`, `defs.h`.

In `data.h`, we define global variables that are going to be used to process and organize data. For example, the variable `InFile` is defined in order to easily track the file being lexically analyzed.

In `decl.h` we define function prototypes.

In `defs.h` we use an `enum` to define different tokens and and a `struct token` to define the general structure of a token. Each element from the `enum` becomes the `int value` in the `token struct`.

### `scan.c `

`scan.c` contains functions that implement the lexical analysis. For example, `int scan(struct token *t)` checks the value of the next character and assigns it to the `token` value in the `struct token` by dereferencing `struct token *t`.