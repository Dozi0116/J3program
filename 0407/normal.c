#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
  int value;
  struct CELL *next;
}CELL;

int main(void)
{
  CELL *root = (CELL *)malloc(sizeof(CELL));
  CELL *p  = root;

  int i = 0;

  for(i = 3;i <= 7;i+=2){
    p -> value = i;
    p -> next = (CELL *)malloc(sizeof(CELL));
    p = p -> next;
  }
  p -> next = NULL;

  for(i = 0, p = root; i < 3;i++){
    printf("val%d >= %d\n", i + 1, p -> value);
    p = p -> next;
  }
  return 0;
}
