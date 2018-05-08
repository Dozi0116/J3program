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
  CELL *root;
  CELL *p = NULL; /* new! */
  int data;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);

    if(0 < data){
      p = root;
      root = makeCELL();
      root -> value = data;
      root -> next = p;
    }
  }while(0 < data);


  for(p = root;p != NULL;p = p -> next){
    printf("%d -> ", p -> value);
  }
  printf("NULL\n");

  return 0;
}
