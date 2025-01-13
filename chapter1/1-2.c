#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mostOnes(int** A, int n) {
	int result, i = 0, j = 0;

	while (i < n && i < n) {
		
		if (A[i][j] == 0) {
			i++;
		}
		else {
			result = i;
			j++;
		}
	}
	return result;
}

int main() {
	int n;
	int** A;
	scanf("%d", &n);
	A = (int**)malloc(n * sizeof(int*));
	if (A == NULL) {
		printf("Not enough memory");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		if (A[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d", mostOnes(A, n));
	for (int i = 0; i < n; i++) {
	    free(A[i]);
	}
	free(A);
	return 0;
}
