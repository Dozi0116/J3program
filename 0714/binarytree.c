#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE *left;
	struct NODE *right;
} NODE;

NODE *addnode(int data);
void insert(NODE **p, int data);
NODE **search(NODE **p, int data);
void delete(NODE **p, int data);
NODE **search_max(NODE **p);
void inorder(NODE *p);

int main(void)
{
	NODE *root;
	int data;

	root = NULL;

	scanf("%d", &data);
	while (data > 0) {
		insert(&root, data);
		scanf("%d", &data);
	}

	inorder(root);
	printf("\n");
	
	scanf("%d", &data);
	while (data > 0) {
		delete(&root, data);
		inorder(root);
		printf("\n");
		scanf("%d", &data);
	}

	return 0;
}

NODE *addnode(int data)
{
	NODE *p;
	
	p = (NODE *)malloc(sizeof(NODE));

	p->value = data;
	p->left = NULL;
	p->right = NULL;

	return p;
}

void insert(NODE **p, int data)
{
	while(*p != NULL) {
		if (data <= (*p)->value) {
			p = &(*p)->left;
		} else {
			p = &(*p)->right;
		}
	}
	
	*p = addnode(data);
}

NODE **search(NODE **p, int data)
{
	// You can write a program here!

	return NULL;
}

void delete(NODE **p, int data)
{
	NODE **wp;
	NODE **max;
	NODE *tmp;

	wp = search(p, data);
	if (wp != NULL) {
		printf("Data is %d\n", (*wp)->value);
	} else {
		printf("Data has not found\n");
	}

	if (wp != NULL) {
		if ((*wp)->left == NULL && (*wp)->right == NULL) {
			// You can write a program here!

		} else if ((*wp)->left == NULL || (*wp)->right == NULL) {
			if ((*wp)->left == NULL) {
				// You can write a program here!

			} else {
				// You can write a program here!
			}
		} else {
			
			max = search_max(&(*wp)->left);
			tmp = *max;
			printf("max = %d\n", tmp->value);

			// You can write a program here!

		}	
	} else {
		printf("You don't have the data you wanna delete!!\n");
	} 
}

NODE **search_max(NODE **p)
{
	// You can write a program here!

	return p;
}

void inorder(NODE *p)
{
	if (p != NULL) {
		inorder(p->left);
		printf("%d ", p->value);
		inorder(p->right);
	}
}