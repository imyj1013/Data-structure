#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int e;
	struct node* left;
	struct node* right;
}node;

typedef struct TREE {
	node* root;
	int cnt;
}TREE;

node* insertnode(int el) {
	node* new = (node*)malloc(sizeof(node));
	new->e = el;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void  preorder(node* root) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	root->e = a;
	if (b != 0) {
		root->left = insertnode(b);
		preorder(root->left);
	}
	if (c != 0) {
		root->right = insertnode(c);
		preorder(root->right);
	}
	return;
}

void find(node* root, char* s) {
	node* p=root;
	printf(" %d", p->e);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'L') {
			p = p->left;
			printf(" %d", p->e);
		}
		else if (s[i] == 'R') {
			p = p->right;
			printf(" %d", p->e);
		}
	}
	printf("\n");
}


int main() {
	char s[101];
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->root = insertnode(0);
	int N;
	scanf("%d", &N);
	tree->cnt = N;
	preorder(tree->root);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", s);
		find(tree->root, s);
	}

	return 0;
}
