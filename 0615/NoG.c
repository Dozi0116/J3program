#include <stdio.h>

void ffff(int, int);
void stars(int);
void spaces(int);

int main(void)
{
  ffff(3,4);
  return 0;
}

void ffff (int n, int s)
{
  if (n==0 && s>0) {
    printf("\n");
    ffff(3,s-1);
  }
  if (n>0 && s>0) {
    spaces(s);stars(5-s);
    ffff(n-1,s);
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
