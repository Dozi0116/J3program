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

void addCELL(struct CELL *p, int data){
  CELL *q = p;
  p = p -> next;
  q -> next = makeCELL();
  q = q -> next;
  q -> value = data;
  q -> next = p;
  q -> prev = p -> prev;
  p -> prev = q;
}

int main(void)
{
  CELL root;
  CELL *p  = &root;
  p -> prev = &root;
  int data;

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

  int index, i;
  do{
    printf("Enter the number. => ");
    scanf("%d", &data);
    printf("Enter the index. => ");
    scanf("%d", &index);

    p = &root;

    if(0 < index){
      for(i = 0;i < index;i++){
        p = p -> next;
      }
      addCELL(p, data);
    }

    printlist(root, NEXT);
    printlist(root, PREV);
  }while(0 < index);

  return 0;
}
