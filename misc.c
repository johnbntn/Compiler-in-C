#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

/// @brief 
/// @param t 
/// @param what 
void match(int t, char *what) {
    if (Token.token == t) {
        scan(&Token);
    } else {
        printf("%s expected on line %d\n", what, Line);
        exit(1);
    }
}

//Make sure T_SEMI is semicolon
void semi(void) {
    match(T_SEMI, ";");
}