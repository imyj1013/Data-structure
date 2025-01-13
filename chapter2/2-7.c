#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(char sss[], char ccc, int n) {
	if (n < 0) {
		return 0;
	}
	else {
		if (sss[n] == ccc) {
			return count(sss, ccc, n - 1) + 1;
		}
		else {
			return count(sss, ccc, n - 1);
		}
	}
}

int main() {
	char sss[101], ccc;
	scanf("%s", sss);
	getchar();
	scanf("%c", &ccc);
	printf("%d", count(sss, ccc, strlen(sss)));
	return 0;
}
