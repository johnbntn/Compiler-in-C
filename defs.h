#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {
    T_PLUS, T_MINUS, T_STAR, T_INLIT, T_SLASH
}

struct token {
    int token;
    int tokenValue;
}