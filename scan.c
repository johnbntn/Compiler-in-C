#include "data.h"
#include "defs.h"
#include "decl.h"

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

/// @brief Scan in identifiers
/// @param c next character
/// @param buf buffer holding characters
/// @param lim length limit
/// @return length of buffer
static int scanident(int c, char *buf, int lim) {
    int i = 0;
    
    //chars can be letters, numbers, and underscores
    while (isalpha(c) || isdigit(c) || '_' == c) {

        //store in buf if under length limit
        if (lim - 1 == i) {
            printf("Identifier too long on line %d\n", Line);
            exit(1);
        }
        else if (i < lim - 1 ) {
            buf[i++] = c;
        }
        c = next();
    }

    // We hit a non-valid character, put it back.
    // NUL-terminate the buf[] and return the length
    putback(c);
    buf[i] = '\0';
    return i;
}

/// @brief Recognizes keywords
/// @param s potential keyword
/// @return the keyword's token or a 0
static int keyword(char *s) {
    switch (*s) {
        case 'p':
            if (!strcmp(s, "print")) return T_PRINT;
        break;
        case 'i':
            if (!strcmp(s, "int")) return T_INT;
    }
    return 0;
}

/// @brief Get next token in file
/// @param t pointer to token struct
/// @return next token
int scan(struct token *t) {
    int c, tokentype;

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
        case ';':
            t -> token = T_SEMI;
            break;
        default:

            if (isdigit(c)) {
                t -> intValue = scanint(c);
                t -> token = T_INTLIT;
                break;
            }
            else if (isalpha(c) || '_' == c) {
                
                //read in potential keyword
                scanident(c, Text, TEXTLEN);
                
                //if it's recognized, assign it
                if (tokentype = keyword(Text)) {
                    t -> token = tokentype;
                    break;
                }
                //Not recognized keyword, so must be variable
                t -> token = T_IDENT;
                break;
            }
            printf("Unrecognizable token %c on line %d\n", c, Line);
            exit(1);

    }
    return 1;
}