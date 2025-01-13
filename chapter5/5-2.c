#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* nextnode;
}nnode;


nnode* uunion(nnode* Aheader, nnode* Bheader) {
	nnode* tmp1node;
	nnode* tmp2node;
	nnode* tmp3node;
	nnode* resultnode = (nnode*)malloc(sizeof(nnode));
	if (resultnode == NULL) {
		printf("Not enough memory");
		return NULL;
	}
	resultnode->nextnode = NULL;

	tmp1node = Aheader->nextnode;
	tmp2node = Bheader->nextnode;
	tmp3node = resultnode;

	while (tmp1node != NULL && tmp2node != NULL) {
		if (tmp1node->num == tmp2node->num) {
			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return NULL;
			}
			plusnode->nextnode = NULL;
			plusnode->num = tmp1node->num;
			tmp3node->nextnode = plusnode;
			tmp1node = tmp1node->nextnode;
			tmp2node = tmp2node->nextnode;
			tmp3node = tmp3node->nextnode;
		}
		else if (tmp1node->num > tmp2node->num) {
			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return NULL;
			}
			plusnode->nextnode = NULL;
			plusnode->num = tmp2node->num;
			tmp3node->nextnode = plusnode;
			tmp2node = tmp2node->nextnode;
			tmp3node = tmp3node->nextnode;
		}
		else if (tmp1node->num < tmp2node->num) {
			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return NULL;
			}
			plusnode->nextnode = NULL;
			plusnode->num = tmp1node->num;
			tmp3node->nextnode = plusnode;
			tmp1node = tmp1node->nextnode;
			tmp3node = tmp3node->nextnode;
		}

	}
	while (tmp1node != NULL) {
		nnode* plusnode = (nnode*)malloc(sizeof(nnode));
		if (plusnode == NULL) {
			printf("Not enough memory");
			return NULL;
		}
		plusnode->nextnode = NULL;
		plusnode->num = tmp1node->num;
		tmp3node->nextnode = plusnode;
		tmp1node = tmp1node->nextnode;
		tmp3node = tmp3node->nextnode;
	}
	while (tmp2node != NULL) {
		nnode* plusnode = (nnode*)malloc(sizeof(nnode));
		if (plusnode == NULL) {
			printf("Not enough memory");
			return NULL;
		}
		plusnode->nextnode = NULL;
		plusnode->num = tmp2node->num;
		tmp3node->nextnode = plusnode;
		tmp2node = tmp2node->nextnode;
		tmp3node = tmp3node->nextnode;
	}
	return resultnode;
}

nnode* intersect(nnode* Aheader, nnode* Bheader) {
	nnode* tmp1node;
	nnode* tmp2node;
	nnode* tmp3node;
	nnode* resultnode = (nnode*)malloc(sizeof(nnode));
	if (resultnode == NULL) {
		printf("Not enough memory");
		return NULL;
	}
	resultnode->nextnode = NULL;

	tmp1node = Aheader->nextnode;
	tmp2node = Bheader->nextnode;
	tmp3node = resultnode;

	while (tmp1node != NULL && tmp2node != NULL) {
		if (tmp1node->num == tmp2node->num) {
			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return NULL;
			}
			plusnode->nextnode = NULL;
			plusnode->num = tmp1node->num;
			tmp3node->nextnode = plusnode;
			tmp1node = tmp1node->nextnode;
			tmp2node = tmp2node->nextnode;
			tmp3node = tmp3node->nextnode;
		}
		else if (tmp1node->num > tmp2node->num) {
			tmp2node = tmp2node->nextnode;
		}
		else if (tmp1node->num < tmp2node->num) {
			tmp1node = tmp1node->nextnode;
		}

	}
	return resultnode;
}


void printsset(nnode* header) {
	nnode* pppnode = header->nextnode;
	while (pppnode != NULL) {
		printf(" %d", pppnode->num);
		pppnode = pppnode->nextnode;
	}
	printf("\n");
}


int main() {
	int n1, n2;
	nnode* Aheader = (nnode*)malloc(sizeof(nnode));
	nnode* Bheader = (nnode*)malloc(sizeof(nnode));
	nnode* pppnode;
	nnode* uunionheader;
	nnode* intersectheader;
	if (Aheader == NULL) {
		printf("Not enough memory");
		return -1;
	}
	if (Bheader == NULL) {
		printf("Not enough memory");
		return -1;
	}
	Aheader->nextnode = NULL;
	Bheader->nextnode = NULL;

	scanf("%d", &n1);
	pppnode = Aheader;



	if (n1 != 0) {
		for (int i = 1; i <= n1; i++) {

			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return -1;
			}
			plusnode->nextnode = NULL;
			scanf("%d", &plusnode->num);
			pppnode->nextnode = plusnode;
			pppnode = plusnode;
		}
	}

	scanf("%d", &n2);
	pppnode = Bheader;


	if (n2 != 0) {
		for (int i = 1; i <= n2; i++) {

			nnode* plusnode = (nnode*)malloc(sizeof(nnode));
			if (plusnode == NULL) {
				printf("Not enough memory");
				return -1;
			}
			plusnode->nextnode = NULL;
			scanf("%d", &plusnode->num);
			pppnode->nextnode = plusnode;
			pppnode = plusnode;
		}
	}




	if (n1 != 0 && n2 != 0) {
		nnode* uunionheader = uunion(Aheader, Bheader);
		nnode* intersectheader = intersect(Aheader, Bheader);
		printsset(uunionheader);
		if (intersectheader->nextnode == NULL) {
			printf(" 0");
		}
		else {
			printsset(intersectheader);
		}

	}
	else if (n1 == 0 && n2 == 0) {
		printf(" 0\n 0");
		return -1;
	}
	else if (n1 != 0 && n2 == 0) {
		printsset(Aheader);
		printf(" 0");

	}
	else if (n1 == 0 && n2 != 0) {
		printsset(Bheader);
		printf(" 0");
	}

	return 0;
}
