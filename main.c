#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "c_kernel.h"

extern void c_kernel_start(int n, float A, float* X, float* Y, float* Z);
extern void asm_kernel_start(int n, float A, float* X, float* Y, float* Z);

void display_results(int n, float* Z) {
	if (n < 10) {
		for (int i = 0; i < n; i++) {
			printf("%.2f ", Z[i]);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			printf("%.2f ", Z[i]);
		}
	}
}

int main(int argc, char* argv[]) {

	int n = 1 << 20;			// vector size
	float A = 2.0;				// scalar variable

	float* X = (float*)malloc(n * sizeof(float));
	float* Y = (float*)malloc(n * sizeof(float));
	float* Z = (float*)malloc(n * sizeof(float));

	/* Fill vector X and Y */

	for (int i = 0; i < n; i++) {
		X[i] = 100.0 + i;
		Y[i] = 110.0 + i;
	}

	/* C Implementation */
	printf("C calling C:\n");
	clock_t start1, end1;

	start1 = clock();			// start the timer
	c_kernel_start(n, A, X, Y, Z);
	end1 = clock();				// end the timer

	display_results(n, Z);
	printf("\n");

	double exec_time = (double)(end1 - start1) / (double)CLOCKS_PER_SEC;
	printf("\nExecution time of C Implementation: %.5f seconds\n", exec_time);

	/* x86_64 Implementation */
	printf("\nx86-64 calling C:\n");

	clock_t start2, end2;

	start2 = clock();
	asm_kernel_start(n, A, X, Y, Z);
	end2 = clock();

	display_results(n, Z);
	printf("\n");
	double asm_exec_time = (double)(end2 - start2) / (double)CLOCKS_PER_SEC;
	printf("\nExecution time of x86-64 Implementation: %.5f seconds\n", asm_exec_time);
	
	free(X);
	free(Y);
	free(Z);
	return 0;
}
