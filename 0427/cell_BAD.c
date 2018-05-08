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
  CELL *root;
  CELL *p;
  int data;

  root = NULL;

  printf("number => ");
  scanf("%d", &data);
  if(data > 0){
    root = makeCELL();
    root -> value = data;
    p = root;

    do{
      printf("number => ");
      scanf("%d", &data);
      if(data > 0){
        p -> next = makeCELL();
        p -> next -> value = data;
        p = p -> next;
      }
    }while(data > 0);
  }

  return 0;
}
