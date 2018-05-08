#include <stdio.h>

typedef struct CELL{
  int value;
  struct CELL *next;
}CELL;

int main(void){
  CELL *root;
  CELL cel1, cel2;

  root = &cel1;

  root->value = 5;
  (*root).value = 5;
  (*root).next = &cel2;

  root->next->value = 2;
  (*(*root).next).value = 2;

  printf("val1 = %d\n", root->value);

  return 0;
}
