#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node* nextnode;
}nnode;


int subset(nnode* A, nnode* B) {
	nnode* tmp1node;
	nnode* tmp2node;
	int result = 0;

	tmp1node = A;
	tmp2node = B;

	while (1) {
		if (tmp1node->num == tmp2node->num) {
			tmp1node = tmp1node->nextnode;
			tmp2node = tmp2node->nextnode;
		}
		else if (tmp1node->num > tmp2node->num) {
			tmp2node = tmp2node->nextnode;
		}
		else if (tmp1node->num < tmp2node->num) {
			return tmp1node->num;
		}

		if (tmp1node == NULL && tmp2node == NULL) {
			break;
		}
		else if (tmp1node != NULL && tmp2node == NULL) {
			return tmp1node->num;
		}
		else if (tmp1node == NULL && tmp2node != NULL) {
			break;
		}
	}


	return result;
}


int main() {
	int n1, n2;
	nnode* A = (nnode*)malloc(sizeof(nnode));
	nnode* B = (nnode*)malloc(sizeof(nnode));
	nnode* pppnode;
	if (A == NULL) {
		printf("Not enough memory");
		return -1;
	}
	if (B == NULL) {
		printf("Not enough memory");
		return -1;
	}
	A->nextnode = NULL;
	B->nextnode = NULL;

	scanf("%d", &n1);
	pppnode = A;

	for (int i = 1; i < n1; i++) {
		scanf("%d", &pppnode->num);

		nnode* plusnode = (nnode*)malloc(sizeof(nnode));
		if (plusnode == NULL) {
			printf("Not enough memory");
			return -1;
		}
		plusnode->nextnode = NULL;
		pppnode->nextnode = plusnode;
		pppnode = plusnode;
	}
	if (n1 != 0) {
		scanf("%d", &pppnode->num);
	}


	scanf("%d", &n2);
	pppnode = B;

	for (int i = 1; i < n2; i++) {
		scanf("%d", &pppnode->num);

		nnode* plusnode = (nnode*)malloc(sizeof(nnode));
		if (plusnode == NULL) {
			printf("Not enough memory");
			return -1;
		}
		plusnode->nextnode = NULL;
		pppnode->nextnode = plusnode;
		pppnode = plusnode;
	}
	if (n2 != 0) {
		scanf("%d", &pppnode->num);
	}

	if (n1 == 0) {
		printf("0");
		return -1;
	}
	printf("%d", subset(A, B));


	return 0;
}
