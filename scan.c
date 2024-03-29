#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"
#include <stdio.h>

// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

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

static void putback(int c) {
  Putback = c;
}

static int skip(void){
    int c;

    c = next();

    //check for whitespace characters
    while (' ' == c || '\n' == c || '\t' == c || '\r' == c || '\v' == c || '\f' == c){
        c = next();
    }

    return c; 
}

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

int scan(struct token *t) {
    int c;

    c = skip();

    //check character value and assign it a value
    switch(c) {
        case EOF:
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