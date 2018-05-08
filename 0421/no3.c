#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
  int value;
  struct CELL *next;
} CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

void addCELL(CELL *p, int data){
  CELL *q = p;
  p = p -> next;
  q -> next = makeCELL();
  q = q -> next;
  q -> value = data;
  q -> next = p;
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

  int index, i;
  do{
    printf("Enter the number. => ");
    scanf("%d", &data);
    printf("Enter the index. => ");
    scanf("%d", &index);

    p = root;

    if(0 < index){
      for(i = 0;i < index - 1;i++){
        p = p -> next;
      }
      addCELL(p, data);
    }

    for(p = root -> next;p != NULL;p = p -> next){
      printf("%d -> ", p -> value);
    }
    printf("NULL\n");
  }while(0 < index);

  return 0;
}
