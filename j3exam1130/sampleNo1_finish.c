#include <stdio.h>
#include <stdlib.h>

#define B_S 5

typedef struct CELL {
	int value;
	struct CELL *next;
} CELL;

int hash(int key);
void init_table(CELL *table[B_S]);
void insert_table(CELL *table[B_S], int data);
void print_table(CELL *table[B_S]);
void print_list(CELL *p, int num);

int main(void)
{
	CELL *table[B_S];
	int data;

	init_table(table);

	printf("Input data = ");
	scanf("%d", &data);

	while (data > 0) {

		insert_table(table, data);
		print_list(table[hash(data)], hash(data));

		printf("Input data = ");
		scanf("%d", &data);

	}

	printf("\nResult :\n");
	print_table(table);

	return 0;
}

int hash(int key)
{
	return key % B_S;
}

void init_table(CELL *table[B_S])
{
	int i;

	for (i = 0; i < B_S; i++) {
		table[i] = NULL;
	}
}

void insert_table(CELL *table[B_S], int data)
{
	// You can modify programs here at Question 1-1!

	int h = hash(data);
	CELL *p = (CELL *)malloc(sizeof(CELL));

	p->value = data;
	p->next = table[h];
	table[h] = p;
}

void print_list(CELL *p, int num)
{
	for (printf("table[%d] -> ", num); p != NULL; p = p->next) {
		printf("%d -> ", p->value);
	}
	printf("NULL\n");
}

void print_table(CELL *table[B_S])
{
	/*
	You can program here at Question 1-2!
	*/
	int i;
	for(i = 0;i < B_S;i++){
		print_list(table[i], i);
	}
}
