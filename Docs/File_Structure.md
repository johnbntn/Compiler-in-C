# File Structure
In total, I use 15 files for this project. Of those, 11 are C files, 3 are header files, and 1 is the Makefile.
## C Files
The C files can further be separated into scanning, parsing, assembling, and miscellaneous.
### Scanning
Only `scan.c` contains functions that are used for the process of lexical analysis.
### Parsing
`expr.c`: Contains functions that parse expressions.\
`stmt.c`: Contains functions that handle print statements and variable declarations/assignments.\
`sym.c`: Contains functions that handle the creation and management of new variables.\
`tree.c`: Contains functions that determine the format of the AST.
### Assembling
`cgn.c`: Contains functions that create actual assembly code.\
`gen.c`: Contains functions that manage what assembly code is generated, depending on where we are in the AST.
### Miscellaneous
`main.c`: Makes sure that execution environment is correct, also starts the compilation process by scanning in the first token.\
`misc.c`: Contains the match function, which makes sure that the next input token is correct. Also contains error functions.\
`assemble.c`: Makes running the NASM code more straightforward.\
`tester.c`: Tests the compiler.
## Header Files
`data.h`: Contains global variables and information about maximums.\
`decl.h`: Function prototypes.\
`defs.h`: Contains info about tokens and AST nodes.