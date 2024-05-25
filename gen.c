#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

/// @brief Generate AST by calling assembly language generator functions in correct order
/// @param n starting node 
/// @return result of assembly functions
int genAST(struct ASTnode *n) {
    int leftreg, rightreg;

    //Generate AST left to right recursively
    if (n -> left) leftreg = genAST(n -> left);
    if (n -> right) rightreg = genAST(n -> right);

    //Call correct assembly lang generator function for each AST node
    switch (n -> op) {
        case A_ADD:         return cgadd(leftreg, rightreg);
        case A_SUBTRACT:    return cgsub(leftreg, rightreg);
        case A_MULTIPLY:    return cgmul(leftreg, rightreg);
        case A_DIVIDE:      return cgdiv(leftreg, rightreg);
        case A_INTLIT:      return cgload(n -> intvalue);

        default:
            fprintf(stderr, "Unknown AST operator %d\n", n->op);
            exit(1);
    }
}

void genpreamble() {
  cgpreamble();
}
void genpostamble() {
  cgpostamble();
}
void genfreeregs() {
  freeall_registers();
}
void genprintint(int reg) {
  cgprintint(reg);
}