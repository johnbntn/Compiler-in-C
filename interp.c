#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

static char *ASTop[] = { "+", "-", "*", "/" };

/// @brief Recursively iterate through AST starting at a node
/// @param n: node to parse from (going to be initially called with root)
/// @return parsed value
int interpretAST(struct ASTnode *n) {
    int leftval, rightval;

    if (n -> left) leftval = interpretAST(n -> left);
    if (n -> right) rightval = interpretAST(n -> right);

      // Debug: Print what we are about to do
    if (n->op == A_INTLIT)
        printf("int %d\n", n->intvalue);
    else
        printf("%d %s %d\n", leftval, ASTop[n->op], rightval);

    switch (n->op) {
        case A_ADD:
            return (leftval + rightval);
        case A_SUBTRACT:
            return (leftval - rightval);
        case A_MULTIPLY:
            return (leftval * rightval);
        case A_DIVIDE:
            return (leftval / rightval);
        case A_INTLIT:
            return (n->intvalue);
        default:
            fprintf(stderr, "Unknown AST operator %d\n", n->op);
            exit(1);
  }
}