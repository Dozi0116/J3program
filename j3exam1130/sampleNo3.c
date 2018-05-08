#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void set_array(int a[SIZE]);
void my_shell_sort(int a[SIZE]);
void print_array( int a[SIZE]);

int main(void)
{
	int a[SIZE];
	
	srand((unsigned)time(NULL));

	set_array(a);
	print_array(a);

	my_shell_sort(a);
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
	
	for (i = 0; i < 10000; i++ ) {
		index1 = rand() % SIZE;
		index2 = rand() % SIZE;
		
		tmp = a[index1];
		a[index1] = a[index2];
		a[index2] = tmp;
	}
}

void my_shell_sort(int a[SIZE])
{
	int h, i, j, tmp;

	for ( h = 1; h < SIZE/9; h = h * 3 + 1 );
	h = (h - 1) / 3;
	
	for ( ; h > 0; h /= 3 ) {
		for ( i = h; i < SIZE; i++ ) {
			for ( j = i; j >= h && a[j] < a[j - h]; j -= h ) {
				tmp = a[j];
				a[j] = a[j-h];
				a[j-h] = tmp;
			}
		}
	}
}

void print_array( int a[SIZE])
{
	int i;
	for ( i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}