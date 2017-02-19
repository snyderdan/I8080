
#ifndef _I8080_CPU_
#  define _I8080_CPU_

#  include <stdint.h>

typedef struct I8080CPU {
	int   counter;
	char *ram;
	void *mmu, *ioports[256];
	short pc, sp;
	char a, c, b, e, d, l, h, f, \
	halt, wr, wait, /* wait = !ready */ \
	int_enabled, int_request, int_instruction;
} __attribute__((packed)) I8080;

#  ifdef __unix__
#    define __cdecl
#   endif

extern I8080 * __cdecl newCPU();
extern void __cdecl initCPU(I8080 *cpu);
extern void __cdecl freeCPU(I8080 *cpu);

extern void __cdecl stepCPU(I8080 *cpu);
extern int  __cdecl executeCycles(I8080 *cpu, int cycleCount);
extern void __cdecl executeInstruction(I8080 *cpu, int instruction); // Pass binary instruction (including operands)
								// Unlike RequestInterrupt() this function can take 2 and 3 byte instructions
extern void __cdecl setMMU(I8080 *, int64_t (*handle)(I8080 *, int)); // set MMU handler. Receives a logical address and return a physical address
extern void __cdecl clearMMU(I8080 *);
extern void __cdecl *getMemory(I8080 *cpu);            // return address of RAM
extern void __cdecl setMemory(I8080 *cpu, void *memory); // Set address of RAM 
/**
 * Notes on memory for the 8080 Emulator:
 *  - Allocating memory and assigning it to the program
 * is the responsibility of the programmer
 *               
 *  - An attempt to address memory above [memory+size] will
 * result in calling the overflow handler (does nothing by default
 * and can be set by the SetOverflowHandler function) and will
 * break the execution of the current instruction.
 * 
 */

extern void __cdecl setIOPort(I8080 *cpu, int portno, void (*handle)(I8080 *instance)); 
/** 
 * Set handle for IO port (portno)
 * Function set as that I/O port are responsible for checking weather the 
 * instruction is input or output and getting the accumulator for outputs
 * as well as setting it for input. 
 * 
 * This instruction should only be used during the configuration of the 
 * CPU and may have undefined side effects if used during CPU execution 
 * 
 * The handle should be a void function that takes a pointer to an I8080 as an argument
 */
extern int __cdecl getIOState(I8080 *); // returns 1 if in output mode or 0 if in input mode
#  define INPUT      0
#  define OUTPUT     1
// Numerous synonyms
#  define writeWire  getIOState
#  define isInput    !writeWire
#  define isOutput   writeWire
#  define inputToCPU isInput
#  define outputFromCPU    isOutput
#  define inputToDevice    isOutput
#  define outputFromDevice isInput

extern int __cdecl getAccumulator(I8080 *cpu); // returns -1 if not WriteWire() else the current
						// value in register A
extern int __cdecl setAccumulator(I8080 *cpu, int); // returns -1 if WriteWire() else the value
						// that register A was set to (only the lowest byte)

#  define INVALID_ACCUMULATOR -1
#  define isValidAccumulator(acc) (acc == INVALID_ACCUMULATOR) ? 0 : 1 // Tests to see if
								// the 'acc' indicates a successful get/set of the accumulator
								// if 0 then the incorrect I/O mode was attempted

// Physical I/O pins
extern void __cdecl requestInterrupt(I8080 *cpu, char instruction);  // pass a one byte instruction
extern int __cdecl interruptEnabled(I8080 *cpu);    // Returns 1 if IR bit is True else False
extern void __cdecl resetCPU(I8080 *cpu);    // clears PC and sets IR bit to False; all other registers remain the same
extern int __cdecl waitState(I8080 *cpu);    // returns 1 if HLT or Ready pin == 0 else 0
extern void __cdecl setReady(I8080 *cpu, int value); // Sets ready pin to value
#  define READY   1
#  define EXECUTE 1
#  define WAIT    0

/** 
 * The following strictly exist to provide more accurate emulation of 
 * external devices but are completely useless as there is no data bus to worry
 * about synchronizing. In order to externally stop the CPU execution use the
 * Ready() function.
 */
static int hold = 0;
#  define setHold(value) hold=value
#  define holdAcknowledged() (hold)
#endif
