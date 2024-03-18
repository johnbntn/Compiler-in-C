# Lexer
## Outline
### Headers
There are three header files, `data.h`, `decl.h`, `defs.h`.

In `data.h`, we define global variables that are going to be used to process and organize data. For example, the variable `InFile` is defined in order to easily track the file being lexically analyzed.

In `decl.h` we define function prototypes.

In `defs.h` we use an `enum` to define different tokens and and a `struct token` to define the general structure of a token. Each element from the `enum` becomes the `int value` in the `token struct`.

### `scan.c `

`scan.c` contains functions that implement the lexical analysis. For example, `int scan(struct token *t)` checks the value of the next character and assigns it to the `token` value in the `struct token` by dereferencing `struct token *t`.

### `main.c`

`main.c` organizes the output of `scan.c`. By having an array of valid tokens that matches the order of the `enum`, `main.c` is able to output the correct token by printing `tokstr[T.token]`.

## Usage

To use the scanner:
1. Fork and clone this repository onto your personal computer
2. Type `make` into your terminal at correct location
3. type `scanner /PathToFile/File`

Testing:
- Execute `make test`

Cleaning
- Execute `make clean`

## Testing

This lexer uses assert statements to compare expected output to actual output. This is done in the file `tests.c`.

### Making Your Own Tests
1. Create a sample file in the `/Tests` directory. This should be named `lexTest[n]_[Type]` where `n` is the next number and `Type` is a short descriptor of what you're testing.
2. Create an expected output string under the `//Correct Test Outputs` comments
3. Add a `content = NULL` line under the last output test
4. Add your own test using the following structure:
~~~ C
    fp = popen("./scanner Tests/lexTest[n]_[Type]", "r");
    stringMaker();
    assert(!strcmp(lexTest[n]Output, content));
    printf("lexTest[n] PASSED\n");
~~~
5. Execute `make test` in your terminal