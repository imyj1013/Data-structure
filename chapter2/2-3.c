#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ddd(int n) {
	if (n >= 1) {
		printf("%d\n", n % 10);
		ddd(n / 10);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	ddd(N);
	return 0;
}
