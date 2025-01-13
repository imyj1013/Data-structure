#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node {
	char ccc;
	struct node* prenode;
	struct node* nextnode;
}nnode;



typedef struct doublelist {
	int count;
	nnode* header;
	nnode* trailer;
}llist;


void add(llist* doulist, int rank, char elmt) {
	if (rank > doulist->count + 1) {
		printf("invalid position\n");
		return;
	}

	nnode* addnode = (nnode*)malloc(sizeof(nnode));


	addnode->ccc = elmt;

	nnode* tmpnode = doulist->header;
	for (int i = 0; i < rank - 1; i++) {
		tmpnode = tmpnode->nextnode;
	}


	addnode->prenode = tmpnode;
	addnode->nextnode = tmpnode->nextnode;
	tmpnode->nextnode->prenode = addnode;
	tmpnode->nextnode = addnode;

	doulist->count++;
}

void delete(llist* doulist, int rank) {
	if (rank > doulist->count) {
		printf("invalid position\n");
		return;
	}

	nnode* tmpnode = doulist->header;
	for (int i = 0; i < rank; i++) {
		tmpnode = tmpnode->nextnode;
	}

	tmpnode->nextnode->prenode = tmpnode->prenode;
	tmpnode->prenode->nextnode = tmpnode->nextnode;

	free(tmpnode);
	doulist->count--;
}

void get(llist* doulist, int rank) {
	if (rank > doulist->count) {
		printf("invalid position\n");
		return;
	}

	nnode* tmpnode = doulist->header;
	for (int i = 0; i < rank; i++) {
		tmpnode = tmpnode->nextnode;
	}

	printf("%c\n", tmpnode->ccc);
}

void print(llist* doulist) {
	nnode* tmpnode = doulist->header;
	while (tmpnode != doulist->trailer->prenode) {
		tmpnode = tmpnode->nextnode;
		printf("%c", tmpnode->ccc);
	}
	printf("\n");
}


int main() {
	int N, rank, elmt;
	char menu;
	llist* doulist = (llist*)malloc(sizeof(llist));
	nnode* header = (nnode*)malloc(sizeof(nnode));
	nnode* trailer = (nnode*)malloc(sizeof(nnode));



	doulist->header = header;
	doulist->trailer = trailer;
	doulist->count = 0;
	header->prenode = NULL;
	header->nextnode = trailer;
	trailer->prenode = header;
	trailer->nextnode = NULL;


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &menu);
		if (menu == 'A') {
			scanf("%d %c", &rank, &elmt);
			add(doulist, rank, elmt);
		}
		else if (menu == 'D') {
			scanf("%d", &rank);
			delete(doulist, rank);
		}
		else if (menu == 'G') {
			scanf("%d", &rank);
			get(doulist, rank);
		}
		else if (menu == 'P') {
			print(doulist);
		}
	}

	free(doulist);
	free(header);
	free(trailer);

	return 0;
}
