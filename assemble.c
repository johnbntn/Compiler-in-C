#include "data.h"
#include "defs.h"
#include "decl.h"

void main (int argc, char *argv[]) {
    system("nasm -f elf64 out.s");
    system("cc -no-pie -o out out.o");
}