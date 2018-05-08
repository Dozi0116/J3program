#include <stdio.h>

void sankaku1(int);

int main(void)
{
  int sankaku_num = 3;
  sankaku1(sankaku_num);
  return 0;
}

void sankaku1(int num)
{
  int i;
  if(num > 0) {
    for(i = num;i > 0;i--){
      printf("*");
    }
    printf("\n");
    sankaku1(num - 1);
  }
}
