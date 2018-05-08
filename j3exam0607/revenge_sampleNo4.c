#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *prev;
	struct CELL *next;
} CELL;

void print_list(CELL *root);
void my_sort(CELL *root);

int main(void)
{
	CELL root;
	CELL *p = &root;
	int a[5] = {3, 5, 2, 4, 1}; //35241
	int x;

	for ( x = 0; x < 5; x++ ) {
		p->next = (CELL *)malloc(sizeof(CELL));
		p->next->prev = p;
		p = p->next;
		p->value = a[x];
	}
	p->next = &root;
	root.prev = p;

	my_sort(root.next);

	print_list(root.next);

	return 0;
}

void print_list(CELL *root)
{
	CELL *p;

	for (p = root; p != root -> prev; p = p->next ) {
		printf("%d\n", p->value);
	}

}

void my_sort(CELL *root)
{
	CELL *i, *j;
	CELL *temp;

	root -> prev -> value = 9999;
	root = root -> prev;

	for ( i = root -> next; i->next != root; i = i->next ) {
		for (j = i->next; j != root; j = j->next ) {
			if (i->value > j->value) {
				if(i -> next == j){//隣り合っている場合、特殊な処理をする。
					i -> prev -> next = j;
					j -> next -> prev = i;
					i -> next = j -> next;
					j -> prev = i -> prev;
					j -> next = i;
					i -> prev = j;
				}else{
					CELL *ip, *in, *jp, *jn;
					ip = i -> prev;
					in = i -> next;
					jp = j -> prev;
					jn = j -> next;

					ip -> next = j;
					j -> prev = ip;
					j -> next = in;
					in -> prev = j;
					jp -> next = i;
					i -> prev = jp;
					i -> next = jn;
					jn -> prev = i;
				}
				temp = i;
				i = j;
				j = temp;
			}
		}
	}
}
