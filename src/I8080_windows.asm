format PE64 DLL

include 'win64a.inc'
include 'struct.inc'
include 'globals.inc'
include 'proc_instruction.inc'

section '.code' code readable executable

; Actual I8080 interface methods, defined in a OS independent way
include 'I8080_methods.inc'

section '.idata' import data readable writeable

	library msvcrt, 'msvcrt.dll'

	import msvcrt,malloc,'malloc',\
           free,'free'
           
section '.edata' export data readable

	export 'I8080.DLL',\
         	setIOPort,'setIOPort', \
         	freeIOPort,'freeIOPort',\
         	requestInterrupt, 'requestInterrupt',\
         	setMemory, 'setMemory',\
         	stepCPU, 'stepCPU',\
         	resetCPU, 'resetCPU',\
         	getMemory, 'getMemory',\
         	interruptEnabled, 'interruptEnabled',\
         	getIOState, 'getIOState',\
         	getAccumulator, 'getAccumulator',\
         	setAccumulator, 'setAccumulator',\
         	newCPU, 'newCPU',\
         	initCPU, 'initCPU',\
         	freeCPU, 'freeCPU',\
         	getHoldState, 'getHoldState',\
         	setHold, 'setHold',\
         	setMMU, 'setMMU',\
         	executeCycles, 'executeCycles',\
         	clearMMU, 'clearMMU'

section '.reloc' fixups data discardable