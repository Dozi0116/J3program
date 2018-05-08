#include <stdio.h>

void sankaku2(int);

int main(void)
{
  int sankaku_num = 10;
  sankaku2(sankaku_num);
  return 0;
}

void sankaku2(int num)
{
  int i;
  if(num > 1) {
    sankaku2(num - 1);
  }

  for(i = num;i > 0;i--){
    printf("*");
  }
  printf("\n");
}
