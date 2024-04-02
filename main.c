// Franciz Emmanuelle Angelo L. Esperanza, Charles Joseph V. Hinolan S14
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "c_kernel.h"

extern void c_kernel_start(int n, float A, float* X, float* Y, float* Z);
extern void asm_kernel_start(int n, float A, float* X, float* Y, float* Z);

void display_results(int n, float* Z) {
	for (int i = 0; i < 10; i++) {
		printf("%.2f ", Z[i]);
	}
}

float random_float(float min, float max) {
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}

void version_testing (int n){
	float max = 1000.0;
	float min = 0.0;

	float A = random_float(min, max);				// scalar variable
	printf("A = %.2f\n", A);

	float* X = (float*)malloc(n * sizeof(float));
	float* Y = (float*)malloc(n * sizeof(float));
	float* Z = (float*)malloc(n * sizeof(float));

	/* Fill vector X and Y */

	

	for (int i = 0; i < n; i++) {
		X[i] = random_float(min, max);
		Y[i] = random_float(min, max);
	}

	printf("Vector Size: %d\n", n);

	/* C Implementation */
	printf("C calling C:\n");
	clock_t start1, end1, start2, end2;

	start1 = clock();			// start the timer
	c_kernel_start(n, A, X, Y, Z);
	end1 = clock();				// end the timer

	display_results(n, Z);
	printf("\n");

	double exec_time = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\nExecution time of C Implementation: %.5f seconds\n", exec_time);

	/* x86_64 Implementation */
	printf("\nx86-64 calling C:\n");

	start2 = clock();
	asm_kernel_start(n, A, X, Y, Z);
	end2 = clock();

	display_results(n, Z);
	printf("\n");
	double asm_exec_time = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\nExecution time of x86-64 Implementation: %.5f seconds\n", asm_exec_time);

	free(X);
	free(Y);
	free(Z);
}

int main(int argc, char* argv[]) {
	srand(time(NULL));

	int n_1 = 1 << 20;
	int n_2 = 1 << 24;
	int n_3 = 1 << 28;

	printf("\n2^20\n\n");
	version_testing(n_1);
	printf("\n-------------------------------\n\n");

	printf("\n2^24\n\n");
	version_testing(n_2);
	printf("\n-------------------------------\n\n");

	printf("\n2^28\n\n");
	version_testing(n_3);
	printf("\n-------------------------------\n\n");


	return 0;
}
