#include "data.h"
#include "defs.h"
#include "decl.h"

static int Globs = 0;                   // Position of next free global symbol slot

/// @brief find variable in table
/// @param s variable to be found
/// @return index if found, -1 if not
int findglob(char *s) {
    int i;

    for (i = 0; i < Globs; i++) {
        if (*s == *Gsym[i].name && !strcmp(s, Gsym[i].name)) return i;
    }
    return -1;
}

/// @brief Find unused index in symbol table
/// @return index
static int newglob(void) {
    int p;

    if ((p = Globs++) >= NSYMBOLS) {
        fatal("Too many global symbols");
    }
    return p;
}

/// @brief create new entry in symbol table
/// @param name of global variable
/// @return position in symbol table
int addglob(char *name) {
    int y;

    // If this is already in the symbol table, return the existing slot
    if ((y = findglob(name)) != -1)
        return (y);

    // Otherwise get a new slot, fill it in and return the slot number
    y = newglob();
    Gsym[y].name = strdup(name);
    return (y);
}