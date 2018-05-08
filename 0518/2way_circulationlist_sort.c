#include <stdio.h>
#include <stdlib.h>

#define NEXT 0
#define PREV 1

typedef struct CELL{
  struct CELL *prev;
  int value;
  struct CELL *next;
}CELL;

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL *));
}

void printlist(struct CELL root, int mode)
{
  int flg = 0;
  CELL *p;
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
  }
}

int main(void)
{
  CELL root;
  CELL *x;
  CELL *p  = &root;
  p -> prev = &root;
  int data, flg;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);

    if(0 < data){
      p -> next = makeCELL();
      p -> next -> prev = p;
      p = p -> next;
      p -> value = data;
    }

  }while(0 < data);

  p -> next = root.next;
  root.next -> prev = p;
  root.prev = p;

  printlist(root, NEXT);
  printlist(root, PREV);

  //makelist
  do{
    printf("Enter the number => ");
    scanf("%d", &data);
    if(data > 0){
      for(p = &root, flg = 0;p != root.next || flg == 0;p = p -> next){
        if(p->next->value > data){
          break;
        }
        flg = 1;
      }
      x = makeCELL();
      x -> value = data;
      x -> next = p -> next;
      p -> next = x;
    }
    printlist(root, NEXT);
    printlist(root, PREV);
    }while(data > 0);

  return 0;
}
