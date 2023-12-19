#include "data.h"
#include "defs.h"
#include "decl.h"
#include <stdio.h>

static int next(void){
    int c;

    if (Putback){
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);

    if ("\n" == c){
        Line++;
        return c;
    }
}

static void putback(int c) {
  Putback = c;
}

static int skip(void){
    int c;

    c = next();

    while (" " == c || "\n" == c || "\t" == c || "\r" == c || "\v" == c || "\f" == c){
        c = next();
    }

    return c; 
}

int scan(struct token *t) {
    int c;

    c = skip();

    switch(c){
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
            printf("Unrecognizable token %c on line %d", c, Line);
            exit(1);

    return 1;
    }
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

// Return the position of character c
// in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}