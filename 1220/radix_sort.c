#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000
#define DATA_MAX 1000

void bin_sort(int num[], int data_size);
void print_array(int num[], int data_size);

int main(void)
{
  int num[DATA_SIZE];

  int i;
  //init array
  for(i = 0;i < DATA_SIZE;i++){
    num[i] = i;
  }
  int temp, a, b;
  for(i = 0;i < DATA_SIZE * 2;i++){
    a = rand() % DATA_SIZE;
    b = rand() % DATA_SIZE;
    temp = num[a];
    num[a] = num[b];
    num[b] = temp;
  }

  print_array(num, DATA_SIZE);
  bin_sort(num, DATA_SIZE);
  print_array(num, DATA_SIZE);

  return 0;
}

void bin_sort(int num[], int data_size)
{
  int Do[10]; //度数分布。　添字の数がどれだけあったかを記録。
  int Ru[10]; //累積度数。　添字の数までに累積何要素あったかを記録。
  int answer[data_size];

  int temp_max;
  for(temp_max = 1;temp_max <= DATA_MAX;temp_max *= 10){
    //init array
    int i;
    for(i = 0;i < 10;i++){
      Do[i] = 0;
      Ru[i] = 0;
    }

    //度数分布を作成
    for(i = 0;i < data_size;i++){
      Do[(num[i] / temp_max) % 10]++;
    }

    //累積度数を作成
    int temp = 0;
    for(i = 0;i < 10;i++){
      temp += Do[i];
      Ru[i] = temp;
    }

    //並び替え
    for(i = 0;i < data_size;i++){
      answer[ Ru[(num[i] / temp_max) % 10] - Do[(num[i] / temp_max) % 10] ] = num[i];
      Do[(num[i] / temp_max) % 10]--;
    }

    for(i = 0;i < data_size;i++){
      num[i] = answer[i];
    }
  }
}

void print_array(int num[], int data_size)
{
  int i = 0;
  for(i = 0;i <data_size;i++){
    printf("[%d] = %d\n", i, num[i]);
  }

  printf("\n");
}
