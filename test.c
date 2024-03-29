#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void asm_kernel_start();


void cFunc(int n, double A, double* X, double* Y, double* Z) {
	for (int i = 0; i < n; i++) {
		Z[i] = A * X[i] + Y[i];
	}
	for (int j = 0;j < n; j++) {
		printf("%f ", Z[j]);
	}
	
}

int main() {
	printf("hi\n");
	asm_kernel_start();
	return 0;
}