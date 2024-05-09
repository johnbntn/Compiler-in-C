# Lexer
## Outline
### Headers
There are three header files, `data.h`, `decl.h`, `defs.h`.

In `data.h`, we define global variables that are going to be used to process and organize data. For example, the variable `InFile` is defined in order to easily track the file being lexically analyzed.

In `decl.h` we define function prototypes.

In `defs.h` we use an `enum` to define different tokens and and a `struct token` to define the general structure of a token. Each element from the `enum` becomes the `int value` in the `token struct`.

### `scan.c `

`scan.c` contains functions that implement the lexical analysis. For example, `int scan(struct token *t)` checks the value of the next character and assigns it to the `token` value in the `struct token` by dereferencing `struct token *t`.