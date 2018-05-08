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
	int x;

	for ( i = root; i->next != root -> prev; i = i->next ) {
		for (j = i->next; j != root -> prev; j = j->next ) {
			if (i->value > j->value) {
				x = i->value;
				i->value = j->value;
				j->value = x;
			}
		}
	}
}
