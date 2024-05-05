#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

//general function to create AST nodes
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue) {

    struct ASTnode *n;

    n = (struct ASTnode *) malloc(sizeof(struct ASTnode));

    //malloc an AST node
    if (n == NULL) {
        fprintf(stderr, "Error w/ malloc in mkastnode");
        exit(1);
    }

    //fill struct with values
    n -> op = op;
    n -> left = left;
    n -> right = right;
    n -> intvalue = intvalue;

    return n;
}

//function to create leaf nodes
struct ASTnode *mkastleaf(int op, int intvalue) {
    return mkastnode(op, NULL, NULL, intvalue);
}

//function to create nodes with only 1 child
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue) {
    return mkastnode(op, left, NULL, intvalue);
}