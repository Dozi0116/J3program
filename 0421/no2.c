#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
  int value;
  struct CELL *next;
}CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

int main(void)
{
  CELL *root = makeCELL();
  CELL *p  = root;
  int data;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);

    if(0 < data){
      p -> value = data;
      p -> next = makeCELL();
      p = p -> next;
    }

  }while(0 < data);

  p -> next = NULL;

  for(p = root;p -> next != NULL;p = p -> next){
    printf("%d -> ", p -> value);
  }
  printf("NULL\n");

  return 0;
}
