# Code Assembly
Assembly is the process of turning parsed tokens into assembly code so that it can be executed. For this compiler, I'm generating x86-64 code.

## Abstraction in `gen.c`
All functions that pipe NASM code to an Outfile are contained in the function `cgn.c`. However, all of these functions can only be called by the functions contained in `gen.c`, which can be called from anywhere. This creates a more easily understood control flow.
## Code Generation
Assembly code works by transferring data in and out of registers. This means that you have to keep track of what values are held in what registers.
### Pre/Postamble 
Before anything else, the compiler generates preamble NASM code. This involves setting up global variables and a printint function. The printint function works by placing `%d\n` into the `rdi` register and then the integer to be printed in the `esi` register; before the call, 0 is placed in `eax`. All of which is required by the x86-64 System V ABI. There's also postamble code that exits the program.
### Registers
The compiler uses four temporary registers: `r8, r9, r10, r11`. As well as stack registers and registers necessary for x86-64 calling conventions. The file `cgn.c` contains functions that keep track of whether a register is available for use or not.
### Variables
Variables are created by using the `common` command, which allows a string to reference a size of memory. In this compiler, all variables are 8 bytes long. To assign values to variables, values are moved into registers and then those registers are moved into the global variables.
