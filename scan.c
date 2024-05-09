#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"
#include <stdio.h>

/// @brief Return the position of character in string s, or -1 if c not found
/// @param s string to be searched
/// @param c char to be found
/// @return position in string
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

/// @brief Get next character in file or keep character if Putback exists
/// @param
/// @return next char
static int next(void){
    int c;

    //check if character should be putback
    if (Putback){
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);

    if ('\n' == c){
        Line++;
    }
    return c;
}

/// @brief Putback unwanted character
/// @param c 
static void putback(int c) {
  Putback = c;
}

/// @brief Remove any whitespace
/// @param  
/// @return first non-whitespace char
static int skip(void){
    int c;

    c = next();

    //check for whitespace characters
    while (' ' == c || '\n' == c || '\t' == c || '\r' == c || '\v' == c || '\f' == c){
        c = next();
    }

    return c; 
}

/// @brief Create integer literal
/// @param c: integer
/// @return integer literal
static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}

/// @brief Get next token in file
/// @param t pointer to token struct
/// @return next token
int scan(struct token *t) {
    int c;

    c = skip();

    //check character value and assign it a value
    switch(c) {
        case EOF:
            t -> token = T_EOF;
            return 0;
        case '+':
            t -> token = T_PLUS;
            break;
        case '-':
            t -> token = T_MINUS;
            break;
        case '*':
            t -> token = T_STAR;
            break;
        case '/':
            t -> token = T_SLASH;
            break;
        default:
            if (isdigit(c)) {
                t -> intValue = scanint(c);
                t -> token = T_INTLIT;
                break;
            }
            printf("Unrecognizable token %c on line %d\n", c, Line);
            exit(1);

    }
    return 1;
}