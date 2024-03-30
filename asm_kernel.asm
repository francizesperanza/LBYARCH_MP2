; Franciz Emmanuelle Angelo L. Esperanza, Charles Joseph V. Hinolan S14
section .data

section .text
bits 64
default rel

global asm_kernel_start
extern printf

asm_kernel_start:
;rcx is int n, xmm1 is float A, r8 is X array, r9 is Y,Z is r10
push rsi
push rbp
mov rbp,rsp
add rbp, 16
add rbp, 8
xor rax,rax
	
mov rsi, [rbp+32]
mov r10, rsi
	
	
	operate:
		mov r12,rcx
		dec r12					;makes it loop to first element
		movss xmm8,[r8+4*r12]	;xmm8 is the element to be multiplied to A

		;multiplication
		vmulss xmm5,xmm8,xmm1
		movss [r10+4*r12],xmm5

		;addition
		movss xmm8,[r10+4*r12]
		movss xmm9,[r9+4*r12]
		vaddss xmm5, xmm9, xmm8
		movss [r10+4*r12],xmm5

	LOOP operate

pop rbp
pop rsi
ret
