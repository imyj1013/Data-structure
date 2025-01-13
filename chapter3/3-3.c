#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n, c=1;
	scanf("%d", &n);
	for (int i = 0; i < n / 2; i++) {
		for (int i = 0; i < n; i++) {
			printf(" %d", c);
			c++;		
		}
		printf("\n");
		c += n - 1;
		for (int i = 0; i < n; i++) {
			printf(" %d", c);
			c--;
		}
		printf("\n");
		c += n + 1;
	}
	if (n % 2 != 0) {
		for (int i = 0; i < n; i++) {
			printf(" %d", c);
			c++;
		}
	}
	return 0;
}
