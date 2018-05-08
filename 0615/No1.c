#include <stdio.h>

int factorial(int);

int main(void)
{
  int factorial_num = 10;
  printf("%d! is %d.\n", factorial_num, factorial(factorial_num));
  return 0;
}

int factorial(int num)
{
  int value = 1;
  if(num > 0) value = num * factorial(num - 1);
  return value;
}
