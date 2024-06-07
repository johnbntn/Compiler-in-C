#include "data.h"
#include "defs.h"
#include "decl.h"

/// @brief Generate AST by calling assembly language generator functions in correct order
/// @param n starting node 
/// @return result of assembly functions
int genAST(struct ASTnode *n, int reg) {
    int leftreg, rightreg;

    //Generate AST left to right recursively
    if (n -> left) leftreg = genAST(n -> left, -1);
    if (n -> right) rightreg = genAST(n -> right, leftreg);

    //Call correct assembly lang generator function for each AST node
    switch (n -> op) {
        case A_ADD:         return cgadd(leftreg, rightreg);
        case A_SUBTRACT:    return cgsub(leftreg, rightreg);
        case A_MULTIPLY:    return cgmul(leftreg, rightreg);
        case A_DIVIDE:      return cgdiv(leftreg, rightreg);
        case A_INTLIT: return (cgloadint(n->v.intvalue));
        case A_IDENT: return (cgloadglob(Gsym[n->v.id].name));
        case A_LVIDENT: return (cgstorglob(reg, Gsym[n->v.id].name));
        case A_ASSIGN: return rightreg; // The work has already been done, return the result
        default:
          fatald("Unknown AST operator", n->op);
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

void genglobsym(char *s) { 
  cgglobsym(s); 
}