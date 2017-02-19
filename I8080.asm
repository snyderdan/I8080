format ELF64

include 'struct.inc'
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
	public executeInstruction
	public interruptEnabled
	public getIOState
	public getAccumulator
	public setAccumulator
	public newCPU
	public initCPU
	public freeCPU
	public waitState
	public setReady
	public setMMU
	public executeCycles
	public clearMMU
	
	extrn malloc
	extrn free
	extrn clock
	extrn printf

newCPU:   ; Creates new CPU object
    push qword sizeof.I8080CPU
    call qword [malloc]     ; Allocates memory
    add esp, 4
    ret


initCPU:       				; Initializes CPU
    push rax 				; store registers onto stack
    push rbx
    push rcx
    mov rbx, [rsp+8+8*3]  	; get address of cpu instance
    xor eax, eax	 		; zero eax
    mov ecx, sizeof.I8080CPU ; Load size of object minus I/O jump table
@@:
    mov [ebx+ecx-1], al		; store zero at that location
    loop @b		 			; loop while ecx > 0

    mov rax, default_mmu     ; Set the default MMU as the memory manager (returns the same address)
    mov [cpu.mem_mngr], rax

    mov rax, null_handle     ; Load eax with null I/O handle (returns on entry)
    lea rbx, [cpu.IOPorts]   ; Load address of I/O jump table

    not cl		     ; Set cl to 255 (zero-ed from previous loop instruction)
@@:
    mov [rbx], rax	     ; store null handle pointer in I/O table position
    add rbx, 8		     ; Go to next I/O pointer
    loop @b		     ; Loop while cl > 0

    pop rcx
    pop rbx
    pop rax
    ret



freeCPU:     ; Frees CPU instance on stack. Just wraps free()
    push qword [rsp+8]
    call qword [free]
    add esp, 8
    ret


stepCPU:	 ; executes one instruction from CPU
	mov rbx, [rsp+8]	   ; Loads CPU instance into ebx
	mov rsi, [cpu.ram_address] ; load ram address into esi
	mov al, [cpu.halt]	   ; Move halt flag into al
	or  al, [cpu.wait]	   ; Move wait flag into al
	jnz @f			   ; If the CPU is in a halt or wait state, then we don't execute anything
	get_byte		   ; Otherwise load the next instruction byte into al
	movzx rax, al
	call process_instruction   ; Process instruction in al
	sub dword [cpu.clk_counter],4	; Subtract 4 from clock count in order to counterbalance the upcoming addition of 4
@@:	add dword [cpu.clk_counter],4	; Add 4 in case we are halted, basically NOP. If the clock stays constant, a timing loop may never exit
	mov cl, [cpu.int_request]	; Check to see if there is an interrupt request
	and cl, [cpu.int_enabled]	; and verify that interrupts are enabled
	jz  @f				; If not, then we leave
	movzx rax, [cpu.int_instruc]	; Otherwise, get the interrupt instruction
	mov [cpu.int_request], byte 0	; Clear request flag
	mov [cpu.wait], byte 0		; Clear any wait or halt status
	mov [cpu.halt], byte 0
	call process_instruction	; Process interrupt instruction
@@:	ret

executeCycles:
	mov  rbx, [rsp+8]		  	; load CPU instance into ebx
	mov  rsi, [cpu.ram_address]	  ; load ram address into esi
	mov  dword [cpu.clk_counter],0	  ; clear clock cycles
	push rbx			 ; push ebx back to the stack
cycle_loop:
	mov  eax, [cpu.clk_counter]	  ; store counter in eax
	cmp  eax, [rsp+16]		  ; compare to the number of cycles to execute
	jge  cycle_end			  ; if greater than or equal, then stop
	call stepCPU			  ; call step_cpu
	jmp  cycle_loop 		  ; reloop
cycle_end:
	pop  rbx			 ; pop CPU instance
	ret				 ; return

;proc executeInstruction C, cpu_inst, instruction:dword
executeInstruction:	 ; Carry over from previous implementation; don't use.

    mov rbx, [rsp+8]
    mov eax, [rsp+16]
    mov rsi, [cpu.ram_address]
    mov [rsi-4], eax
    mov pc, -3
    movzx eax, al
    call process_instruction
    ret



;proc setramaddress cpu_inst, ramaddr:dword
setMemory:	 ; Sets base RAM address of CPU. Practically obsolete since implementing MMU functionality

    ramaddr  equ rsp+12   ;

    push rbx		  ; Store rbx
    mov rbx, [rsp+16]	  ; load it with CPU instance
    mov rax, [ramaddr]	  ; load rax with ram address
    mov [cpu.ram_address], rax	  ; set ram address and return
    pop rbx
    ret

getMemory:		  ; Returns base RAM address
    push rbx
    mov rbx, [rsp+16]
    mov rax, [cpu.ram_address]
    pop rbx
    ret

setMMU: 		      ; Sets MMU handler
    push rbx		      ; store ebx
    mov rbx, [rsp+16]	      ; mov CPU instance to rbx
    mov rax, [rsp+24]	      ; move pointer to MMU function to rax
    mov [cpu.mem_mngr], rax   ; set handle
    pop rbx		      ; restore ebx and return
    ret

clearMMU:       ; simply sets the memory manager back to default
    push rbx
    mov rbx, [rsp+16]
    mov [cpu.mem_mngr], default_mmu
    pop rbx
    ret


;proc setport c cpu_inst:dword, portnumber:dword, handle:dword
setIOPort:       ; Assign an I/O function handle to an I/O port
    cmp dword [rsp+16], 255   ; ensure port number is under 255
    jle @f
    push qword error1		  ; If not, print an error. Not sure why this is the only error I check for.
    call qword [printf]
    add  rsp, 8
    call exitprocess		  ; And then just leave.
@@: mov  eax, [rsp+16]	      ; Move the actual port number into eax
	xor  rbx, rbx
	mov  ebx, eax
	mov  rax, rbx
    mov  rbx, [rsp+8]  		  ; Move cpu instance into rbx
    mov  rcx, [rsp+24]		  ; move handle into rcx
    imul rax, 8 		  ; Calculate offset (each port in jump table is a 8-byte pointer, so we multiply our port number by 8 to get the offset
    lea  rax, [rax+cpu.IOPorts]   ; Load address of I/O port into rax. I just wanted to use the LEA instruction.
    mov [rax], rcx		  ; store pointer to function
    ret



;proc freeport c cpu_inst:dword, portnumber:dword
freeIOPort:
    cmp dword [rsp+16], 255
    jle @f
    push qword error1
    call qword [printf]
    add  rsp, 8
    call exitprocess
@@: mov  eax, [rsp+16]
	xor  rbx, rbx
	mov  ebx, eax
	mov  rax, rbx
    mov  rbx, [rsp+8]
    imul rax, 8
    lea  rax, [rax+cpu.IOPorts]
    mov [rax], dword 0
    mov [rax+4], dword 0
    ret



requestInterrupt:
    mov  rbx, [rsp+8]
    mov  al, byte [rsp+16]
    mov  [cpu.int_instruc], al
    mov  [cpu.int_request], byte 1
    ret



resetCPU:
	push rbx
	mov rbx, [rsp+16]
	xor ax, ax
	mov [cpu.reg_pc], ax
	mov [cpu.int_enabled], al
	mov [cpu.halt], al
	mov [cpu.wait], al
	pop rbx
	ret



interruptEnabled:
    push rbx
    mov rbx, [rsp+16]
    movzx rax,byte [cpu.int_enabled]
    pop rbx
    ret



getIOState:
    push rbx
    mov  rbx, [rsp+16]
    movzx rax, byte [cpu.wr]
    pop  rbx
    ret


waitState:
    push rbx
    mov  rbx, [rsp+16]
    xor  rax, rax
    mov  al, [cpu.halt]
    or	 al, [cpu.wait]
    pop  rbx
    ret


setReady:
    push rbx
    mov  rbx, [rsp+16]
    mov  al, [rsp+24]
    xor  al, 1	   ; invert the value
    mov  [cpu.wait], al
    pop  rbx
    ret


getAccumulator:
    push rbx
    mov  rbx, [rsp+16]
    movzx rax, a
    cmp  byte [cpu.wr], 1
    jz   @f
    mov  rax, -1
@@: pop  rbx
    ret



;proc setrega C, value:dword
setAccumulator:
	push rbx
    mov  rbx, [rsp+16]
    mov  al, byte [rsp+24]
    mov  a, al
    movzx rax, al
    cmp  byte [cpu.wr], 1
    jz   @f
    mov  rax, -1
@@: pop  rbx
    ret
    
    
exitprocess:
	mov     rax, 60         ; exit
    xor     rdi, rdi        ; return code
    syscall 


section '.data' writeable
  error1 db 'IO Port must be in the range of (0x00-0xFF)',10,0
