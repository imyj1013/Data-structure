#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prottt = -1;
int N = 0;

void push(char* sta, char ccc) {

	prottt++;
	sta[prottt] = ccc;
}


char pop(char* sta) {

	char ret = sta[prottt];
	prottt--;
	return ret;
}

int main() {
	char sta[1000];
	char pro[1000];
	int result = 1;
	gets(sta);
	for (int i = 0; i < 1000; i++) {
		if (sta[i] == '\0') {
			if (prottt != -1) {
				result = -1;
			}
			break;
		}

		if (sta[i] == '(' || sta[i] == '{' || sta[i] == '[') {
			N++;
			push(pro, sta[i]);
		}
		else if (sta[i] == ')') {
			N++;
			if (prottt == -1) {
				result = -1;
			}
			if (pop(pro) != '(') {
				result = -1;
			}

		}
		else if (sta[i] == '}') {
			N++;
			if (prottt == -1) {
				result = -1;
			}
			if (pop(pro) != '{') {
				result = -1;
			}

		}
		else if (sta[i] == ']') {
			N++;
			if (prottt == -1) {
				result = -1;
			}
			if (pop(pro) != '[') {
				result = -1;
			}

		}

	}

	if (result == 1) {
		printf("OK_%d", N);
	}
	else {
		printf("Wrong_%d", N);
	}
	return 0;
}
