; Franciz Emmanuelle Angelo L. Esperanza, Charles Joseph V. Hinolan S14
section .text
bits 64
default rel
global asm_kernel_start
asm_kernel_start:
push rsi
push rbp
mov rbp,rsp
add rbp, 16
add rbp, 8
mov rsi, [rbp+32]
mov r12, rsi
operate:
	dec rcx
	js end
	mov r11, rcx
	imul r11, 4
	movss xmm0,[r8+r11]
	movss xmm5,[r9+r11]
	mulss xmm0,xmm1
	addss xmm5, xmm0
	movss [r12+r11],xmm5
	jnz operate
end:
pop rbp
pop rsi
ret
