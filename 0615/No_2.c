#include <stdio.h>

#define SIZE 4

void sankaku3(int);
void stars(int);
void spaces(int);

int main(void)
{
  int sankaku_num = 5;
  sankaku3(sankaku_num);
  return 0;
}

void sankaku3(int num)
{
  int i, j;
  for(i = SIZE;i > 0;i--){
    for(j = 0;j < num;j++){
      spaces(SIZE - i);
      stars(i);
      printf(" ");
    }
    printf("\n");
  }
}

void stars(int num)
{
  if(num > 0) {
    printf("*");
    stars(num - 1);
  }
}

void spaces(int num)
{
  if(num > 0) {
    printf(" ");
    spaces(num - 1);
  }
}
