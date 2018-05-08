
#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
  int value;
  struct CELL *next;
} CELL;

void displist(CELL);

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

void displist(struct CELL root)
{
  CELL *p;
  for(p = root.next;p != NULL;p = p -> next){
    printf("%d ", p -> value);
  }
  printf("\n");
}

int main(void)
{
  CELL root;
  root.value = 0;
  CELL *p = &root;
  CELL *x;
  int data;
  root.next = NULL;

  //makelist
  do{
    printf("Enter the number => ");
    scanf("%d", &data);
    if(data > 0){
      for(p = &root;p -> next != NULL;p = p -> next){
        if(p->next->value > data){
          break;
        }
      }
      x = makeCELL();
      x -> value = data;
      x -> next = p -> next;
      p -> next = x;
    }
    displist(root);
    }while(data > 0);

  return 0;
}
