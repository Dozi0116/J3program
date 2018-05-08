void print_table(CELL *table[B_S])
{
	/*
	解き終わり！もう編集はしないこと！
	*/
	int i;
	for(i = 0;i < B_S;i++){
		print_list(table[i], i);
	}
}
