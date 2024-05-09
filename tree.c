#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

/// @brief Create ASTnode with parameter values
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

/// @brief Create leaf node
struct ASTnode *mkastleaf(int op, int intvalue) {
    return mkastnode(op, NULL, NULL, intvalue);
}

/// @brief Create node with only one child
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue) {
    return mkastnode(op, left, NULL, intvalue);
}