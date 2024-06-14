#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Tokens
enum {
  T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_EQUALS, T_IDENT,

  //keywords
  T_PRINT, T_INT
};

// Token structure
struct token {
  int token;
  int intValue;
};

// AST node types
enum {
  A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT, 
  A_LVIDENT, A_ASSIGN, A_IDENT
};

//AST Node structure
struct ASTnode {
  int op;
  struct ASTnode *left;
  struct ASTnode *right;
  union {
    int intvalue;
    int id;
  } v;
};
