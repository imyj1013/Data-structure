#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ttt = -1;
int N;

void push(char* sta, char ccc) {

	if (ttt == N-1) {
		printf("Stack FULL\n");
		return;
	}

	ttt++;
	sta[ttt] = ccc;
}

char pop(char* sta) {

	if (ttt == -1) {
		printf("Stack Empty\n");
		return;
	}

	char ret = sta[ttt];
	ttt--;
	return ret;
}

void peek(char* sta) {

	if (ttt == -1) {
		printf("Stack Empty\n");
		return;
	}

	printf("%c\n", sta[ttt]);
}

void duplication(char* sta) {

	if (ttt > N-2) {
		printf("Stack FULL\n");
		return;
	}
	
	char tmp = pop(sta);
	push(sta, tmp);
	push(sta, sta[ttt]);
}

void upRotate(char* sta, int n) {

	if (n <= 1 || n > N) {
		return;
	}
	if (n > ttt + 1) {
		return;
	}

	char tmp = sta[ttt];
	for (int i = 1; i < n; i++) {
		sta[ttt - i + 1] = sta[ttt - i];
	}

	sta[ttt - n+1] = tmp;
}

void downRotate(char* sta, int n) {

	if (n <= 1 || n > N) {
		return;
	}
	if (n > ttt + 1) {
		return;
	}
	char tmp = sta[ttt -n+1];

	for (int i = n; i > 1; i--) {
		sta[ttt - i + 1] = sta[ttt - i+2];
	}
	sta[ttt] = tmp;
}

void print(char* sta) {

	if (ttt < 0) {
		return;
	}
	for (int i = ttt; i >= 0; i--) {
		printf("%c", sta[i]);
	}
	printf("\n");
}

int main() {
	int cnt, t=-1, n;
	char ccc;
	char* sta;
	char menu[6];

	scanf("%d %d", &N, &cnt);
	getchar();

	sta = (char*)malloc((N)*sizeof(char));
	if (sta == NULL) {
		return -1;
	}

	for (int i = 0; i < cnt; i++) {
		scanf("%s", menu);
		getchar();

		if (strcmp(menu, "PUSH") == 0) {

			scanf("%c", &ccc);
			getchar();
			push(sta, ccc);

		}
		else if (strcmp(menu, "POP") == 0) {

			char poptmp = pop(sta);

		}
		else if (strcmp(menu, "PEEK") == 0) {

			peek(sta);

		}
		else if (strcmp(menu, "DUP") == 0) {

			duplication(sta);

		}
		else if (strcmp(menu, "UpR") == 0) {

			scanf("%d", &n);
			getchar();
			upRotate(sta, n);

		}
		else if (strcmp(menu, "DownR") == 0) {

			scanf("%d", &n);
			getchar();
			downRotate(sta, n);

		}
		else if (strcmp(menu, "PRINT") == 0) {

			print(sta);

		}
	}

	free(sta);
	return 0;
}
