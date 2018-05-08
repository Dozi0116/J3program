/*
  シェルソートの間隔を1から配列の大きさまでをとり、それぞれ100回計測した結果を表示する。
  2種類の初期値から結果を求めたが、理論値に近づかない結果となってしまった。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENT 100

void shell_sort(int number[], const int data_size, int div_num);
void init_num(int number[]);
void swap(int *a, int *b);

int count_compare;
int count_exchange;

int main(void)
{
  int number[ELEMENT];
  int i, cnt;
  int min_conp_count, min_conp_num, min_exchange_count, min_exchange_num;
  min_conp_count = 99999;
  min_exchange_count = 99999;
  min_conp_num = -1;
  min_exchange_num = -1;

  for(i = 0;i < ELEMENT;i++){
    //同じ配列で試すため、ここで初期化を行う。
    //case1
    srand(15412);
    //case2
    //srand(1000);
    printf("h = SIZE / %d\n", i+1);
    count_exchange = 0;
    count_compare = 0;
    for(cnt = 0; cnt < 100;cnt++){
      init_num(number);
      shell_sort(number, ELEMENT, i + 1);
    }
    printf("finish!\n");
    printf("average compare => %d\n", count_compare / 100);
    printf("average exchange => %d\n\n", count_exchange / 100);
    if(min_conp_count > count_compare){
      min_conp_count = count_compare;
      min_conp_num = i;
    }
    if(min_exchange_count > count_exchange){
      min_exchange_count = count_exchange;
      min_exchange_num = i;
    }
  }

  printf("result\n");

  printf("min_conp => SIZE / %d, %d count!\n", min_conp_num + 1, min_conp_count / 100);
  printf("min_exchange => SIZE / %d, %d count!\n", min_exchange_num + 1, min_exchange_count / 100);

  return 0;
}

void init_num(int number[])
{
  int i;
	int index1, index2, tmp;

	for (i = 0; i < ELEMENT; i++) {
		number[i] = i + 1;
	}

	for (i = 0; i < 10000; i++ ) {
		index1 = rand() % ELEMENT;
		index2 = rand() % ELEMENT;

		tmp = number[index1];
		number[index1] = number[index2];
		number[index2] = tmp;
	}
}

void shell_sort(int number[], const int data_size, int div_num)
{
  int h, i, j;
  for(h = data_size / div_num;h > 0;h /= 2){
    for(i = 0;i < data_size;i++){
      count_compare++;
      for (j = i;j >= h&& number[j] < number[j - h];j -= h, count_compare++){
        count_exchange++;
        swap(&number[j-h], &number[j]);
      }
      if(j <= h - 1){
        count_compare--;
      }
    }
  }
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
