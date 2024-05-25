#include <stdio.h>

#ifndef extern_
 #define extern_ extern
#endif

extern_ int     Line;
extern_ int     Putback;
extern_ FILE	*Infile;
extern_ FILE		*Outfile;
extern_ struct token    Token;

#define TEXTLEN 512 //Line length limit
extern_ char Text[TEXTLEN + 1];