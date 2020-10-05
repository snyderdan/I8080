I8080

Emulator based on the Intel 8080 processor. 

This emulator can be assembled using FASM, and provides an object file 
that can be linked to C/C++ programs using the I8080.h header file. 
There are a number of methods outlined in the header that are used to 
interface with, and control, the emulator. These are detailed in the 
header file itself, but here are a few highlighted points.

In order to run, the CPU must be provided either a valid block of memory
to use as RAM, or an MMU function must be provided. To have simple direct
memory access, use setMemory() passing it a pointer to valid memory. 
If more advanced functionality is desired (memory virtualization, paging,
protection, etc.) then an MMU function should be provided through the
setMMU() function. The MMU function can use isOutput() or isInput() to 
see if the CPU is attempting to write to an address or read from an 
address. 

All kinds of crazy things can be accomplished in the MMU function. There 
is no READY pin functionality, as the READY pin is acknowledged after the 
I8080 has placed an address on the address bus. If you wish to put the 
CPU into a WAIT state (as the READY pin does) then execution can be held
in the MMU function to produce the same effect. 

Once an interrupt request is made, it is processed when the CPU finishes
processing its current instruction. If the CPU is in the HALT state, and
interrupts are enabled, the interrupt is accepted and processed. If the
CPU is in the HOLD state, or interrupts are disabled, the request is 
ignored, and must be sent again at a later time. It is also possible to
write an interrupt controller, to avoid conflicts of interrupts. If 
multiple interrupts are made at once, it is a matter of who gets to write
last. Interrupts are disabled when an interrupt request is accepted.
