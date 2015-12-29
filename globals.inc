;
;********************************************************************
; General notes on register usage 
;
; ebx contains the pointer to the current in-use CPU instance
; esi contains the pointer to the main memory for that CPU
; edi is used for indexing into main memory (PC and HL)
;
;********************************************************************

struct I8080CPU    ; structure for I8080 object
    ; start with aligned portions
    clk_counter dd  ?	; clocks passed
    ram_address dd  ?	; base RAM address
    mem_mngr	dd  ?	; pointer to MMU
    IOPorts	dd  256 dup ?	 ; Internal I/O jump table
    reg_pc  dw	?	; program counter
    reg_sp  dw	?	; stack pointer
    ; registers
    reg_a   db	?
    reg_c   db	?
    reg_b   db	?
    reg_e   db	?
    reg_d   db	?
    reg_l   db	?
    reg_h   db	?
    reg_f   db	?
    halt    db	?	; flag if CPU is in halt state
    wr	    db	?	; write wire; tells I/O functions state of CPU
    wait    db	?	; flag if CPU is in wait state
    int_enabled db  ?	; flag set if interrupts are enabled
    int_request db  ?	; flag set when interrupt is requested
    int_instruc db  ?	; instruction passed from interrupt
ends

; CPU critical information

virtual at ebx	   ; set up a virtual object at ebx
    cpu I8080CPU   ; anytime we reference cpu, it will use ebx as the base address, and add an offset based on what attribute is being accessed.
end virtual

; 8-bit registers
a  equ	byte [cpu.reg_a]
b  equ	byte [cpu.reg_b]
c  equ	byte [cpu.reg_c]
d  equ	byte [cpu.reg_d]
e  equ	byte [cpu.reg_e]
h  equ	byte [cpu.reg_h]
l  equ	byte [cpu.reg_l]

; pseudo registers
bc equ word [cpu.reg_c]
de equ word [cpu.reg_e]
hl equ word [cpu.reg_l]

; 16-bit registers
pc equ	word [cpu.reg_pc]
sp equ	word [cpu.reg_sp]
;
; the m operand refers to [hl]
;


null_handle:
    ret

default_mmu:
    mov eax, [esp+8]
    ret

macro lflags {	     ; load flags from cpu instance
      mov ah, [cpu.reg_f]
      sahf
}

macro sflags {	     ; store flags in cpu instance
      lahf
      mov [cpu.reg_f], ah
}

macro get_byte {	 ; Get next byte pointed to by PC and increment PC
      movzx edi, pc
      push edi
      push ebx
      call dword [cpu.mem_mngr]
      add  esp, 8
      mov  al, [esi+eax]
      inc pc
}

macro get_word {	; Get next word pointed to by PC and increment PC
      movzx edi, pc
      push edi
      push ebx
      call dword [cpu.mem_mngr]
      add  esp, 8
      mov  ax, [esi+eax]
      add  pc, 2
}

macro read_byte src {	; Read byte located at src
      movzx edi, src
      push edi
      push ebx
      call dword [cpu.mem_mngr]
      add  esp, 8
      mov  al, [esi+eax]
}

macro read_word src {	; read word located at src
      movzx edi, src
      push edi
      push ebx
      call dword [cpu.mem_mngr]
      add  esp, 8
      mov  ax, [esi+eax]
}

macro write_byte dest {
      movzx edi, dest
      push ecx
      push edi
      push ebx
      mov  byte [cpu.wr],1
      call dword [cpu.mem_mngr]
      mov  byte [cpu.wr],0
      add  esp, 8
      pop  ecx
      mov  byte [esi+eax], cl
}

macro write_word dest {
      movzx edi, dest
      push ecx
      push edi
      push ebx
      mov  byte [cpu.wr],1
      call dword [cpu.mem_mngr]
      mov  byte [cpu.wr],0
      add  esp, 8
      pop  ecx
      mov  word [esi+eax], cx
}

macro push_cx {
      sub sp, 2
      movzx edi, sp
      push ecx
      push edi
      push ebx
      mov  byte [cpu.wr],1
      call dword [cpu.mem_mngr]
      mov  byte [cpu.wr],0
      add  esp, 8
      pop  ecx
      mov  word [esi+eax], cx
}

macro pop_cx {
      add sp, 2
      movzx edi, sp
      push edi
      push ebx
      call dword [cpu.mem_mngr]
      add  esp, 8
      mov cx, word [esi+eax-2]
}