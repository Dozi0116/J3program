#include <stdio.h>

void stars(int);

int main(void)
{
  int stars_num = 2;
  stars(stars_num);
  printf("\n");
  return 0;
}

void stars(int num)
{
  if(num > 0) {
    printf("*");
    stars(num - 1);
  }
}
