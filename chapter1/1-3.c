#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* prefixAverages1(int* X, int n) 
{
	int* A;
	A = (int*)malloc(n * sizeof(int));
	if (A == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		double sss = 0;
		for (int j = 0; j <= i; j++) {
			sss += X[j];
		}
		A[i] = (int)(sss / (i + 1)+0.5);
	}
	

	return A;
}

int* prefixAverages2(int* X, int n)
{
	int* A;
	double sss = 0;
	A = (int*)malloc(n * sizeof(int));
	if (X == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		sss += X[i];
		A[i] = (int)(sss / (i + 1)+0.5);
	}
	

	return A;
}

int main() {
	int n;
	int* X, *A;
	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	if (X == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &X[i]);
	}

	A = prefixAverages1(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	free(X);
	free(A);
	return 0;
}
