#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 15
#define DATA_MAX 100

void bin_sort(int num[], int data_size);
void print_array(int num[], int data_size);

int main(void)
{
  int num[DATA_SIZE];

  int i;
  //init array
  for(i = 0;i < DATA_SIZE;i++){
    num[i] = rand() % DATA_MAX;
  }

  print_array(num, DATA_SIZE);
  bin_sort(num, DATA_SIZE);
  print_array(num, DATA_SIZE);

  return 0;
}

void bin_sort(int num[], int data_size)
{
  const int data_max = 100;
  int Do[data_max]; //度数分布。　添字の数がどれだけあったかを記録。
  int Ru[data_max]; //累積度数。　添字の数までに累積何要素あったかを記録。

  //init array
  int i;
  for(i = 0;i < data_max;i++){
    Do[i] = 0;
    Ru[i] = 0;
   }


  for(i = 0;i < data_size;i++){
    Do[num[i]]++;
  }

  int temp = 0;
  for(i = 0;i < data_max;i++){
    temp += Do[i];
    Ru[i] = temp;
  }

  print_array(Do, data_max);
  print_array(Ru, data_max);

  int answer[data_size];
  for(i = 0;i < data_size;i++){
    answer[ Ru[num[i]] - Do[num[i]] ] = num[i];
    Do[num[i]]--;
  }

  print_array(answer, data_size);
}

void print_array(int num[], int data_size)
{
  int i = 0;
  for(i = 0;i <data_size;i++){
    printf("[%d] = %d\n", i, num[i]);
  }

  printf("\n");
}
