#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node {
	int coef_num;
	int exp_num;
	struct node* nextnode;
}nnode;


nnode* append(nnode* prenode, int coef, int exp) {

	nnode* tmpnode = (nnode*)malloc(sizeof(nnode));

	tmpnode->coef_num = coef;
	tmpnode->exp_num = exp;
	tmpnode->nextnode = NULL;

	prenode->nextnode = tmpnode;


	return tmpnode;
}


nnode* calcul(nnode* header1, nnode* header2) {
	
	nnode* sumnode = (nnode*)malloc(sizeof(nnode));
	sumnode->nextnode = NULL;

	nnode* tmp1node = header1->nextnode;
	nnode* tmp2node = header2->nextnode;
	nnode* tmp3node = sumnode;


	while (tmp1node != NULL && tmp2node != NULL) {

		if (tmp1node->exp_num == tmp2node->exp_num) {
			if (tmp1node->coef_num + tmp2node->coef_num != 0) {
				tmp3node = append(tmp3node, tmp1node->coef_num + tmp2node->coef_num, tmp1node->exp_num);
			}
			tmp1node = tmp1node->nextnode;
			tmp2node = tmp2node->nextnode;
		}
		else if (tmp1node->exp_num > tmp2node->exp_num) {
			tmp3node = append(tmp3node, tmp1node->coef_num, tmp1node->exp_num);
			tmp1node = tmp1node->nextnode;
		}
		else {
			tmp3node = append(tmp3node, tmp2node->coef_num, tmp2node->exp_num);
			tmp2node = tmp2node->nextnode;
		}

	}

	while (tmp1node != NULL) {
		tmp3node = append(tmp3node, tmp1node->coef_num, tmp1node->exp_num);
		tmp1node = tmp1node->nextnode;
	}

	while (tmp2node != NULL) {
		tmp3node = append(tmp3node, tmp2node->coef_num, tmp2node->exp_num);
		tmp2node = tmp2node->nextnode;
	}

	return sumnode;
}



void print(nnode* llist) {
	nnode* tmpnode = llist;
	while (tmpnode->nextnode != NULL) {
		tmpnode = tmpnode->nextnode;
		printf(" %d %d", tmpnode->coef_num, tmpnode->exp_num);
	}
}

void memoryclear(nnode* header) {
	nnode* savenode;
	nnode* clearnode;

	clearnode = header;
	while (clearnode != NULL) {
		savenode = clearnode->nextnode;
		free(clearnode);
		clearnode = savenode;
	}

}



int main() {
	int n1, n2, coef, exp;

	nnode* header1 = (nnode*)malloc(sizeof(nnode));
	nnode* header2 = (nnode*)malloc(sizeof(nnode));
	nnode* header_sum;
	nnode* tmpnode;

	header1->nextnode = NULL;
	header2->nextnode = NULL;

	tmpnode = header1;

	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d %d", &coef, &exp);
		tmpnode = append(tmpnode, coef, exp);
	}

	tmpnode = header2;

	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %d", &coef, &exp);
		tmpnode = append(tmpnode, coef, exp);
	}


	header_sum = calcul(header1, header2);


	print(header_sum);


	memoryclear(header1);
	memoryclear(header2);
	memoryclear(header_sum);
	return 0;
}
