#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hhh(int n, char fr, char a, char t) {
	if (n == 1) {
		printf("%c %c\n", fr, t);
	}
	else {
		hhh(n - 1, fr, t, a);
		printf("%c %c\n", fr, t);
		hhh(n - 1, a, fr, t);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	hhh(N, 'A', 'B', 'C');
	return 0;
}
