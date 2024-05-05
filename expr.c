#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

//convert tokens to AST nodes
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
//create AST node tree recursively
struct ASTnode *binexpr(void) {

    struct ASTnode *n, *left, *right;
    int nodetype;

    //get int_lit on left and scan
    left = primary();

    //if at EOF, just return left leaf
    if (Token.token == EOF) return left;

    //convert token to ast node
    nodetype = arithop(Token.token);

    //recursively make the right node
    right = binexpr();

    //once recursion is done (reached EOF), create tree
    n = mkastnode(nodetype, left, right, 0);
    return n;
}