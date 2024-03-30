// Franciz Emmanuelle Angelo L. Esperanza, Charles Joseph V. Hinolan S14
#include "c_kernel.h"

void c_kernel_start(int n, float A, float* X, float* Y, float* Z) {
	for (int i = 0; i < n; i++) {
		Z[i] = A * X[i] + Y[i];
	}
}