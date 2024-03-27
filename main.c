#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void asm_kernel_start();

void c_kernel_start(int n, float A, float* X, float* Y, float* Z) {
	for (int i = 0; i < n; i++) {
		Z[i] = A * X[i] + Y[i];
	}
}

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
	clock_t start1, end1;

	start1 = clock();			// start the timer
	c_kernel_start(n, A, X, Y, Z);
	end1 = clock();				// end the timer

	display_results(n, Z);

	double exec_time = (double)(end1 - start1) / (double)CLOCKS_PER_SEC;
	printf("\nExecution time of C Implementation: %.5f seconds\n", exec_time);

	/* x86_64 Implementation */
	asm_kernel_start();

	free(X);
	free(Y);
	free(Z);
	return 0;
}
