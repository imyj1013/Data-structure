#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mmm(int pi[], int n) {
	if (n == 0) {
		return pi[n];
	}
	else {
		if (mmm(pi, n - 1) > pi[n]) {
			return mmm(pi, n - 1);
		}
		else {
			return pi[n];
		}
	}
}

int main() {
	int N;
	int pi[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &pi[i]);
	}
	printf("%d", mmm(pi, N-1));
	return 0;
}
