# Lexer
Lexical analysis is the process of breaking down code into segments called tokens, allowing the computer to process them. Telling the computer what tokens mean allows it to process them.

## Tokens
To start the compilation process, a file is organized into a stream of tokens. Initially, there is no grammar checking in this step, the scanner simply checks to see whether each element of the input is a valid token. Here are the list of tokens in `defs.h`:
~~~C
//Tokens
enum {
  T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_EQUALS, T_IDENT,

  //keywords
  T_PRINT, T_INT
};
~~~