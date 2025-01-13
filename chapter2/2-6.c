#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ggg(a, b) {
	if (b == 0) {
		return a;
	}
	else {
		if (a % b >= b) {
			return ggg(a % b, b);
		}
		else {
			return ggg(b, a % b);
		}
	}
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a >= b) {
		printf("%d", ggg(a, b));
	}
	else {
		printf("%d", ggg(b, a));
	}
	return 0;
}
