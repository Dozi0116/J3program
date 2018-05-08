void insert_table(CELL *table[B_S], int data)
{
	//解き終わり！、もう編集はしないこと！

	int h = hash(data);
	CELL *p = (CELL *)malloc(sizeof(CELL));

	p->value = data;
	p->next = table[h];
	table[h] = p;
}
