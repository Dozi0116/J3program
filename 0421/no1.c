#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
  int value;
  struct CELL *next;
} CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

int main(void)
{
  CELL *root = makeCELL(); //dummy
  CELL *p = root; /* new! */
  int data;

  root -> value = 0;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);

    if(0 < data){
      p -> next = makeCELL();
      p = p -> next;
      p -> value = data;

    }
  }while(0 < data);


  for(p = root -> next;p != NULL;p = p -> next){
    printf("%d -> ", p -> value);
  }
  printf("NULL\n");

  return 0;
}
