#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Que {
	int* Q;
	int f;
	int r;
}Que;

void initQueue(Que* q, int N) {
	q->Q = (int*)malloc(sizeof(int) * N);
	q->f = 0;
	q->r = 0;
	for (int i = 0; i < N; i++) {
		q->Q[i] = 0;
	}
}

void enqueue(Que* q, int N, int e) {
	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;
}

void dequeue(Que* q, int N) {
	q->f = (q->f + 1) % N;
	q->Q[q->f] = 0;
	return;
}

void PRINT(Que* q, int N) {
	for (int i = 0; i < N; i++) {
		printf(" %d", q->Q[i]);
	}
	printf("\n");
}

int main() {
	int q, n, e, nnn;
	char c;
	Que* que;
	que = (Que*)malloc(sizeof(Que));
	scanf("%d", &q);
	scanf("%d", &n);
	getchar();
	nnn = n;
	initQueue(que, q);
	while (nnn != 0) {
		scanf("%c", &c);
		getchar();
		if (c == 'I') {
			scanf("%d", &e);
			getchar();
			if ((que->r + 1) % q == que->f) {
				printf("overflow");
				PRINT(que, q);
				return -1;
			}
			enqueue(que, q, e);

		}
		else if (c == 'D') {
			if ((que->r) % q == que->f) {
				printf("underflow");
				return -1;
			}
			dequeue(que, q);

		}
		else if (c == 'P') {
			PRINT(que, q);
		}
		nnn--;
	}

	return 0;
}
