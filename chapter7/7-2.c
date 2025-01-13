#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NODE{
	struct NODE* prenode;
	struct NODE* nextnode;
	int elem;
}NODE;

typedef struct deq {
	NODE* front;
	NODE* rear;
	int cnt;
}DEQ;


void add_front(DEQ* deq, int x);
void add_rear(DEQ* deq, int x);
void delete_front(DEQ* deq);
void delete_rear(DEQ* deq);
void print(DEQ* deq);

int main() {
	int n;
	DEQ* deq = (DEQ*)malloc(sizeof(DEQ));
	deq->front = NULL;
	deq->rear = NULL;
	deq->cnt = 0;

	scanf("%d", &n);
	getchar();
	while (n != 0) {
		char order[3];
		int e;
		scanf("%s", order);
		getchar();
		if (strcmp(order, "AF") == 0) {
			scanf("%d", &e);
			getchar();
			add_front(deq, e);


		}
		else if (strcmp(order, "AR") == 0) {
			scanf("%d", &e);
			getchar();
			add_rear(deq, e);


		}
		else if (strcmp(order, "DF") == 0) {
			if (deq->cnt != 0) {
				delete_front(deq);
			}
			else {
				printf("underflow");
				return -1;
			}
		}
		else if (strcmp(order, "DR") == 0) {
			if (deq->cnt > 0) {
				delete_rear(deq);
			}
			else {
				printf("underflow");
				return -1;
			}
		}
		else if (strcmp(order, "P") == 0) {
			print(deq);
		}

		n--;
	}


	return 0;
}



void add_front(DEQ* deq, int x) {
	deq->cnt++;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->elem = x;
	node->prenode = NULL;
	node->nextnode = deq->front;
	if (deq->front != NULL) {
		deq->front->prenode = node;
	}
	else {
		deq->rear = node;
	}
	deq->front = node;
}


void add_rear(DEQ* deq, int x) {
	deq->cnt++;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->elem = x;
	node->nextnode = NULL;
	node->prenode = deq->rear;
	if (deq->rear != NULL) {
		deq->rear->nextnode = node;
	}
	else {
		deq->front = node;
	}
	deq->rear = node;
}


void delete_front(DEQ* deq) {
	deq->cnt--;
	deq->front = deq->front->nextnode;
	if (deq->front != NULL) {
		deq->front->prenode = NULL;
	}
}


void delete_rear(DEQ* deq) {
	deq->cnt--;
	deq->rear = deq->rear->prenode;
	if (deq->rear != NULL) {
		deq->rear->nextnode = NULL;
	}
}


void print(DEQ* deq) {
	NODE* p = deq->front;
	for (int i = 0; i < deq->cnt; i++) {
		printf(" %d", p->elem);
		p = p->nextnode;
	}
	printf("\n");
}
