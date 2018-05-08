#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *name = (char *)malloc(sizeof(char *));
  printf("What is your name?\n");
  scanf("%s", name);
  printf("%s\n", name);

  printf("What is your name?\n");
  scanf("%s", name);
  printf("%s\n", name);
  return 0;
}
