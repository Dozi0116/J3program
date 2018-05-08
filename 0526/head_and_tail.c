#include <stdio.h>
#include <stdlib.h>

#define NEXT 0
#define PREV 1

typedef struct CELL {
  struct CELL *prev;
  int value;
  struct CELL *next;
} CELL;

struct CELL* makeCELL();
void insert(struct CELL **, struct CELL **, int);
int delete(struct CELL **, struct CELL **);
void printlist(struct CELL *, struct CELL *, int);
void menu(struct CELL *, struct CELL *);

int main(void)
{
  CELL *head, *tail;
  head = makeCELL();
  tail = head;
  int data;


  printf("initialize list\n");
  do{
    printf("Enter the number. => ");
    scanf("%d", &data);
    if(0 < data){
      tail -> next = makeCELL();
      tail -> next -> prev = tail;
      tail = tail -> next;
      tail -> value = data;
    }
  }while(0 < data);
  if(head -> next != NULL){
    head = head -> next;
    tail -> next = head;
    head -> prev = tail;
  }

  menu(head, tail);

  return 0;
}

CELL* makeCELL()
{
  return (CELL *)malloc(sizeof(CELL *));
}

void insert(CELL **head, CELL **tail, int data)
{
  (*tail) -> next = makeCELL();
  (*tail) -> next -> prev = *tail;
  *tail = (*tail) -> next;
  (*tail) -> value = data;
  (*tail) -> next = *head;
  (*head) -> prev = *tail;
}

int delete(CELL **head, CELL **tail)
{
  if(*head == *tail)return -1;

  int pop = (*head) -> value;
  CELL *p = *head;
  *head = (*head) -> next;
  (*head) -> prev = *tail;
  free(p);
  return pop;
}


void printlist(CELL *head, CELL *tail, int mode)
{
  CELL *p;

  switch(mode){
    case NEXT:
      for(p = head;p != tail;p = p -> next){
        printf("%d -> ", p -> value);
      }
      printf("%d -> ...\n", p -> value);
    break;

    case PREV:
      for(p = tail;p != head; p = p -> prev){
        printf("%d -> ", p -> value);
      }
      printf("%d -> ...\n", p -> value);
    break;

    default: {printf("Eroor.\n"); exit(-1);}
  }
}

void menu(CELL *head, CELL *tail)
{
  int data;

  while(1){
    system("clear");

    printf(
    "Please select operation.\n"
    "1. Insert list\n"
    "2. Delete list\n"
    "3. Display list\n"
    "0. Exit\n"
    "=> ");
    scanf("%d", &data);

    switch(data){
      case 1:
        printf("Enter the number. => ");
        scanf("%d", &data);
        printf("head => %p, tail => %p\n", head, tail);
        insert(&head, &tail, data);
        printf("head => %p, tail => %p\n", head, tail);
      break;

      case 2:
        delete(&head, &tail);
      break;

      case 3:
        printlist(head, tail, NEXT);
        printlist(head, tail, PREV);
        scanf("%*c%*c");
      break;

      case 0:
        exit(1);
      break;
    }
  }
}
