#include "data.h"
#include "defs.h"
#include "decl.h"

void var_declaration(void) {

    match(T_INT, "int");
    ident();
    addglob(Text);
    genglobsym(Text);
    semi();
} 