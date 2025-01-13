#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char data;
	int level;
	struct node* next;
}NODE;

typedef struct stack {
	NODE* top;
	int cnt;
}STACK;

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
			if (s[i] >= 'A' && s[i] <= 'Z') {     // 피연산자
				printf("%c", s[i]);
			}
			else if (s[i] == ')') {              // 닫는 괄호
				NODE* p = stack->top;
				while (p->data != '(') {
					printf("%c", p->data);
					if (p->data == '&' || p->data == '|') printf("%c", p->data);
					p = p->next;
					free(stack->top);
					stack->top = p;
				}
				stack->top = p->next;
			}
			else {
				int level;                              // 우선순위 판별
				switch (s[i]) {
				case '(': level = 7; break;
				case '!': level = 6; break;
				case '*': case '/': level = 5; break;
				case '+': case '-':
					level = 4;
					if (i == 0 || s[i - 1] == '&' || s[i - 1] == '|' || s[i - 1] == '<' || s[i - 1] == '>' || s[i - 1] == '(' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '+' || s[i - 1] == '-') {
						level = 6;
						break;
					}
				case '>': case '<': level = 3; break;
				case '&': level = 2; i++; break;
				case '|': level = 1; i++; break;
				}

				if (stack->top == NULL) {                         // 스택이 비어있으면 연산자 저장
					NODE* node = (NODE*)malloc(sizeof(NODE));
					node->data = s[i];
					node->next = NULL;
					stack->top = node;
					stack->top->level = level;
				}

				else {

					if (stack->top->level < level) {                 // top 연산자보다 우선순위가 높으면 저장
						NODE* node = (NODE*)malloc(sizeof(NODE));
						node->data = s[i];
						node->next = stack->top;
						stack->top = node;
						stack->top->level = level;
					}
					else {                                           // top 연산자보다 우선순위가 낮을 때
						NODE* p = stack->top;
						while (stack->top->level >= level) {
							if (p->data == '(') break;
							printf("%c", p->data);
							if (p->data == '&' || p->data == '|') printf("%c", p->data);
							p = p->next;
							free(stack->top);
							stack->top = p;
							if (p == NULL) break;
						}

						NODE* node = (NODE*)malloc(sizeof(NODE));
						node->data = s[i];
						node->next = stack->top;
						stack->top = node;
						stack->top->level = level;

					}

				}

			}

		}

		NODE* p = stack->top;                                    // 스택에 남아있는 연산자 다 출력
		while (p != NULL) {
			if (p->data == '(') break;
			printf("%c", p->data);
			if (p->data == '&' || p->data == '|') printf("%c", p->data);
			p = p->next;
			free(stack->top);
			stack->top = p;
		}
		printf("\n");

		n--;
	}

	return 0;
}
