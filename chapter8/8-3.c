#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int id;
	int e;
	struct node* left;
	struct node* right;
}node;

typedef struct TREE {
	node* root;
}TREE;

node* insertnode(int id, int e, node* l, node* r) {
	node* new = (node*)malloc(sizeof(node));
	new->id = id;
	new->e = e;
	new->left = l;
	new->right = r;
	return new;
}

node* build() {
	node* left = insertnode(7, 130, NULL, NULL);
	node* right = insertnode(8, 80, NULL, NULL);
	right = insertnode(6, 120, left, right);
	right = insertnode(3, 50, NULL, right);
	node* root = insertnode(1, 20, NULL, right);
	left = insertnode(4, 70, NULL, NULL);
	right = insertnode(5, 90, NULL, NULL);
	left = insertnode(2, 30, left, right);
	root->left = left;
	return root;
}

node* findpre(node* root, int y) {
	node* p = NULL;
	if (root->id == y) {
		return root;
	}
	else {
		if (root->left != NULL) {
			p = findpre(root->left, y);
			if (p != NULL) {
				return p;
			}
		}
		if (root->right != NULL) {
			p = findpre(root->right, y);
			if (p != NULL) {
				return p;
			}
		}
		return NULL;
	}
}

int preorder(node* target, int y) {
	int result = 0;
	if (target == NULL) {
		return;
	}
	result += target->e;
	if (target->left != NULL) {
		result += preorder(target->left, y);
	}
	if (target->right != NULL) {
		result += preorder(target->right, y);
	}
	return result;
}

int main() {
	int y, x;
	node* target;
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->root = build();

	scanf("%d", &y);

	if (y > 8) {
		printf("-1");
		return -1;
	}

	target = findpre(tree->root, y);
	x = preorder(target, y);

	printf("%d", x);

	return 0;
}
