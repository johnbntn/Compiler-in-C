#include "data.h"
#include "defs.h"
#include "decl.h"

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

//match ident
void ident(void) {
    match(T_IDENT, "identifier");
}

// Print out fatal messages
void fatal(char *s) {
    fprintf(stdout, "%s on line %d\n", s, Line); exit(1);
}

void fatals(char *s1, char *s2) {
    fprintf(stdout, "%s:%s on line %d\n", s1, s2, Line); exit(1);
}

void fatald(char *s, int d) {
    fprintf(stdout, "%s:%d on line %d\n", s, d, Line); exit(1);
}

void fatalc(char *s, int c) {
    fprintf(stdout, "%s: %c on line %d\n", s, c, Line); exit(1);
}