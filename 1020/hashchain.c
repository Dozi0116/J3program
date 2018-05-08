#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

typedef struct data {
  int id;
  char *name;
  struct data *next;
} DATA;

void init(DATA *table[]);
int hash_function(int num);
int insert_data(DATA **root, int num, char *str);
int delete_data(DATA **root, int num);
DATA *makeDATA(int num, char *str);
void show_data(DATA *table[]);

int main(void)
{
  int ope;
  DATA *table[TABLE_SIZE];

  init(table);

  while(1){


    do{
      printf("Select mode:\n");
      printf("1: Insert, 2: Delete, 3: Show data, 0: Exit\n");
      printf("=> "); scanf("%d", &ope);
    }while(ope < 0 || 3 < ope);

    int num;
    char *name = (char *)malloc(sizeof(char *));
    int index;
    int result;

    switch(ope){
      case 1:
      {
        do{
          printf("Insert mode\n");
          printf("Please enter the number\n=> "); scanf("%d", &num);
        }while(num < 0);
        printf("Please enter the name\n=> "); scanf("%s", name);

        index = hash_function(num);
        result = insert_data(&table[index], num, name);

        if(0 <= result){
          printf("Insert successed!\n");
        }else{
          printf("Insert failed...\n");
        }
        break;
      }
      case 2:
      {
        do{
          printf("Insert mode\n");
          printf("Please enter the number\n=> "); scanf("%d", &num);
        }while(num < 0);

        index = hash_function(num);
        result = delete_data(&table[index], num);

        if(0 <= result){
          printf("Delete successed!\n");
        }else{
          printf("Delete failed...\n");
        }
        break;
      }
      case 3:
      {
        show_data(table);
        break;
      }

      case 0: return 0;

    }

  }

  return -1;
}

void init(DATA *table[])
{
  int i;
  for(i = 0;i < TABLE_SIZE;i++){
    table[i] = makeDATA(-1, "none");
  }
}

int hash_function(int num)
{
  return num % TABLE_SIZE;
}

int insert_data(DATA **root, int num, char *str)
{
  DATA *p, *q;
  for(p = *root;p != NULL;p = p -> next){
    printf("p -> id = %d\n", p -> id);
    if(p -> id == num){
      return -1;
    }
  }

  for(q = *root;q -> next != p;q = q -> next);

  q -> next = makeDATA(num, str);
  return 0;
}

int delete_data(DATA **root, int num)
{
  DATA *p, *q;

  for(p = *root;p != NULL;p = p -> next){
    if(p -> id == num){
      for(q = *root;q -> next != p;q = q -> next);
      if(p -> next != NULL){
        q -> next = q -> next -> next;
      }else{
        q -> next = NULL;
      }
      free(p);
      return 0;
    }
  }

  return -1;
}

void show_data(DATA *table[])
{
  int i;
  DATA *p;
  for(i = 0;i < TABLE_SIZE;i++){
    for(p = table[i] -> next;p != NULL;p = p -> next){
      printf("[%d]%s,", p-> id, p -> name);
    }
    printf("\n");
  }
}

DATA *makeDATA(int num, char *str)
{
  DATA *cell = (DATA *)malloc(sizeof(DATA *));

  cell -> next = NULL;
  cell -> id = num;
  cell -> name = str;

  return cell;
}
