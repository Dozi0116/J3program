#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
  int value;
  struct CELL *next;
} CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

int main(void){
  CELL *root = makeCELL();
  CELL *p;
  CELL header;
  int data;

  root -> next = NULL;
  p = &header;
  header.next = NULL;

  scanf("%d", &data);
  while(data > 0){
    p -> next = makeCELL();
    p = p -> next;
    p -> value = data;
    scanf("%d", &data);
  }
  p -> next = NULL;

  for(p = header.next;p != NULL;p = p -> next){
    printf("%d\n", p -> value);
  }

  return 0;
}
