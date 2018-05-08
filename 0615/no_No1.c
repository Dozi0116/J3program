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
  int i;
  int value = 1;
  for(i = num;i > 0;i--){
    value *= i;
  }
  return value;
}
