#include <stdio.h>

typedef struct{
  int value;
  struct CELL *next;
}CELL;

int main(void){
  CELL *root;
  CELL cel;

  root = &cel;

  root->value = 5; //ok
  (*root).value = 5; //ok
  root->next = NULL;

  return 0;
}
