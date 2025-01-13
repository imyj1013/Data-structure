#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}NODE;

typedef struct stack {
	NODE* top;
	int cnt;
}STACK;

int cal(int a, int b, int t) {
	switch (t) {
	case '+': return a + b;
	case '-': return a - b;
	case '/': return a / b;
	case '*': return a * b;
	}
}

int main() {
	int n;
	char s[101];


	scanf("%d", &n);
	getchar();

	while (n != 0) {
		STACK* stack = (STACK*)malloc(sizeof(STACK));
		stack->top = NULL;
		stack->cnt = 0;
		scanf("%s", s);
		getchar();

		for (int i = 0; s[i]; i++) {
			if (s[i] >= '0' && s[i] <= '9') {

				NODE* node = (NODE*)malloc(sizeof(NODE));
				node->data = (int)s[i]-'0';
				node->next = stack->top;
				stack->top = node;


			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {

				int a, b;
				a = stack->top->data;
				b = stack->top->next->data;
				stack->top = stack->top->next->next;


				NODE* node = (NODE*)malloc(sizeof(NODE));
				node->data = cal(b, a, s[i]);
				node->next = stack->top;
				stack->top = node;

			}
			

		}

		printf("%d\n", stack->top->data);

		n--;
	}

	return 0;
}
