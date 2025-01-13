#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int id;
	int e;
	struct node* left;
	struct node* right;
}node;

node* insertnode(int id, int e, node* l, node* r) {
	node* new = (node*)malloc(sizeof(node));
	new->id = id;
	new->e = e;
	new->left = l;
	new->right = r;
	return new;
}


int main() {
	int x;
	node* n7 = insertnode(7, 130, NULL, NULL);
	node* n8 = insertnode(8, 80, NULL, NULL);
	node* n6 = insertnode(6, 120, n7, n8);
	node* n3 = insertnode(3, 50, NULL, n6);
	node* n4 = insertnode(4, 70, NULL, NULL);
	node* n5 = insertnode(5, 90, NULL, NULL);
	node* n2 = insertnode(2, 30, n4, n5);
	node* n1 = insertnode(1, 20, n2, n3);
	scanf("%d", &x);
	switch (x) {
	case 1:
		printf("%d %d %d", n1->e, n1->left->e, n1->right->e); break;
	case 2:
		printf("%d %d %d", n2->e, n2->left->e, n2->right->e); break;
	case 6:
		printf("%d %d %d", n6->e, n6->left->e, n6->right->e); break;
	case 3:
		printf("%d %d", n3->e, n3->right->e); break;
	case 4:
		printf("%d", n4->e); break;
	case 5:
		printf("%d", n5->e); break;
	case 7:
		printf("%d", n7->e); break;
	case 8:
		printf("%d", n8->e); break;
	default:
		printf("-1");
	}


	return 0;
}
