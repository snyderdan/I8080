
#ifndef _I8080_CPU_
#  define _I8080_CPU_

#  include <stdint.h>

typedef struct I8080CPU {
	uint64_t   counter;
	uint8_t *ram;
	void *mmu, *ioports[256];
	uint16_t pc, sp;
	uint8_t a, c, b, e, d, l, h, f,
	halt, wr, hold,
	int_enabled, int_request, int_instruction;
} __attribute__((packed)) I8080;

#  ifdef __unix__
#    define __cdecl
#   endif

/**
 * A I8080 object can be allocated using newCPU() or using malloc(sizeof(I8080))
 * Either is acceptable. When a CPU is allocated, it must be passed to initCPU()
 * in order to ensure predictable operation. Freeing a CPU can be done by 
 * freeCPU() or simply free(). 
 */
extern I8080 * __cdecl newCPU();
extern void __cdecl initCPU(I8080 *cpu);
extern void __cdecl freeCPU(I8080 *cpu);

/**
 * Notes on memory for the 8080 Emulator:
 *  - In order for the emulator to work you must either assign it memory using 
 *    the setMemory() function, or assign it a memory manager using setMMU().
 * 
 *  - If both methods are called with a valid memory pointer and a valid MMU
 *    function, the MMU takes priority. This can be undone with clearMMU().
 * 
 *  - If only setMemory() is used, the default MMU simply uses logical addresses
 *    as indexes into the memory passed as a parameter. 
 * 
 *  - The MMU function must take an I8080 * and an integer representing a logical
 *    address on the 16-bit address bus of the I8080. It must then return a real
 *    address that is within the address space of the process/thread making the
 *    memory request. 
 * 
 */
extern void __cdecl setMMU(I8080 *, void *(*handle)(I8080 *, uint16_t)); // set MMU handler. Receives a logical address and return a physical address
extern void __cdecl clearMMU(I8080 *);
extern void __cdecl *getMemory(I8080 *cpu);            // return address of RAM
extern void __cdecl setMemory(I8080 *cpu, void *memory); // Set address of RAM 

extern void __cdecl stepCPU(I8080 *cpu);
extern uint64_t  __cdecl executeCycles(I8080 *cpu, uint64_t cycleCount);

/** 
 * Set handle for IO port (portno)
 * Function set as that I/O port are responsible for checking weather the 
 * instruction is input or output and getting the accumulator for outputs
 * as well as setting it for input. 
 * 
 * This function should only be used during the configuration of the 
 * CPU and may have undefined side effects if used during CPU execution 
 * 
 * The handle should be a void function that takes a pointer to an I8080 as an argument
 *
 */
extern void __cdecl setIOPort(I8080 *cpu, uint8_t portno, void (*handle)(I8080 *instance)); 

extern uint8_t __cdecl getIOState(I8080 *); // returns 1 if in output mode or 0 if in input mode
#  define INPUT      0
#  define OUTPUT     1
// Numerous synonyms
#  define writeWire  getIOState
#  define isInput    !writeWire
#  define isOutput   writeWire

extern uint8_t __cdecl getAccumulator(I8080 *cpu); // returns -1 if not WriteWire() else the current
						// value in register A
extern uint8_t __cdecl setAccumulator(I8080 *cpu, uint8_t acc); // returns -1 if WriteWire() else the value
						// that register A was set to (only the lowest byte)

#  define INVALID_ACCUMULATOR -1
#  define isValidAccumulator(acc) (acc == INVALID_ACCUMULATOR) ? 0 : 1 // Tests to see if
								// the 'acc' indicates a successful get/set of the accumulator
								// if 0 then the incorrect I/O mode was attempted

// Physical I/O pins
extern void __cdecl resetCPU(I8080 *cpu);    // clears PC and sets IR bit to False; all other registers remain the same
extern void __cdecl requestInterrupt(I8080 *cpu, uint8_t instruction);  // pass a one byte instruction
extern uint8_t __cdecl interruptEnabled(I8080 *cpu);    // Returns 1 if IR bit is True else False
/**
 * setHold() is used to place the CPU in the hold state, essentially halting execution.
 * The getHoldState() function returns whether or not the CPU is in a hold state, via
 * the setHold() method. If an interrupt is received in either the HOLD state or when interrupts
 * are disabled via instructions, then the interrupt will not be acknowledged.
 */
extern uint8_t __cdecl getHoldState(I8080 *cpu);    // returns 1 if HLT or hold pin == 1 else 0
extern void __cdecl setHold(I8080 *cpu, uint8_t value); // Sets hold pin to value (0 or 1)

#endif
