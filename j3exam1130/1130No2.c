void my_insertion_sort(int a[SIZE])
{
	//解き終わり！、もう編集はしないこと！

	int i, j, tmp;
	int count_compare = 0, count_exchange = 0;

	for ( i = 1; i < SIZE; i++ ) {
		//初めから負ける場合でも比較はするから+1
		count_compare++;
		//交換する、つまり比較しているため、ループ更新文で+1
		for ( j = i; j >= 1 && a[j] < a[j - 1]; j--, count_compare++ ) {
			count_exchange++;
			tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
		}
		//ハッピーエンドの比較分を打ち消す
		if(j == 0){
			count_compare--;
		}
	}

	printf("count_compare = %d\n", count_compare);
	printf("count_exchange = %d\n", count_exchange);
}
