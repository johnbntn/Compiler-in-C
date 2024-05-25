#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

void statements(void) {
    struct ASTnode *tree;
    int reg;

    while (1) {
        //match first token as print
        match(T_PRINT, "print");

        tree = binexpr(0);
        reg = genAST(tree);
        genprintint(reg);

        //match at semicolon and stop at EOF
        semi();
        if (Token.token == T_EOF) {
            return;
        }
    }
}