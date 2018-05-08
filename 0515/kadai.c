#include <stdio.h>
#include <stdlib.h>

#define ELEMENT 100

typedef struct CELL {
  char sentence[ELEMENT];
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
    printf("%s ", p -> sentence);
  }
  printf("\n");
}

int main(void)
{
  CELL root;
  CELL *p = &root;
  char data[ELEMENT];
  int i = 0;

  do{
    printf("Please enter the words. => ");
    scanf("%s", data);

    if(*data != '0'){
      p -> next = makeCELL();
      p = p -> next;
      i = 0;
      while(data[i] != '\0'){
        p -> sentence[i] = data[i];
        i++;
      }
      p -> sentence[i] = '\0';
    }
  }while(*data != '0');

  displist(root);

  return 0;
}
