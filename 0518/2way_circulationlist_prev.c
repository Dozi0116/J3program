#include <stdio.h>
#include <stdlib.h>

#define NEXT 0
#define PREV 1

typedef struct CELL {
  struct CELL *prev;
  int value;
  struct CELL *next;
} CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

void displist(struct CELL root)
{
  CELL *p;
  for(p = root.next;p != &root;p = p -> prev){
    printf("%d ", p -> value);
  }
  printf("\n");
}

void printlist(struct CELL root, int mode)
{
  int flg = 0;
  CELL *p = &root;

  switch(mode){
    case NEXT:
      for(p = root.next,flg = 0;p != root.next || flg == 0;p = p -> next){
        printf("%d -> ", p -> value);
        flg = 1;
      }
      printf("%d -> ...\n", p -> value);
    break;

    case PREV:
      for(p = root.prev, flg = 0;p != root.prev || flg == 0; p = p -> prev){
        printf("%d -> ", p -> value);
        flg = 1;
      }
      printf("%d -> ...\n", p -> value);
    break;

    default: {printf("Eroor.\n"); exit(-1);}
  }
}

int main(void)
{
  CELL root;
  CELL *p  = &root;
  p -> next = &root;
  int data;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);

    if(0 < data){
      p -> prev = makeCELL();
      p -> prev -> next = p;
      p = p -> prev;
      p -> value = data;
    }

  }while(0 < data);

  root.next = p;
  root.prev -> next = p;
  p -> prev = root.prev;

  printlist(root, NEXT);
  printlist(root, PREV);

  

  return 0;
}
