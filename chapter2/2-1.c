#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum(int a) {
	if (a > 1) {
		return sum(a - 1) + a;
	}
	else if (a == 1) {
		return 1;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d", sum(N));
	return 0;
}
