#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE *left;
	struct NODE *right;
} NODE;

void insert(NODE **p, int data);
void my_alloc(NODE **p, int data);
NODE **my_search_for_insert(NODE **p, int data);
void inorder(NODE *p);

int main(void)
{
	NODE *root = NULL;
	int data;

	printf("Input data : ");
	scanf("%d", &data);

	while ( data > 0 ) {

		insert(&root, data);

		printf("Input next data : ");
		scanf("%d", &data);
	}

	inorder(root);

	return 0;
}

void insert(NODE **p, int data)
{
	my_alloc(my_search_for_insert(p, data), data);
}

void my_alloc(NODE **p, int data)
{
	*p = (NODE *)malloc(sizeof(NODE));
	(*p)->value = data;
	(*p)->left = NULL;
	(*p)->right = NULL;
}

NODE **my_search_for_insert(NODE **p, int data)
{
	while ( *p  != NULL ) {
		if ( (*p)->value > data ) {
			p = &(*p)->left;
		} else {
			p = &(*p)->right;
		}
	}

	return p;
}

void inorder(NODE *p)
{
	if (p != NULL) {
		inorder(p->right);
		printf("%d\n", p->value);
		inorder(p->left);
	}
}
