#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void set_array(int a[SIZE]);
void my_insertion_sort(int a[SIZE]);
void print_array( int a[SIZE]);

int main(void)
{
	int a[SIZE];

	srand((unsigned)time(NULL));

	set_array(a);
	print_array(a);

	my_insertion_sort(a);
	print_array(a);

	return 0;
}

void set_array(int a[SIZE])
{
	int i;
	int index1, index2, tmp;

	for (i = 0; i < SIZE; i++) {
		a[i] = i + 1;
	}

	for (i = 0; i < 1000; i++ ) {
		index1 = rand() % SIZE;
		index2 = rand() % SIZE;

		tmp = a[index1];
		a[index1] = a[index2];
		a[index2] = tmp;
	}
}

void my_insertion_sort(int a[SIZE])
{
	// You can modify programs here!

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

void print_array( int a[SIZE])
{
	int i;
	for ( i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
