#include "data.h"
#include "defs.h"
#include "decl.h"

void print_statement(void) {
    struct ASTnode *tree;
    int reg;

    // Match a 'print' as the first token
    match(T_PRINT, "print");

    // Parse the following expression and generate the assembly code
    tree = binexpr(0);
    reg = genAST(tree, -1);
    genprintint(reg);
    genfreeregs();

    // Match the following semicolon
    semi();
}

void assignment_statement(void) {
    struct ASTnode *left, *right, *tree;
    int id;

    // Ensure we have an identifier
    ident();

    // Check it's been defined then make a leaf node for it
    if ((id = findglob(Text)) == -1) {
        fatals("Undeclared variable", Text);
    }
    right = mkastleaf(A_LVIDENT, id);

    // Ensure we have an equals sign
    match(T_EQUALS, "=");

    // Parse the following expression
    left = binexpr(0);

    // Make an assignment AST tree
    tree = mkastnode(A_ASSIGN, left, right, 0);

    // Generate the assembly code for the assignment
    genAST(tree, -1);
    genfreeregs();

    // Match the following semicolon
    semi();
}

void var_declaration(void) {

    match(T_INT, "int");
    ident();
    addglob(Text);
    genglobsym(Text);
    semi();
}

void statements(void) {
    struct ASTnode *tree;
    int reg;

    while (1) {
        switch (Token.token) {
        case T_PRINT:
            print_statement();
            break;
        case T_INT:
            var_declaration();
            break;
        case T_IDENT:
            assignment_statement();
            break;
        case T_EOF:
            return;
        default:
            fatald("Syntax error, token", Token.token);
            }
    }
}