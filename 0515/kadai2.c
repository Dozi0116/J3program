#include <stdio.h>
#include <stdlib.h>

#define ELEMENT 100

typedef struct CELL {
  char sentence[ELEMENT];
  struct CELL *next;
} CELL;

void displist(CELL);

CELL* makeCELL(){
  return (CELL *)malloc(sizeof(CELL));
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
  int s = 0, e = 0, i = 0;

  printf("Please enter the words. => ");
  fgets(data, ELEMENT, stdin);

  while(data[e] != '\0'){
    if(data[e] == ' '){
      p -> next = makeCELL();
      i = 0;
      for(;s < e;s++, i++){
        p -> next -> sentence[i] = data[s];
      }
      p -> next -> sentence[i] = '\0';
      p = p -> next;
      s++;
    }
    e++;
  }

  p -> next = makeCELL();
  p = p -> next;
  i = 0;
  for(;s < e;s++, i++){
    p -> sentence[i] = data[s];
  }
  p -> sentence[i] = '\0';

  displist(root);

  return 0;
}
