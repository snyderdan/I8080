;
; Actual I8080 interface methods, defined in a OS independent way
; There are some external dependencies that need to be provided, but they are readily available on both
; Windows and *nix machines:
;       malloc
;       free
;       printf (necessary?)
;       clock (necessary?)
;

newCPU:   ; Creates new CPU object
	mov rdi, sizeof.I8080CPU
    call malloc     ; Allocates memory
    ret


initCPU:       				; Initializes CPU
    push rbx
    mov rbx, rdi          	; get address of cpu instance
    xor rax, rax	 		; zero rax
    mov rcx, sizeof.I8080CPU ; Load size of object
@@:
    mov [rbx+rcx-1], al		; store zero at that location
    loop @b		 			; loop while rcx > 0

    mov rax, default_mmu     ; Set the default MMU as the memory manager (returns the same address)
    mov [cpu.mem_mngr], rax

    mov rax, null_handle     ; Load rax with null I/O handle (returns on entry)
    lea rbx, [cpu.IOPorts]   ; Load address of I/O jump table

    not cl		     ; Set cl to 255 (zero-ed from previous loop instruction)
@@:
    mov [rbx], rax	     ; store null handle pointer in I/O table position
    add rbx, 8		     ; Go to next I/O pointer
    loop @b		     ; Loop while cl > 0
    pop rbx
    ret



freeCPU:     ; Frees CPU instance on stack. Just wraps free()
    call free
    ret


stepCPU:	 ; executes one instruction from CPU
    push rbx
	mov rbx, rdi       	   ; Loads CPU instance into rbx
	mov rsi, [cpu.ram_address] ; load ram address into rsi
	mov al, [cpu.halt]	   ; Move halt flag into al
	or  al, [cpu.hold]	   ; Move hold flag into al
	jnz @f			   ; If the CPU is in a halt or hold state, then we don't execute anything
	get_byte		   ; Otherwise load the next instruction byte into al
	movzx rax, al
	call process_instruction   	; Process instruction in al
	sub dword [cpu.clk_counter],4	; Subtract 4 from clock count in order to counterbalance the upcoming addition of 4
@@:	add dword [cpu.clk_counter],4	; Add 4 in case we are halted, basically NOP. If the clock stays constant, a timing loop may never exit
	mov cl, [cpu.int_request]		; Check to see if there is an interrupt request
	and cl, [cpu.int_enabled]		; and verify that interrupts are enabled
	mov [cpu.int_request], byte 0 	; clear interrupt request (we are either taking the request or not. No second chance)
	jz  @f					; If not, then we leave
	and cl, [cpu.hold]		; If we are in a hold state, we do not acknowledge the interrupt
	jnz @f
	movzx rax, [cpu.int_instruc]	; Otherwise, get the interrupt instruction
	mov [cpu.int_enabled], byte 0	; Disable interrupts to process interrupt
	mov [cpu.halt], byte 0		; Clear halt status
	call process_instruction	; Process interrupt instruction
@@:	pop rbx
    ret



executeCycles:
    push rbx
	mov  rbx, rdi      		  	  ; load CPU instance into rbx
	mov  dword [cpu.clk_counter],0	  ; clear clock cycles
cycle_loop:
	cmp  [cpu.clk_counter], esi	 ; compare to the number of cycles to execute
	jge  cycle_end			     ; if greater than or equal, then stop
    push rsi                    ; store counter
    mov  rdi, rbx               ; pass CPU instance
	call stepCPU			     ; call step_cpu
    pop  rsi                    ; restore counter
	jmp  cycle_loop 		     ; reloop
cycle_end:
    pop rbx
	ret				             ; return




;proc setramaddress cpu_inst, ramaddr:dword
setMemory:	 ; Sets base RAM address of CPU. Practically obsolete since implementing MMU functionality
    push rbx		  ; Store rbx
    mov rbx, rdi	  ; load it with CPU instance
    mov [cpu.ram_address], rsi	  ; set ram address and return
    pop rbx
    ret


getMemory:		  ; Returns base RAM address
    push rbx
    mov rbx, rdi
    mov rax, [cpu.ram_address]
    pop rbx
    ret

setMMU: 		      ; Sets MMU handler
    push rbx		      ; store ebx
    mov rbx, rdi	      ; mov CPU instance to rbx
    mov [cpu.mem_mngr], rsi   ; set handle
    pop rbx		      ; restore ebx and return
    ret

clearMMU:       ; simply sets the memory manager back to default
    push rbx
    mov rbx, rdi
    mov [cpu.mem_mngr], default_mmu
    pop rbx
    ret


;proc setport c cpu_inst:dword, portnumber:dword, handle:dword
setIOPort:          ; Assign an I/O function handle to an I/O port
    push rbx
    cmp  esi, 255    ; ensure port number is under 255
    jle  @f
    push qword error1		; If not, print an error. Not sure why this is the only error I check for.
    call printf
    add  rsp, 8
    call exitprocess		; And then just leave.
@@: xor  rax, rax
    mov  eax, esi           ; move port number to eax
    mov  rbx, rdi     		; Move cpu instance into rbx
    imul rax, 8 		  ; Calculate offset (each port in jump table is a 8-byte pointer, so we multiply our port number by 8 to get the offset
    mov  [rax+cpu.IOPorts], rdx		  ; store pointer to function
    pop  rbx
    ret



;proc freeport c cpu_inst:dword, portnumber:dword
freeIOPort:
    push rbx
    cmp  esi, 255
    jle  @f
    push qword error1
    call printf
    add  rsp, 8
    call exitprocess
@@: xor  rax, rax
    mov  eax, esi           ; move port number to eax
    mov  rbx, rdi           ; Move cpu instance into rbx
    imul rax, 8           ; Calculate offset (each port in jump table is a 8-byte pointer, so we multiply our port number by 8 to get the offset
    mov  rdx, null_handle
    mov  [rax+cpu.IOPorts], rdx
    pop  rbx
    ret



requestInterrupt:
    push rbx
    mov  rbx, rdi
    mov  al, byte [rsp+16]
    mov  [cpu.int_instruc], al
    mov  [cpu.int_request], byte 1
    pop  rbx
    ret



resetCPU:
	push rbx
	mov rbx, rdi
	xor ax, ax
	mov [cpu.reg_pc], ax
	mov [cpu.int_enabled], al
	mov [cpu.halt], al
	mov [cpu.hold], al
	pop rbx
	ret



interruptEnabled:
    push rbx
    mov rbx, rdi
    movzx rax,byte [cpu.int_enabled]
    pop rbx
    ret



getIOState:
    push rbx
    mov  rbx, rdi
    movzx rax, byte [cpu.wr]
    pop  rbx
    ret


getHoldState:
    push rbx
    mov  rbx, rdi
    xor  rax, rax
    mov  al, [cpu.hold]
    pop  rbx
    ret


setHold:
    push rbx
    mov  rbx, rdi
    mov  ax, si
    xor  al, 1	   ; invert the value
    mov  [cpu.hold], al
    pop  rbx
    ret


getAccumulator:
    push rbx
    mov  rbx, rdi
    movzx rax, a
    cmp  byte [cpu.wr], 1
    jz   @f
    mov  rax, -1
@@: pop  rbx
    ret



;proc setrega C, value:dword
setAccumulator:
	push rbx
    mov  rbx, rdi
    mov  ax, si
    mov  a, al
    movzx rax, si
    cmp  byte [cpu.wr], 1
    jz   @f
    mov  rax, -1
@@: pop  rbx
    ret
    
    
exitprocess:
	mov     rax, 60         ; exit
    xor     rdi, rdi        ; return code
    syscall 