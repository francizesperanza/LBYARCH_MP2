#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asm_kernel_start();

int main(int argc, char* argv[]) {
	asm_kernel_start();
	return 0;
}
