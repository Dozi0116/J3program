#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
  int value;
  struct CELL *next;
}CELL;

int main(void)
{
  CELL *root;
  root = (CELL *)malloc(sizeof(CELL));
  root -> value = 3;
  root -> next = (CELL *)malloc(sizeof(CELL));
  root -> next -> value = 5;
  root -> next -> next = (CELL *)malloc(sizeof(CELL));
  root -> next -> next -> value = 7;
  root -> next -> next -> next = NULL;

  printf("val1 => %d\nval2 => %d\nval3 => %d\n", root -> value, root -> next -> value, root -> next -> next -> value);

  return 0;
}
