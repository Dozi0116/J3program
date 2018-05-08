#include <stdio.h>

void spaces(int);

int main(void)
{
  int spaces_num = 2;
  spaces(spaces_num);
  printf("End.\n");
  return 0;
}

void spaces(int num)
{
  if(num > 0) {
    printf(" ");
    spaces(num - 1);
  }
}
