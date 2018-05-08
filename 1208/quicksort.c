#include <stdio.h>

#define DATA_SIZE 10

void quick_sort(int *number, const int data_size);
void swap(int *a, int *b);
void print_array(int num[], int data_size);

int main(void)
{
  int num[DATA_SIZE];

  int i;
  //init array
  for(i = 0;i < DATA_SIZE;i++){
    num[i] = 7 * i % 10;
  }

  print_array(num, DATA_SIZE);
  quick_sort(num, DATA_SIZE);
  print_array(num, DATA_SIZE);

  return 0;
}

void quick_sort(int *number, const int data_size)
{
  if(data_size <= 1) return;

  if(data_size == 2){
    if(number[1] < number[0]){
      swap(&number[0], &number[1]);
    }
    return;
  }

  int pivot = number[0];
  int min = 0, max = data_size-1;
  //配列の中身をpivot以下とpivotより上に分ける
  while(1){
    while(number[min] < pivot) min++;
    while(number[max] > pivot) max--;

    if(min >= max) break;

    swap(&number[min], &number[max]);
  }

  int i;
  for(i = 0;number[i] != pivot;i++);

  quick_sort(&number[0], i);
  quick_sort(&number[i+1], data_size - i - 1);

}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int num[], int data_size)
{
  int i = 0;
  for(i = 0;i <data_size;i++){
    printf("[%d] = %d\n", i, num[i]);
  }

  printf("\n");
}
