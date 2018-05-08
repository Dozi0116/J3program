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
  CELL root;
  CELL *p = &root;
  int data;
  int i;
  root.next = NULL;

  //makelist
  do{
    printf("Enter the number => ");
    scanf("%d", &data);
    if(data > 0){
      p -> next = makeCELL();
      p = p -> next;
      p -> value = data;
    }
  }while(data > 0);
  p -> next = NULL;

  //displist
  for(p = root.next;p != NULL;p = p -> next){
    printf("%d ", p -> value);
  }
  printf("\n");

  //addlist
  CELL *x;
  int index;

  do{
    printf("Enter the number. => ");
    scanf("%d", &data);
    printf("Enter the index. => ");
    scanf("%d", &index);

    if(data > 0){
      for(p = &root, i = 0;i < index - 1;i++){
        p = p -> next;
      }
      x = makeCELL();
      x -> value = data;
      x -> next = p -> next;
      p -> next = x;
    }
    //displist
    for(p = root.next;p != NULL;p = p -> next){
      printf("%d ", p -> value);
    }
    printf("\n");
  }while(data > 0);


  return 0;
}
