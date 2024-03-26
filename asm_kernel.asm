section .data
msg db "Hi, this is the ASM kernel. Thank yewww",13,10,0

section .text
bits 64
default rel
global asm_kernel_start

extern printf

asm_kernel_start:
	sub rsp, 8*5
	mov rcx, msg
	call printf
	add rsp, 8*5
	ret
