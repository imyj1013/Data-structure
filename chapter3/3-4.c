#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N, M, c = 1, i = 0, j = 0;
	int ar[100][100] = { 0, };
	scanf("%d %d", &N, &M);
	while (c <= N * M) {
		while (ar[i][j] == 0 && j < M)
			ar[i][j++] = c++;
		j--;
		i++;

		while (ar[i][j] == 0 && i < N)
			ar[i++][j] = c++;
		i--;
		j--;

		while (ar[i][j] == 0 && j >= 0)
			ar[i][j--] = c++;
		j++;
		i--;

		while (ar[i][j] == 0 && i >= 0)
			ar[i--][j] = c++;
		i++;
		j++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}
