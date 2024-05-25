#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

/// @brief convert tokens to AST node ops
/// @param tok: token from lexer
/// @return Element in AST Node enum
int arithop(int tok){
    switch(tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}

static int OpPrec[] = {0, 10, 10, 20, 20, 0}; //precedence for each token

/// @brief Get precedence of token and find errors
/// @param tok token
/// @return precedence of token
static int op_precedence(int tokentype) {
    int prec = OpPrec[tokentype];

    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
        exit(1);
    }
  return prec;
}

/// @brief Parse primary factor and return it in an AST leaf
/// @param void
/// @return pointer to AST node containing primary factor
static struct ASTnode *primary(void) {
    
    //create ASTnode to hold intlit
    struct ASTnode *n;

    //for intlit, make leaf and scan next token, otherwise error
    switch (Token.token) {
        case(T_INTLIT):
            n = mkastleaf(A_INTLIT, Token.intValue);
            scan(&Token);
            return n;
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
}

/// @brief Create AST tree where root is operator
/// @param ptp previous token's precedence (called w/ 0)
/// @return AST node pointer
struct ASTnode *binexpr(int ptp) {

    struct ASTnode *left, *right;
    int tokentype;

    //get int_lit on left and scan
    left = primary();

    tokentype = Token.token; //make tokentype the current token

    //if at semicolon, return left leaf
    if (Token.token == T_SEMI) return left;

    while (op_precedence(tokentype) > ptp) {
        scan(&Token);

        right = binexpr(OpPrec[tokentype]);

        left = mkastnode(arithop(tokentype), left, right, 0);

        tokentype = Token.token;

        if (tokentype == T_SEMI) return left;
    }

    return left;
}