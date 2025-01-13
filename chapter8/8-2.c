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

void preorder(node* target, int y) {
	if (target == NULL) {
		return;
	}
	printf(" %d", target->e);
	preorder(target->left, y);
	preorder(target->right, y);
}

node* findin(node* root, int y) {
	node* p = NULL;
	if (root->left != NULL) {
		p = findin(root->left, y);
		if (p != NULL) {
			return p;
		}
	}
	if (root->id == y) {
		return root;
	}
	if (root->right != NULL) {
		p = findin(root->right, y);
		if (p != NULL) {
			return p;
		}
	}
	return NULL;

}

void inorder(node* target, int y) {
	if (target == NULL) {
		return;
	}
	inorder(target->left, y);
	printf(" %d", target->e);
	inorder(target->right, y);
}

node* findpost(node* root, int y) {
	node* p = NULL;
	if (root->left != NULL) {
		p = findpost(root->left, y);
		if (p != NULL) {
			return p;
		}
	}
	if (root->right != NULL) {
		p = findpost(root->right, y);
		if (p != NULL) {
			return p;
		}
	}
	if (root->id == y) {
		return root;
	}
	return NULL;
}

void postorder(node* target, int y) {
	if (target == NULL) {
		return;
	}
	postorder(target->left, y);
	postorder(target->right, y);
	printf(" %d", target->e);
}

int main() {
	int x, y;
	node* target;
	TREE* tree = (TREE*)malloc(sizeof(TREE));
	tree->root = build();

	scanf("%d %d", &x, &y);

	if (y > 8) {
		printf("-1");
		return -1;
	}

	if (x == 1) {
		target = findpre(tree->root, y);
		preorder(target, y);
	}
	else if (x == 2) {
		target = findin(tree->root, y);
		inorder(target, y);
	}
	else {
		target = findpost(tree->root, y);
		postorder(target, y);
	}

	return 0;
}
