process_instruction:
	imul rax, 8	  ; scale from 1 to 8 bytes
	mov  rdx, qword .instr_jmp_table
	add  rax, rdx
	jmp  qword [rax]   ; jumps to address pointed to by eax

	.instr_jmp_table:
		dq .instr_0x0
		dq .instr_0x1
		dq .instr_0x2
		dq .instr_0x3
		dq .instr_0x4
		dq .instr_0x5
		dq .instr_0x6
		dq .instr_0x7
		dq .instr_0x8
		dq .instr_0x9
		dq .instr_0xa
		dq .instr_0xb
		dq .instr_0xc
		dq .instr_0xd
		dq .instr_0xe
		dq .instr_0xf
		dq .instr_0x10
		dq .instr_0x11
		dq .instr_0x12
		dq .instr_0x13
		dq .instr_0x14
		dq .instr_0x15
		dq .instr_0x16
		dq .instr_0x17
		dq .instr_0x18
		dq .instr_0x19
		dq .instr_0x1a
		dq .instr_0x1b
		dq .instr_0x1c
		dq .instr_0x1d
		dq .instr_0x1e
		dq .instr_0x1f
		dq .instr_0x20
		dq .instr_0x21
		dq .instr_0x22
		dq .instr_0x23
		dq .instr_0x24
		dq .instr_0x25
		dq .instr_0x26
		dq .instr_0x27
		dq .instr_0x28
		dq .instr_0x29
		dq .instr_0x2a
		dq .instr_0x2b
		dq .instr_0x2c
		dq .instr_0x2d
		dq .instr_0x2e
		dq .instr_0x2f
		dq .instr_0x30
		dq .instr_0x31
		dq .instr_0x32
		dq .instr_0x33
		dq .instr_0x34
		dq .instr_0x35
		dq .instr_0x36
		dq .instr_0x37
		dq .instr_0x38
		dq .instr_0x39
		dq .instr_0x3a
		dq .instr_0x3b
		dq .instr_0x3c
		dq .instr_0x3d
		dq .instr_0x3e
		dq .instr_0x3f
		dq .instr_0x40
		dq .instr_0x41
		dq .instr_0x42
		dq .instr_0x43
		dq .instr_0x44
		dq .instr_0x45
		dq .instr_0x46
		dq .instr_0x47
		dq .instr_0x48
		dq .instr_0x49
		dq .instr_0x4a
		dq .instr_0x4b
		dq .instr_0x4c
		dq .instr_0x4d
		dq .instr_0x4e
		dq .instr_0x4f
		dq .instr_0x50
		dq .instr_0x51
		dq .instr_0x52
		dq .instr_0x53
		dq .instr_0x54
		dq .instr_0x55
		dq .instr_0x56
		dq .instr_0x57
		dq .instr_0x58
		dq .instr_0x59
		dq .instr_0x5a
		dq .instr_0x5b
		dq .instr_0x5c
		dq .instr_0x5d
		dq .instr_0x5e
		dq .instr_0x5f
		dq .instr_0x60
		dq .instr_0x61
		dq .instr_0x62
		dq .instr_0x63
		dq .instr_0x64
		dq .instr_0x65
		dq .instr_0x66
		dq .instr_0x67
		dq .instr_0x68
		dq .instr_0x69
		dq .instr_0x6a
		dq .instr_0x6b
		dq .instr_0x6c
		dq .instr_0x6d
		dq .instr_0x6e
		dq .instr_0x6f
		dq .instr_0x70
		dq .instr_0x71
		dq .instr_0x72
		dq .instr_0x73
		dq .instr_0x74
		dq .instr_0x75
		dq .instr_0x76
		dq .instr_0x77
		dq .instr_0x78
		dq .instr_0x79
		dq .instr_0x7a
		dq .instr_0x7b
		dq .instr_0x7c
		dq .instr_0x7d
		dq .instr_0x7e
		dq .instr_0x7f
		dq .instr_0x80
		dq .instr_0x81
		dq .instr_0x82
		dq .instr_0x83
		dq .instr_0x84
		dq .instr_0x85
		dq .instr_0x86
		dq .instr_0x87
		dq .instr_0x88
		dq .instr_0x89
		dq .instr_0x8a
		dq .instr_0x8b
		dq .instr_0x8c
		dq .instr_0x8d
		dq .instr_0x8e
		dq .instr_0x8f
		dq .instr_0x90
		dq .instr_0x91
		dq .instr_0x92
		dq .instr_0x93
		dq .instr_0x94
		dq .instr_0x95
		dq .instr_0x96
		dq .instr_0x97
		dq .instr_0x98
		dq .instr_0x99
		dq .instr_0x9a
		dq .instr_0x9b
		dq .instr_0x9c
		dq .instr_0x9d
		dq .instr_0x9e
		dq .instr_0x9f
		dq .instr_0xa0
		dq .instr_0xa1
		dq .instr_0xa2
		dq .instr_0xa3
		dq .instr_0xa4
		dq .instr_0xa5
		dq .instr_0xa6
		dq .instr_0xa7
		dq .instr_0xa8
		dq .instr_0xa9
		dq .instr_0xaa
		dq .instr_0xab
		dq .instr_0xac
		dq .instr_0xad
		dq .instr_0xae
		dq .instr_0xaf
		dq .instr_0xb0
		dq .instr_0xb1
		dq .instr_0xb2
		dq .instr_0xb3
		dq .instr_0xb4
		dq .instr_0xb5
		dq .instr_0xb6
		dq .instr_0xb7
		dq .instr_0xb8
		dq .instr_0xb9
		dq .instr_0xba
		dq .instr_0xbb
		dq .instr_0xbc
		dq .instr_0xbd
		dq .instr_0xbe
		dq .instr_0xbf
		dq .instr_0xc0
		dq .instr_0xc1
		dq .instr_0xc2
		dq .instr_0xc3
		dq .instr_0xc4
		dq .instr_0xc5
		dq .instr_0xc6
		dq .instr_0xc7
		dq .instr_0xc8
		dq .instr_0xc9
		dq .instr_0xca
		dq .instr_0xcb
		dq .instr_0xcc
		dq .instr_0xcd
		dq .instr_0xce
		dq .instr_0xcf
		dq .instr_0xd0
		dq .instr_0xd1
		dq .instr_0xd2
		dq .instr_0xd3
		dq .instr_0xd4
		dq .instr_0xd5
		dq .instr_0xd6
		dq .instr_0xd7
		dq .instr_0xd8
		dq .instr_0xd9
		dq .instr_0xda
		dq .instr_0xdb
		dq .instr_0xdc
		dq .instr_0xdd
		dq .instr_0xde
		dq .instr_0xdf
		dq .instr_0xe0
		dq .instr_0xe1
		dq .instr_0xe2
		dq .instr_0xe3
		dq .instr_0xe4
		dq .instr_0xe5
		dq .instr_0xe6
		dq .instr_0xe7
		dq .instr_0xe8
		dq .instr_0xe9
		dq .instr_0xea
		dq .instr_0xeb
		dq .instr_0xec
		dq .instr_0xed
		dq .instr_0xee
		dq .instr_0xef
		dq .instr_0xf0
		dq .instr_0xf1
		dq .instr_0xf2
		dq .instr_0xf3
		dq .instr_0xf4
		dq .instr_0xf5
		dq .instr_0xf6
		dq .instr_0xf7
		dq .instr_0xf8
		dq .instr_0xf9
		dq .instr_0xfa
		dq .instr_0xfb
		dq .instr_0xfc
		dq .instr_0xfd
		dq .instr_0xfe
		dq .instr_0xff
		
	;
	; many instructions such as 0x8, 0x10, and 0x18 are undefined in the
	; 8080 documentation so they are left unimplemented
	; 
	; instructions such as mov b, b are also left unimplemented
	;
	
	.instr_0x0: ; nop
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x1: ; lxi b, word
		add dword [cpu.clk_counter],10
		get_word
		mov bc, ax
		ret

	.instr_0x2: ; stax b
		add dword [cpu.clk_counter],7
		mov cl, a
		write_byte bc
		ret

	.instr_0x3: ; inx b
		add dword [cpu.clk_counter],5
		inc bc
		ret
		
	.instr_0x4: ; inr b
		add dword [cpu.clk_counter],5
		lflags
		inc b
		sflags
		ret
		
	.instr_0x5: ; dcr b
		add dword [cpu.clk_counter],5
		lflags
		dec b
		sflags
		ret
		
	.instr_0x6: ; mvi b, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov b, al
		ret
		
	.instr_0x7: ; rcl
		add dword [cpu.clk_counter],4
		lflags
		rcl a, 1       ; rotates through carry to the left
		sflags
		ret
		
	.instr_0x8:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x9: ; dad b
		add dword [cpu.clk_counter],10
		mov ax, bc
		add hl, ax
		jnc @f
		lflags
		stc
		sflags
	 @@:	ret
		
	.instr_0xa: ; ldax b
		add dword [cpu.clk_counter],7
		read_byte bc
		mov a, al
		ret
		
	.instr_0xb: ; dcx b
		add dword [cpu.clk_counter],5
		dec bc
		ret
		
	.instr_0xc: ; inr c
		add dword [cpu.clk_counter],5
		lflags
		inc c
		sflags
		ret
		
	.instr_0xd: ; dcr c
		add dword [cpu.clk_counter],5
		lflags
		dec c
		sflags
		ret
		
	.instr_0xe: ; mvi c, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov c, al
		ret
		
	.instr_0xf: ; rrc
		add dword [cpu.clk_counter],4
		lflags
		rcr a, 1       ; rotates right through carry
		sflags
		ret
		
	.instr_0x10:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x11: ; lxi d, word
		add dword [cpu.clk_counter],10
		get_word
		mov de, ax
		ret
		
	.instr_0x12: ; stax d
		add dword [cpu.clk_counter],7
		mov cl, a
		write_byte de
		ret
		
	.instr_0x13: ; inx d
		add dword [cpu.clk_counter],5
		inc de
		ret
		
	.instr_0x14: ; inr d
		add dword [cpu.clk_counter],5
		lflags
		inc d
		sflags
		ret
		
	.instr_0x15: ; dcr d
		add dword [cpu.clk_counter],5
		lflags
		dec d
		sflags
		ret
		
	.instr_0x16: ; mvi d, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov d, al
		ret
		
	.instr_0x17: ; ral
		add dword [cpu.clk_counter],4
		lflags
		rol a, 1
		sflags
		ret
		
	.instr_0x18:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x19: ; dad d
		add dword [cpu.clk_counter],10
		mov ax, de
		add hl, ax
		jnc @f
		lflags
		stc
		sflags
	 @@:	ret
		
	.instr_0x1a: ; ldax d
		add dword [cpu.clk_counter],7
		read_byte de
		mov a,al
		ret
		
	.instr_0x1b: ; dcx d
		add dword [cpu.clk_counter],5
		dec de
		ret
		
	.instr_0x1c: ; inr e
		add dword [cpu.clk_counter],5
		lflags
		inc e
		sflags
		ret
		
	.instr_0x1d: ; dcr e
		add dword [cpu.clk_counter],5
		lflags
		dec e
		sflags
		ret
		
	.instr_0x1e: ; mvi e, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov e, al
		ret
		
	.instr_0x1f: ; rar
		add dword [cpu.clk_counter],4
		lflags
		ror a, 1
		sflags
		ret
		
	.instr_0x20:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x21: ; lxi h, word
		add dword [cpu.clk_counter],10
		get_word
		mov hl, ax
		ret
		
	.instr_0x22: ; shld word
		add dword [cpu.clk_counter],16
		get_word
		mov cx, hl
		write_word ax
		ret
		
	.instr_0x23: ; inx h
		add dword [cpu.clk_counter],5
		inc hl
		ret
		
	.instr_0x24: ; inr h
		add dword [cpu.clk_counter],5
		lflags
		inc h
		sflags
		ret
		
	.instr_0x25: ; dcr h
		add dword [cpu.clk_counter],5
		lflags
		dec h
		sflags
		ret
		
	.instr_0x26: ; mvi h, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov h, al
		ret
		
	.instr_0x27: ; daa
		add dword [cpu.clk_counter],4
		lflags				; load virtual flags in ah
		mov  ch, ah			; store working copy in ch
		mov  cl, ch			; store old copy in cl
		test ah, 16			; AF set?
		jnz  .loadjust		; if it is, perform adjustment
		mov  al, a			; otherwise, we check if the lower digit is over 9
		and  al, 0FH		; extract lower BCD digit
		cmp  al, 9			; digit > 9?
		jg   .loadjust		; perform adjustment
		mov  al, a			; 
		and  ch, (255-16)	; otherwise, clear AF in ch
		jmp  .hibyte		; go to process high digit
	  .loadjust:
		mov  al, a			; load number
		add  al, 6			; add 6
		or   ch, 16			; set AF flag
		jnc  .hibyte		; set carry if necessary
		or   ch, 1
	  .hibyte:
		cmp  a, 99H			; A > 99H?
		jg	 .hiadjust		; if so, adjust
		test cl, 1			; old CF set?
		jnz  .hiadjust		; if so, adjust
		and  ch, 254		; otherwise, clear carry
		jmp  @f				; skip adjustment
	  .hiadjust:
		add  al, 60H		; adjust
		or   ch, 1			; set carry
	  @@:
		mov  a, al
		mov  [cpu.reg_f], ch
		ret
		
		
	.instr_0x28:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x29: ; dad h
		add dword [cpu.clk_counter],10
		mov ax, hl
		add hl, ax
		jnc @f
		lflags
		stc
		sflags
	 @@:	ret
		
	.instr_0x2a: ; lhld word
		add dword [cpu.clk_counter],16
		get_word
		read_word ax
		mov hl, ax
		ret
		
	.instr_0x2b: ; dex h
		add dword [cpu.clk_counter],5
		dec hl
		ret
		
	.instr_0x2c: ; inr l
		add dword [cpu.clk_counter],5
		lflags
		inc l
		sflags
		ret
		
	.instr_0x2d: ; dcr l
		add dword [cpu.clk_counter],5
		lflags
		dec l
		sflags
		ret
		
	.instr_0x2e: ; mvi l, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov l, al
		ret
		
	.instr_0x2f: ; cma
		add dword [cpu.clk_counter],4
		not a
		ret
		
	.instr_0x30:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x31: ; lxi sp, word
		add dword [cpu.clk_counter],10
		get_word
		mov sp, ax
		ret
		
	.instr_0x32: ; sta word
		add dword [cpu.clk_counter],13
		get_word
		mov cl, a
		write_byte ax
		ret
		
	.instr_0x33: ; inx sp
		add dword [cpu.clk_counter],5
		inc sp
		ret
		
	.instr_0x34: ; inr m
		add dword [cpu.clk_counter],10
		movzx edi, hl
		lflags
		inc byte [edi+esi]
		sflags
		ret
		
	.instr_0x35: ; dcr m
		add dword [cpu.clk_counter],10
		movzx edi, hl
		lflags
		dec byte [edi+esi]
		sflags
		ret
		
	.instr_0x36: ; mvi m, byte
		add dword [cpu.clk_counter],10
		get_byte
		write_byte hl
		ret
		
	.instr_0x37: ; stc
		add dword [cpu.clk_counter],4
		lflags
		stc
		sflags
		ret
		
	.instr_0x38:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0x39: ; dad sp
		add dword [cpu.clk_counter],5
		mov ax, sp
		add hl, ax
		jnc @f
		lflags
		stc
		sflags
	 @@:	ret
		
	.instr_0x3a: ; lda word
		add dword [cpu.clk_counter],13
		get_word
		read_word ax
		mov a, al
		ret
		
	.instr_0x3b: ; dex sp
		add dword [cpu.clk_counter],5
		dec sp
		ret
		
	.instr_0x3c: ; inr a
		add dword [cpu.clk_counter],5
		lflags
		inc a
		sflags
		ret
		
	.instr_0x3d: ; dcr a
		add dword [cpu.clk_counter],5
		lflags
		dec a
		sflags
		ret
		
	.instr_0x3e: ; mvi a, byte
		add dword [cpu.clk_counter],7
		get_byte
		mov a, al
		ret
		
	.instr_0x3f: ; cmc
		add dword [cpu.clk_counter],4
		lflags
		cmc
		sflags
		ret
		
	.instr_0x40: ; mov b, b
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x41: ; mov b, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov b, al
		ret
		
	.instr_0x42: ; mov b, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov b, al
		ret
		
	.instr_0x43: ; mov b, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov b, al
		ret
		
	.instr_0x44: ; mov b, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov b, al
		ret
		
	.instr_0x45: ; mov b, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov b, al
		ret
		
	.instr_0x46: ; mov b, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov b, al
		ret
		
	.instr_0x47: ; mov b, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov b, al
		ret
		
	.instr_0x48: ; mov c, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov c, al
		ret
		
	.instr_0x49: ; mov c, c
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x4a: ; mov c, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov c, al
		ret
		
	.instr_0x4b: ; mov c, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov c, al
		ret
		
	.instr_0x4c: ; mov c, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov c, al
		ret
		
	.instr_0x4d: ; mov c, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov c, al
		ret
		
	.instr_0x4e: ; mov c, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov c, al
		ret
		
	.instr_0x4f: ; mov c, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov c, al
		ret
		
	.instr_0x50: ; mov d, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov d, al
		ret
		
	.instr_0x51: ; mov d, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov d, al
		ret
		
	.instr_0x52: ; mov d, d
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x53: ; mov d, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov d, al
		ret
		
	.instr_0x54: ; mov d, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov d, al
		ret
		
	.instr_0x55: ; mov d, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov d, al
		ret
		
	.instr_0x56: ; mov d, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov d, al
		ret
		
	.instr_0x57: ; mov d, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov d, al
		ret
		
	.instr_0x58: ; mov e, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov e, al
		ret
		
	.instr_0x59: ; mov e, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov e, al
		ret
		
	.instr_0x5a: ; mov e, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov e, al
		ret
		
	.instr_0x5b: ; mov e, e
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x5c: ; mov e, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov e, al
		ret
		
	.instr_0x5d: ; mov e, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov e, al
		ret
		
	.instr_0x5e: ; mov e, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov e, al
		ret
		
	.instr_0x5f: ; mov e, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov e, al
		ret
		
	.instr_0x60: ; mov h, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov h, al
		ret
		
	.instr_0x61: ; mov h, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov h, al
		ret
		
	.instr_0x62: ; mov h, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov h, al
		ret
		
	.instr_0x63: ; mov h, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov h, al
		ret
		
	.instr_0x64: ; mov h, h
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x65: ; mov h, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov h, al
		ret
		
	.instr_0x66: ; mov h, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov h, al
		ret
		
	.instr_0x67: ; mov h, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov h, al
		ret
		
	.instr_0x68: ; mov l, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov l, al
		ret
		
	.instr_0x69: ; mov l, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov l, al
		ret
		
	.instr_0x6a: ; mov l, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov l, al
		ret
		
	.instr_0x6b: ; mov l, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov l, al
		ret
		
	.instr_0x6c: ; mov l, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov l, al
		ret
		
	.instr_0x6d: ; mov l, l
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x6e: ; mov l, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov l, al
		ret
		
	.instr_0x6f: ; mov l, a
		add dword [cpu.clk_counter],5
		mov al, a
		mov l, al
		ret
		
	.instr_0x70: ; mov m, b
		add dword [cpu.clk_counter],7
		mov cl, b
		write_byte hl
		ret
		
	.instr_0x71: ; mov m, c
		add dword [cpu.clk_counter],7
		mov cl, c
		write_byte hl
		ret
		
	.instr_0x72: ; mov m, d
		add dword [cpu.clk_counter],7
		mov cl, d
		write_byte hl
		ret
		
	.instr_0x73: ; mov m, e
		add dword [cpu.clk_counter],7
		mov cl, e
		write_byte hl
		ret
		
	.instr_0x74: ; mov m, h
		add dword [cpu.clk_counter],7
		mov cl, h
		write_byte hl
		ret
		
	.instr_0x75: ; mov m, l
		add dword [cpu.clk_counter],7
		mov cl, l
		write_byte hl
		ret
		
	.instr_0x76: ; halt
		add dword [cpu.clk_counter],7
		mov byte  [cpu.halt], 1
		ret
		
	.instr_0x77: ; mov m, a
		add dword [cpu.clk_counter],7
		mov cl, a
		write_byte hl
		ret
		
	.instr_0x78: ; mov a, b
		add dword [cpu.clk_counter],5
		mov al, b
		mov a, al
		ret
		
	.instr_0x79: ; mov a, c
		add dword [cpu.clk_counter],5
		mov al, c
		mov a, al
		ret
		
	.instr_0x7a: ; mov a, d
		add dword [cpu.clk_counter],5
		mov al, d
		mov a, al
		ret
		
	.instr_0x7b: ; mov a, e
		add dword [cpu.clk_counter],5
		mov al, e
		mov a, al
		ret
		
	.instr_0x7c: ; mov a, h
		add dword [cpu.clk_counter],5
		mov al, h
		mov a, al
		ret
		
	.instr_0x7d: ; mov a, l
		add dword [cpu.clk_counter],5
		mov al, l
		mov a, al
		ret
		
	.instr_0x7e: ; mov a, m
		add dword [cpu.clk_counter],7
		read_byte hl
		mov a, al
		ret
		
	.instr_0x7f: ; mov a, a
		add dword [cpu.clk_counter],5
		ret
		
	.instr_0x80: ; add b
		add dword [cpu.clk_counter],4
		mov al, b
		add a, al
		sflags
		ret
		
	.instr_0x81: ; add c
		add dword [cpu.clk_counter],4
		mov al, c
		add a, al
		sflags
		ret
		
	.instr_0x82: ; add d
		add dword [cpu.clk_counter],4
		mov al, d
		add a, al
		sflags
		ret
		
	.instr_0x83: ; add e
		add dword [cpu.clk_counter],4
		mov al, e
		add a, al
		sflags
		ret
		
	.instr_0x84: ; add h
		add dword [cpu.clk_counter],4
		mov al, h
		add a, al
		sflags
		ret
		
	.instr_0x85: ; add l
		add dword [cpu.clk_counter],4
		mov al, l
		add a, al
		sflags
		ret
		
	.instr_0x86: ; add m
		add dword [cpu.clk_counter],7
		read_byte hl
		add a, al
		sflags
		ret
		
	.instr_0x87: ; add a
		add dword [cpu.clk_counter],4
		mov al, a
		add a, al
		sflags
		ret
		
	.instr_0x88: ; adc b
		add dword [cpu.clk_counter],4
		lflags
		mov al, b
		adc a, al
		sflags
		ret
		
	.instr_0x89: ; adc c
		add dword [cpu.clk_counter],4
		lflags
		mov al, c
		adc a, al
		sflags
		ret
		
	.instr_0x8a: ; adc d
		add dword [cpu.clk_counter],4
		lflags
		mov al, d
		adc a, al
		sflags
		ret
		
	.instr_0x8b: ; adc e
		add dword [cpu.clk_counter],4
		lflags
		mov al, e
		adc a, al
		sflags
		ret
		
	.instr_0x8c: ; adc h
		add dword [cpu.clk_counter],4
		lflags
		mov al, h
		adc a, al
		sflags
		ret
		
	.instr_0x8d: ; adc l
		add dword [cpu.clk_counter],4
		lflags
		mov al, l
		adc a, al
		sflags
		ret
		
	.instr_0x8e: ; adc m
		add dword [cpu.clk_counter],7
		read_byte hl
		lflags
		adc a, al
		sflags
		ret
		
	.instr_0x8f: ; adc a
		add dword [cpu.clk_counter],4
		lflags
		mov al, a
		adc a, al
		sflags
		ret
		
	.instr_0x90: ; sub b
		add dword [cpu.clk_counter],4
		mov al, b
		sub a, al
		sflags
		ret
		
	.instr_0x91: ; sub c
		add dword [cpu.clk_counter],4
		mov al, c
		sub a, al
		sflags
		ret
		
	.instr_0x92: ; sub d
		add dword [cpu.clk_counter],4
		mov al, d
		sub a, al
		sflags
		ret
		
	.instr_0x93: ; sub e
		add dword [cpu.clk_counter],4
		mov al, e
		sub a, al
		sflags
		ret
		
	.instr_0x94: ; sub h
		add dword [cpu.clk_counter],4
		mov al, h
		sub a, al
		sflags
		ret
		
	.instr_0x95: ; sub l
		add dword [cpu.clk_counter],4
		mov al, l
		sub a, al
		sflags
		ret
		
	.instr_0x96: ; sub m
		add dword [cpu.clk_counter],7
		read_byte hl
		sub a, al
		sflags
		ret
		
	.instr_0x97: ; sub a
		add dword [cpu.clk_counter],4
		mov al, a
		sub a, al
		sflags
		ret
		
	.instr_0x98: ; sbb b
		add dword [cpu.clk_counter],4
		lflags
		mov al, b
		sbb a, al
		sflags
		ret
		
	.instr_0x99: ; sbb c
		add dword [cpu.clk_counter],4
		lflags
		mov al, c
		sbb a, al
		sflags
		ret
		
	.instr_0x9a: ; sbb d
		add dword [cpu.clk_counter],4
		lflags
		mov al, d
		sbb a, al
		sflags
		ret
		
	.instr_0x9b: ; sbb e
		add dword [cpu.clk_counter],4
		lflags
		mov al, e
		sbb a, al
		sflags
		ret
		
	.instr_0x9c: ; sbb h
		add dword [cpu.clk_counter],4
		lflags
		mov al, h
		sbb a, al
		sflags
		ret
		
	.instr_0x9d: ; sbb l
		add dword [cpu.clk_counter],4
		lflags
		mov al, l
		sbb a, al
		sflags
		ret
		
	.instr_0x9e: ; sbb m
		add dword [cpu.clk_counter],7
		read_byte hl
		lflags
		sbb a, al
		sflags
		ret
		
	.instr_0x9f: ; sbb a
		add dword [cpu.clk_counter],4
		lflags
		mov al, a
		sbb a, al
		sflags
		ret
		
	.instr_0xa0: ; ana b
		add dword [cpu.clk_counter],4
		mov al, b
		and a, al
		sflags
		ret
		
	.instr_0xa1: ; ana c
		add dword [cpu.clk_counter],4
		mov al, c
		and a, al
		sflags
		ret
		
	.instr_0xa2: ; ana d
		add dword [cpu.clk_counter],4
		mov al, d
		and a, al
		sflags
		ret
		
	.instr_0xa3: ; ana e
		add dword [cpu.clk_counter],4
		mov al, e
		and a, al
		sflags
		ret
		
	.instr_0xa4: ; ana h
		add dword [cpu.clk_counter],4
		mov al, h
		and a, al
		sflags
		ret
		
	.instr_0xa5: ; ana l
		add dword [cpu.clk_counter],4
		mov al, l
		and a, al
		sflags
		ret
		
	.instr_0xa6: ; ana m
		add dword [cpu.clk_counter],7
		read_byte hl
		and a, al
		sflags
		ret
		
	.instr_0xa7: ; ana a
		add dword [cpu.clk_counter],4
		mov al, a
		and a, al
		sflags
		ret
		
	.instr_0xa8: ; xra b
		add dword [cpu.clk_counter],4
		mov al, b
		xor a, al
		sflags
		ret
		
	.instr_0xa9: ; xra c
		add dword [cpu.clk_counter],4
		mov al, c
		xor a, al
		sflags
		ret
		
	.instr_0xaa: ; xra d
		add dword [cpu.clk_counter],4
		mov al, d
		xor a, al
		sflags
		ret
		
	.instr_0xab: ; xra e
		add dword [cpu.clk_counter],4
		mov al, e
		xor a, al
		sflags
		ret
		
	.instr_0xac: ; xra h
		add dword [cpu.clk_counter],4
		mov al, h
		xor a, al
		sflags
		ret
		
	.instr_0xad: ; xra l
		add dword [cpu.clk_counter],4
		mov al, l
		xor a, al
		sflags
		ret
		
	.instr_0xae: ; xra m
		add dword [cpu.clk_counter],7
		read_byte hl
		xor a, al
		sflags
		ret
		
	.instr_0xaf: ; xra a
		add dword [cpu.clk_counter],4
		mov al, a
		xor a, al
		sflags
		ret
		
	.instr_0xb0: ; ora b
		add dword [cpu.clk_counter],4
		mov al, b
		or a, al
		sflags
		ret
		
	.instr_0xb1: ; ora c
		add dword [cpu.clk_counter],4
		mov al, c
		or a, al
		sflags
		ret
		
	.instr_0xb2: ; ora d
		add dword [cpu.clk_counter],4
		mov al, d
		or a, al
		sflags
		ret
		
	.instr_0xb3: ; ora e
		add dword [cpu.clk_counter],4
		mov al, e
		or a, al
		sflags
		ret
		
	.instr_0xb4: ; ora h
		add dword [cpu.clk_counter],4
		mov al, h
		or a, al
		sflags
		ret
		
	.instr_0xb5: ; ora l
		add dword [cpu.clk_counter],4
		mov al, l
		or a, al
		sflags
		ret
		
	.instr_0xb6: ; ora m
		add dword [cpu.clk_counter],7
		read_byte hl
		or a, al
		sflags
		ret
		
	.instr_0xb7: ; ora a
		add dword [cpu.clk_counter],4
		mov al, a
		or a, al
		sflags
		ret
		
	.instr_0xb8: ; cmp b
		add dword [cpu.clk_counter],4
		mov al, b
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xb9: ; cmp c
		add dword [cpu.clk_counter],4
		mov al, c
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xba: ; cmp d
		add dword [cpu.clk_counter],4
		mov al, d
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xbb: ; cmp e
		add dword [cpu.clk_counter],4
		mov al, e
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xbc: ; cmp h
		add dword [cpu.clk_counter],4
		mov al, h
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xbd: ; cmp l
		add dword [cpu.clk_counter],4
		mov al, l
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xbe: ; cmp m
		add dword [cpu.clk_counter],7
		read_byte hl
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xbf: ; cmp a
		add dword [cpu.clk_counter],4
		mov al, a
		lflags
		cmp a, al
		sflags
		ret
		
	.instr_0xc0: ; rnz
		add dword [cpu.clk_counter],5
		lflags
		jz @f ; no return on zero
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xc1: ; pop b
		add dword [cpu.clk_counter],10
		pop_cx
		mov bc, cx
		ret
		
	.instr_0xc2: ; jnz word
		add dword [cpu.clk_counter],10
		get_word
		mov cx, ax
		lflags
		jz @f  ; skip jmp if zero
		mov pc, cx
	  @@:	ret
		
	.instr_0xc3: ; jmp word
		add dword [cpu.clk_counter],10
		get_word
		mov pc, ax
		ret
		
	.instr_0xc4: ; cnz word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jz @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	  @@:	add esp, 2
		ret
		
	.instr_0xc5: ; push b
		add dword [cpu.clk_counter],11
		mov cx, bc
		push_cx
		ret
		
	.instr_0xc6: ; adi byte
		add dword [cpu.clk_counter],7
		get_byte
		add a, al
		sflags
		ret
		
	.instr_0xc7: ; rst 00h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0
		ret
		
	.instr_0xc8: ; rz
		add dword [cpu.clk_counter],5
		lflags
		jnz @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xc9: ; ret
		add dword [cpu.clk_counter],10
		pop_cx
		mov pc, cx
		ret
		
	.instr_0xca: ; jz word
		add dword [cpu.clk_counter],10
		get_word
		mov cx, ax
		lflags
		jnz @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xcb:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0xcc: ; cz word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jnz @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xcd: ; call word
		add dword [cpu.clk_counter],17
		get_word
		push ax
		mov cx, pc
		push_cx
		pop pc
		ret
		
	.instr_0xce: ; aci byte
		add dword [cpu.clk_counter],7
		get_byte
		lflags
		adc a, al
		sflags
		ret
		
	.instr_0xcf: ; rst 08h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x8
		ret
		
	.instr_0xd0: ; rnc
		add dword [cpu.clk_counter],5
		lflags
		jc @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xd1: ; pop d
		add dword [cpu.clk_counter],10
		pop_cx
		mov de, cx
		ret
		
	.instr_0xd2: ; jnc word
		add dword [cpu.clk_counter],10
		get_word
		mov cx, ax
		lflags
		jc @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xd3: ; out byte
		add dword [cpu.clk_counter],10
		get_byte
		movzx rax, al
		imul rax, 8
		mov  rdi, rbx
		mov  byte [cpu.wr], 1
		call qword [rax+cpu.IOPorts]
		mov  byte [cpu.wr],0
		ret
		
	.instr_0xd4: ; cnc word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jc @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop  pc
		ret
		add esp, 2
	 @@:	ret
		
	.instr_0xd5: ; push d
		add dword [cpu.clk_counter],11
		mov cx, de
		push_cx
		ret
		
	.instr_0xd6: ; sui byte
		add dword [cpu.clk_counter],7
		get_byte
		sub a, al
		sflags
		ret
		
	.instr_0xd7: ; rst 10h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x10
		ret
		
	.instr_0xd8: ; rc
		add dword [cpu.clk_counter],5
		lflags
		jnc @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xd9:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0xda: ; jc word
		add dword [cpu.clk_counter],11
		get_word
		mov cx, ax
		lflags
		jnc @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xdb: ; in byte
		add dword [cpu.clk_counter],10
		get_byte
		movzx rax, al
		imul rax, 8
		mov  rdi, rbx
		call qword [rax+cpu.IOPorts]
		ret
		
	.instr_0xdc: ; cc word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jnc @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xdd:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0xde: ; sbi byte
		add dword [cpu.clk_counter],7
		get_byte
		lflags
		sbb a, al
		sflags
		ret
		
	.instr_0xdf: ; rst 18h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x18
		ret
		
	.instr_0xe0: ; rpo
		add dword [cpu.clk_counter],5
		lflags
		jpe @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xe1: ; pop h
		add dword [cpu.clk_counter],10
		pop_cx
		mov hl, cx
		ret
		
	.instr_0xe2: ; jpo word
		add dword [cpu.clk_counter],10
		get_word
		lflags
		jpe @f
		mov pc, ax
	 @@:	ret
		
	.instr_0xe3: ; xthl
		add dword [cpu.clk_counter],18
		pop_cx
		xchg cx, hl
		push_cx
		ret
		
	.instr_0xe4: ; cpo word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jpe @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xe5: ; push h
		add dword [cpu.clk_counter],11
		mov cx, hl
		push_cx
		ret
		
	.instr_0xe6: ; ani byte
		add dword [cpu.clk_counter],7
		get_byte
		and a, al
		sflags
		ret
		
	.instr_0xe7: ; rst 20h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x20
		ret
		
	.instr_0xe8: ; rpe
		add dword [cpu.clk_counter],5
		lflags
		jpo @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xe9: ; pchl
		add dword [cpu.clk_counter],5
		mov ax, hl
		mov pc, ax
		ret
		
	.instr_0xea: ; jpe word
		add dword [cpu.clk_counter],10
		get_word
		mov cx, ax
		lflags
		jpo @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xeb: ; xchg
		add dword [cpu.clk_counter],4
		mov ax, hl
		xchg ax, de
		mov hl, ax
		ret
		
	.instr_0xec: ; cpe word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jpo @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xed:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0xee: ; xri byte
		add dword [cpu.clk_counter],7
		get_byte
		xor a, al
		sflags
		ret
		
	.instr_0xef: ; rst 28h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x28
		ret
		
	.instr_0xf0: ; rp
		add dword [cpu.clk_counter],5
		lflags
		jle @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xf1: ; pop psw
		add dword [cpu.clk_counter],10
		pop_cx
		mov a, ch
		mov [cpu.reg_f], cl
		ret
		
	.instr_0xf2: ; jp word
		add dword [cpu.clk_counter],10
		get_word
		mov cx, ax
		lflags
		jle @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xf3: ; di
		add dword [cpu.clk_counter],4
		mov [cpu.int_enabled], 0
		ret
		
	.instr_0xf4: ; cp word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jle @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xf5: ; push psw
		add dword [cpu.clk_counter],11
		mov cl, [cpu.reg_f]
		mov ch, a
		push_cx
		ret
		
	.instr_0xf6: ; ori byte
		add dword [cpu.clk_counter],7
		get_byte
		or a, al
		sflags
		ret
		
	.instr_0xf7: ; rst 30h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x30
		ret
		
	.instr_0xf8: ; rm
		add dword [cpu.clk_counter],5
		lflags
		jge @f
		add dword [cpu.clk_counter],11
		pop_cx
		mov pc, cx
	 @@:	ret
		
	.instr_0xf9: ; sphl
		add dword [cpu.clk_counter],5
		mov ax, hl
		mov sp, ax
		ret
		
	.instr_0xfa: ; jm word
		add dword [cpu.clk_counter],10
		get_word
		lflags
		jge @f
		mov pc, cx
	 @@:	ret
		
	.instr_0xfb: ; ei
		add dword [cpu.clk_counter],4
		mov [cpu.int_enabled], 1
		ret
		
	.instr_0xfc: ; cm word
		add dword [cpu.clk_counter],11
		get_word
		push ax
		lflags
		jge @f
		add dword [cpu.clk_counter],17
		mov cx, pc
		push_cx
		pop pc
		ret
	 @@:	add esp, 2
		ret
		
	.instr_0xfd:
		add dword [cpu.clk_counter],4
		ret
		
	.instr_0xfe: ; cpi byte
		add dword [cpu.clk_counter],7
		get_byte
		cmp a, al
		sflags
		ret
		
	.instr_0xff: ; rst 38h
		add dword [cpu.clk_counter],11
		mov cx, pc
		push_cx
		mov pc, 0x38
		ret