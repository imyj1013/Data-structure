#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N, xarr[100], c, ttt;
	int* baggum;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &xarr[i]);
	}
	scanf("%d", &c);
	baggum = (int*)malloc(c * sizeof(int));
	if (baggum == NULL) {
		printf("Not enough memory");
		return -1;
	}
	for (int i = 0; i < c; i++) {
		scanf("%d", &baggum[i]);
	}
	ttt = xarr[baggum[c-1]];
	for (int i = c-1; i >=2; i--) {
		xarr[baggum[i]] = xarr[baggum[i-1]];
	}
	xarr[baggum[1]] = ttt;
	for (int i = 0; i < N; i++) {
		printf(" %d", xarr[i]);
	}
	free(baggum);
	return 0;
}
