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
  root->value = 5;
  root->next = (CELL *)malloc(sizeof(CELL));
  root->next->value = 2;
  root->next->next = NULL;
  return 0;
}
