#include "Headers/data.h"
#include "Headers/defs.h"
#include "Headers/decl.h"

// List of available registers and their names
static int freereg[4];
static char *reglist[4]= { "r8", "r9", "r10", "r11" };

/// @brief Set all registers as available
void freeall_registers(void)
{
  freereg[0]= freereg[1]= freereg[2]= freereg[3]= 1;
}

/// @brief Allocate free register
/// @return number of register allocated
static int alloc_register(void)
{
  for (int i=0; i<4; i++) {
    if (freereg[i]) {
      freereg[i]= 0;
      return(i);
    }
  }
  fprintf(stderr, "Out of registers!\n");
  exit(1);
}

/// @brief check register is free and then mark it as free in the array
/// @param reg register trying to free
static void free_register(int reg)
{
  if (freereg[reg] != 0) {
    fprintf(stderr, "Error trying to free register %d\n", reg);
    exit(1);
  }
  freereg[reg]= 1;
}

/// @brief print out assembly function preamble
void cgpreamble()
{
  freeall_registers();
  fputs(
	"\tglobal\tmain\n"
	"\textern\tprintf\n"
	"\tsection\t.text\n"
	"LC0:\tdb\t\"%d\",10,0\n"
	"printint:\n"
	"\tpush\trbp\n"
	"\tmov\trbp, rsp\n"
	"\tsub\trsp, 16\n"
	"\tmov\t[rbp-4], edi\n"
	"\tmov\teax, [rbp-4]\n"
	"\tmov\tesi, eax\n"
	"\tlea	rdi, [rel LC0]\n"
	"\tmov	eax, 0\n"
	"\tcall	printf\n"
	"\tnop\n"
	"\tleave\n"
	"\tret\n"
	"\n"
	"main:\n"
	"\tpush\trbp\n"
	"\tmov	rbp, rsp\n",
  Outfile);
}

/// @brief Print out assembly postamble
void cgpostamble()
{
  fputs(
	"\tmov	eax, 0\n"
	"\tpop	rbp\n"
	"\tret\n",
  Outfile);
}

/// @brief Load int value into register
/// @param value to be loaded 
/// @return Register number
int cgload(int value) {

  // Get a new register
  int r= alloc_register();

  // Print out the code to initialise it
  fprintf(Outfile, "\tmov\t%s, %d\n", reglist[r], value);
  return(r);
}

// Add two registers together and return
// the number of the register with the result
int cgadd(int r1, int r2) {
  fprintf(Outfile, "\tadd\t%s, %s\n", reglist[r2], reglist[r1]);
  free_register(r1);
  return(r2);
}

/// @brief Subtract second register from first and place result in fist register
/// @param r1
/// @param r2
/// @return Number of the register with the result
int cgsub(int r1, int r2) {
  fprintf(Outfile, "\tsub\t%s, %s\n", reglist[r1], reglist[r2]);
  free_register(r2);
  return(r1);
}

/// @brief Multiply two registers and place result in another register
/// @param r1
/// @param r2 
/// @return Number of register with the result
int cgmul(int r1, int r2) {
  fprintf(Outfile, "\timul\t%s, %s\n", reglist[r2], reglist[r1]);
  free_register(r1);
  return(r2);
}


/// @brief Divide first register by second and place result in another register
/// @param r1 
/// @param r2 
/// @return Register with result
int cgdiv(int r1, int r2) {
  fprintf(Outfile, "\tmov\trax, %s\n", reglist[r1]);
  fprintf(Outfile, "\tcqo\n");
  fprintf(Outfile, "\tidiv\t%s\n", reglist[r2]);
  fprintf(Outfile, "\tmov\t%s, rax\n", reglist[r1]);
  free_register(r2);
  return(r1);
}



/// @brief Print an integer in a register
/// @param r register to be printed
void cgprintint(int r) {
  fprintf(Outfile, "\tmov\trdi, %s\n", reglist[r]);
  fprintf(Outfile, "\tcall\tprintint\n");
  free_register(r);
}