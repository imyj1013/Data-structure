#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N, arrr[100], c;
	int* duizip;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arrr[i]);
	}
	scanf("%d", &c);
	duizip = (int*)malloc(2*c*sizeof(int));
	if (duizip == NULL) {
		printf("Not enough memory");
		return -1;
	}
	for (int i = 0; i < 2 * c; i++) {
		scanf("%d", &duizip[i]);
	}
	for (int i = 0; i < c; i++) {
		for (int j = duizip[i * 2], k = duizip[i * 2 + 1]; j <= (duizip[i * 2 + 1]+ duizip[i * 2])/2; j++, k--) {
			int ttt = arrr[j];
			arrr[j] = arrr[k];
			arrr[k] = ttt;
		}
	}
	for (int i = 0; i < N; i++) {
		printf(" %d", arrr[i]);
	}
	free(duizip);

	return 0;
}
