#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int N, M, i = 0, j = 0, c = 1, p=0, q=0, r=0;
	int ar[100][100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ar[i][j] = 0;
		}
	}

	while (c <= N*M) {
		ar[i][j] = c;
		c++;
		i++;
		j--;
		if (i == N || j == -1) {
			if (q == M-1) {
				p++;
				i = p;
				j = q;
			}
			else {
				q++;
				i = p;
				j = q;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", ar[i][j]);
		}
		printf("\n");
	}

	return 0;
}
