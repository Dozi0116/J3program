#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *next;
	
} CELL;

void print_list(CELL *root);
void my_sort(CELL *root);

int main(void)
{
	CELL root;
	CELL *p = &root;
	int a[5] = {3, 5, 2, 4, 1};
	int x;

	for ( x = 0; x < 5; x++ ) {
		p->next = (CELL *)malloc(sizeof(CELL));
		p = p->next;
		p->value = a[x];
	}
	p->next = NULL;

	my_sort(root.next);
	
	print_list(root.next);

	return 0;
}

void print_list(CELL *root)
{
	CELL *p;

	for (p = root; p != NULL; p = p->next ) {
		printf("%d\n", p->value);
	}

}

void my_sort(CELL *root)
{
	CELL *i, *j;
	int x;

	for ( i = root; i->next != NULL; i = i->next ) {
		for (j = i->next; j != NULL; j = j->next ) {
			if (i->value > j->value) {
				x = i->value;
				i->value = j->value;
				j->value = x;
			}
		}
	}
}