format ELF64

include 'macro/struct.inc'
include 'globals.inc'
include 'proc_instruction.inc'

section '.text' executable
;************************************************
; had to define all the args stuff myself as
; fasm kept barfing on declaring C calls for some reason.
;
; I declared the functions like so:
;	proc exec c, cpu_inst, instruction:dword
;		; some code
;	endp
;
; And it would complain about invalid labels or
; extra characters on the line on the endp or ret
;************************************************

	public setIOPort
	public freeIOPort
	public requestInterrupt
	public setMemory
	public stepCPU
	public resetCPU
	public getMemory
	public interruptEnabled
	public getIOState
	public getAccumulator
	public setAccumulator
	public newCPU
	public initCPU
	public freeCPU
	public getHoldState
	public setHold
	public setMMU
	public executeCycles
	public clearMMU
	
	extrn malloc
	extrn free

; Actual I8080 interface methods, defined in a OS independent way
include 'I8080_methods.inc'
