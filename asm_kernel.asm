section .data
;msg db "Hi, this is the ASM kernel. Thank yewww",13,10,0
varn dd 3
vara dq 2.0
varx dq 1.0,2.0,3.0
vary dq 11.0,12.0,13.0
varz dq 0,0,0

section .text
bits 64
default rel
global asm_kernel_start

extern printf
extern cFunc

asm_kernel_start:
	sub rsp, 8*15
	mov rcx, [varn]
	mov rdx, [vara]
	lea r8, [varx]
	lea r9, [vary]
	lea rax, [varz]
	call cFunc
	add rsp, 8*15
	ret
