format PE DLL

include 'win32a.inc'
include 'globals.inc'
include 'proc_instruction.inc'

section '.code' code readable executable
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

cpu_inst equ esp+4+(8*4)   ; the addition of 4 is accounting for the
			   ; return address while the (8*4) is accounting for the pusha instruction

newcpu:   ; Creates new CPU object
    push dword sizeof.I8080CPU
    call [malloc]     ; Allocates memory
    add esp, 4
    ret


initcpu:       ; Initializes CPU
    pusha		 ; store registers onto stack
    mov ebx, [cpu_inst]  ; get address of cpu instance
    xor eax, eax	 ; zero eax
    mov ecx, sizeof.I8080CPU-(256*4) ; Load size of object minus I/O jump table
@@:
    mov [ebx+ecx-1], al  ; store zero at that location
    loop @b		 ; loop while ecx > 0

    mov eax, default_mmu     ; Set the default MMU as the memory manager (returns the same address)
    mov [cpu.mem_mngr], eax

    mov eax, null_handle     ; Load eax with null I/O handle (returns on entry)
    lea ebx, [cpu.IOPorts]   ; Load address of I/O jump table

    not cl		     ; Set cl to 255 (zero-ed from previous loop instruction)
@@:
    mov [ebx], eax	     ; store null handle pointer in I/O table position
    add ebx, 4		     ; Go to next I/O pointer
    loop @b		     ; Loop while cl > 0

    popa		     ; restore registers and return
    ret



freecpu:     ; Frees CPU instance on stack. Just wraps free()
    push dword [esp+4]
    call [free]
    add esp, 4
    ret


step_cpu:	 ; executes one instruction from CPU
	pusha			   ; store all registers
	mov ebx, [cpu_inst]	   ; Loads CPU instance into ebx
	mov esi, [cpu.ram_address] ; load ram address into esi
	mov al, [cpu.halt]	   ; Move halt flag into al
	or  al, [cpu.wait]	   ; Move wait flag into al
	jnz @f			   ; If the CPU is in a halt or wait state, then we don't execute anything
	get_byte		   ; Otherwise load the next instruction byte into al
	movzx eax, al
	call process_instruction   ; Process instruction in al
	sub dword [cpu.clk_counter],4	; Subtract 4 from clock count in order to counterbalance the upcoming addition of 4
@@:	add dword [cpu.clk_counter],4	; Add 4 in case we are halted, basically NOP. If the clock stays constant, a timing loop may never exit
	mov cl, [cpu.int_request]	; Check to see if there is an interrupt request
	and cl, [cpu.int_enabled]	; and verify that interrupts are enabled
	jz  @f				; If not, then we leave
	movzx eax, [cpu.int_instruc]	; Otherwise, get the interrupt instruction
	mov [cpu.int_request], byte 0	; Clear request flag
	mov [cpu.wait], byte 0		; Clear any wait or halt status
	mov [cpu.halt], byte 0
	call process_instruction	; Process interrupt instruction
@@:	popa				; Restore registers and return
	ret

cycles:
	pusha				 ; store all registers
	mov  ebx, [cpu_inst]		  ; load CPU instance into ebx
	mov  esi, [cpu.ram_address]	  ; load ram address into esi
	mov  dword [cpu.clk_counter],0	  ; clear clock cycles
	push ebx			 ; push ebx back to the stack
cycle_loop:
	mov  eax, [cpu.clk_counter]	  ; store counter in eax
	cmp  eax, [cpu_inst+8]		  ; compare to the number of cycles to execute
	jge  cycle_end			  ; if greater than or equal, then stop
	call step_cpu			  ; call step_cpu
	jmp  cycle_loop 		  ; reloop
cycle_end:
	pop  ebx			 ; pop CPU instance
	mov  [esp+(4*7)],eax		 ; store cycles in place of eax
	popa				 ; pop all regs
	ret				 ; return

;proc exec C, cpu_inst, instruction:dword
exec:	 ; Carry over from previous implementation; don't use.

    instruction equ cpu_inst + 4

    pusha
    mov ebx, [cpu_inst]
    mov eax, [instruction]
    mov esi, [cpu.ram_address]
    mov [esi-4], eax
    mov pc, -3
    movzx eax, al
    call process_instruction
    popa
    ret



;proc setramaddress cpu_inst, ramaddr:dword
setramaddress:	 ; Sets base RAM address of CPU. Practically obsolete since implementing MMU functionality

    ramaddr  equ esp+12   ;

    push ebx		  ; Store ebx
    mov ebx, [esp+8]	  ; load it with CPU instance
    mov eax, [ramaddr]	  ; load eax with ram address
    mov [cpu.ram_address], eax	  ; set ram address and return
    pop ebx
    ret

getramaddress:		  ; Returns base RAM address
    push ebx
    mov ebx, [esp+8]
    mov eax, [cpu.ram_address]
    pop ebx
    ret

setmmu: 		      ; Sets MMU handler
    push ebx		      ; store ebx
    mov ebx, [esp+8]	      ; mov CPU instance to ebx
    mov eax, [esp+12]	      ; move pointer to MMU function to eax
    mov [cpu.mem_mngr], eax   ; set handle
    pop ebx		      ; restore ebx and return
    ret

clrmmu:       ; simply sets the memory manager back to default
    push ebx
    mov ebx, [esp+8]
    mov [cpu.mem_mngr], default_mmu
    pop ebx
    ret


;proc setport c cpu_inst:dword, portnumber:dword, handle:dword
setport:       ; Assign an I/O function handle to an I/O port

    portnumber equ cpu_inst+4	  ; port assigning to
    handle     equ cpu_inst+8	  ; function handle

    pusha			  ; store registers
    cmp dword [portnumber], 255   ; ensure port number is under 255
    jle @f
    push dword error1		  ; If not, print an error. Not sure why this is the only error I check for.
    call [printf]
    mov [esp], dword 1
    call [exitprocess]		  ; And then just leave.
@@: mov  eax, [portnumber]	  ; Move the actual port number into eax
    mov  ebx, [cpu_inst]	  ; Move cpu instance into ebx
    mov  ecx, [handle]		  ; move handle into ecx
    imul eax, 4 		  ; Calculate offset (each port in jump table is a 4-byte pointer, so we multiply our port number by 4 to get the offset
    lea  eax, [eax+cpu.IOPorts]   ; Load address of I/O port into eax. I just wanted to use the LEA instruction.
    mov [eax], ecx		  ; store pointer to function
    popa			  ; restore registers and ret
    ret



;proc freeport c cpu_inst:dword, portnumber:dword
freeport:

    portnumber equ cpu_inst+4

    pusha
    cmp dword [portnumber], 255
    jle @f
    push dword error1
    call [printf]
    add esp, 4
    push dword 1
    call [exitprocess]
@@: mov  eax, [portnumber]
    mov  ebx, [cpu_inst]
    imul eax, 4
    lea  eax, [eax+cpu.IOPorts]
    mov [eax], dword 0
    popa
    ret



;proc requestint C cpu_inst, intaddress:WORD
requestint:

    intaddress equ cpu_inst+4

    pusha
    mov  ebx, [cpu_inst]
    mov  al,byte [intaddress]
    mov [cpu.int_instruc], al
    MOV [cpu.int_request], byte 1
    popa
    ret



reset_cpu:
	push ebx
	mov ebx, [esp+8]
	xor ax, ax
	mov [cpu.reg_pc], ax
	mov [cpu.int_enabled], al
	mov [cpu.halt], al
	mov [cpu.wait], al
	pop ebx
	ret



areintsenabled:
    push ebx
    mov ebx, [esp+8]
    movzx eax,byte [cpu.int_enabled]
    pop ebx
    ret



writewire:
    push ebx
    mov ebx, [esp+8]
    movzx eax, byte [cpu.wr]
    pop ebx
    ret


waitw:
    push ebx
    mov ebx, [esp+8]
    xor eax, eax
    mov al, [cpu.halt]
    or	al, [cpu.wait]
    pop ebx
    ret


setwait:
    push ebx
    mov ebx, [esp+8]
    mov al, [esp+16]
    xor al, 1	   ; invert the value
    mov [cpu.wait], al
    pop ebx
    ret


getrega:
    push ebx
    mov ebx, [esp+8]
    movzx eax, a
    cmp   byte [cpu.wr], 1
    jz @f
    mov eax, -1
@@: pop ebx
    ret



;proc setrega C, value:dword
setrega:

    value    equ esp+12

    push ebx
    mov ebx, [esp+8]
    mov al, byte [value]
    mov a, al
    movzx eax, al
    cmp byte [cpu.wr], 1
    jz @f
    mov eax, -1
@@: pop ebx
    ret


section '.data' data readable writeable
  error1 db 'IO Port must be in the range of (0x00-0xFF)',10,0

section '.idata' import data readable writeable

  library kernel, 'kernel32.dll',\
	  msvcrt, 'msvcrt.dll',\
	  delay, 'delay.dll'

  import msvcrt,printf,'printf',\
		malloc,'malloc',\
		free,'free',\
		clock,'clock'

  import kernel,exitprocess, 'ExitProcess'

section '.edata' export data readable

  export 'I8080.DLL',\
	 setport,'setIOPort', \
	 freeport,'freeIOPort',\
	 requestint, 'requestInterrupt',\
	 setramaddress, 'setMemory',\
	 step_cpu, 'stepCPU',\
	 reset_cpu, 'resetCPU',\
	 getramaddress, 'getMemory',\
	 exec, 'executeInstruction',\
	 areintsenabled, 'interruptEnabled',\
	 writewire, 'getIOState',\
	 getrega, 'getAccumulator',\
	 setrega, 'setAccumulator',\
	 newcpu, 'newCPU',\
	 initcpu, 'initCPU',\
	 freecpu, 'freeCPU',\
	 waitw, 'waitState',\
	 setwait, 'setReady',\
	 setmmu, 'setMMU',\
	 cycles, 'executeCycles',\
	 clrmmu, 'clearMMU'

section '.reloc' fixups data discardable