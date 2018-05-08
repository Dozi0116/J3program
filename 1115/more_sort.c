#include <stdio.h>

#define ELEMENT 10

void bubble_sort(int number[], const int data_size);
void insertion_sort(int number[], const int data_size);
void selection_sort(int number[], const int data_size);
void shell_sort(int number[], const int data_size);
void init_num(int number[]);
void swap(int *a, int *b);

int main(void)
{
  int number[ELEMENT];
  int i, j;
  void (* sort[])(int [], int) = {bubble_sort, insertion_sort, selection_sort, shell_sort};

  for(i = 0;i < 4;i++){
    init_num(number);
    sort[i](number, ELEMENT);
    for(j = 0;j < ELEMENT;j++){
      printf("[%d] = %d\n", j, number[j]);
    }
    printf("\n");
  }

  return 0;
}

void init_num(int number[])
{
  int i;
  for(i = 0;i < ELEMENT;i++){
    number[i] = i * 3 % 10;
  }
}

void bubble_sort(int number[], const int data_size)
{
  printf("bubblesort\n");
  int i, j, c = 0;
  for(i = 0;i < data_size - 1;i++){
    for(j = data_size - 1;j > i;j--){
      c++;
      if(number[i] > number[j]){
        swap(&number[i], &number[j]);
      }
    }
  }

  printf("compere = %d\n", c);
}

void insertion_sort(int number[], const int data_size)
{
  printf("insertionsort\n");
  int i, j, flg = 0, c = 0;
  for(i = 0;i < data_size;i++){
    for(j = i, flg = 0;j >= 1 && flg == 0;j--){
      c++;
      if(number[j-1] > number[j]){
        swap(&number[j-1], &number[j]);
      }else{
        flg = 1;
      }
    }
  }

  printf("compere = %d\n", c);
}

void selection_sort(int number[], const int data_size)
{
  printf("selectionsort\n");
  int i, j, min_index, c = 0;
  for(i = 0; i < data_size;i++){
    for(j = i, min_index = i;j < data_size;j++){
      c++;
      if(number[min_index] > number[j]){
        min_index = j;
      }
    }
    swap(&number[i], &number[min_index]);
  }

  printf("compere = %d\n", c);
}

void shell_sort(int number[], const int data_size)
{
  printf("shellsort\n");
  int h, i, j, flg = 0, c = 0;
  for(h = data_size / 2;h > 0;h /= 2){
    for(i = 0;i < data_size;i++){
      for(j = i, flg = 0;j >= h && flg == 0;j -= h){
        c++;
        if(number[j-h] > number[j]){
          swap(&number[j-h], &number[j]);
        }else{
          flg = 1;
        }
      }
    }
  }

  printf("compere = %d\n", c);
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
