#include <stdio.h>

#define DATA_SIZE 10

void bin_sort(int num[], int data_size);
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
  bin_sort(num, DATA_SIZE);
  print_array(num, DATA_SIZE);

  return 0;
}

void bin_sort(int num[], const int data_size)
{
  const int data_max = 100;
  int bin[data_max];
  int i = 0;
  int j = 0;

  for(i = 0;i < data_max;i++){
    bin[i] = 0;
  }

  for(i = 0;i < data_size;i++){
    bin[num[i]]++;
  }

  for(i = 0, j = 0;i < data_max;i++){
    if(bin[i] >= 1){
      for(;bin[i] > 0;bin[i]--, j++){
        num[j] = i;
      }
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
