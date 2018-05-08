#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 50
#define TABLE_SIZE 50

typedef struct data {
  int id;
  char name[NAME_MAX];
  int state; //0 ... 空, 1 ... データが入っている, 2 ... 削除済み
} DATA;

int insert_data(DATA table[], int id, char name[]);
int delete_data(DATA table[], int id);
void show_data(DATA table[]);
int hash_function(int num);

int main(void)
{
  int ope;
  DATA table[TABLE_SIZE];

  while(1){


    do{
      printf("Select mode:\n");
      printf("1: Insert, 2: Delete, 3: Show data, 0: Exit\n");
      printf("=> "); scanf("%d", &ope);
    }while(ope < 0 || 3 < ope);

    int num;
    char name[NAME_MAX];
    int result;

    switch(ope){
      case 1:
      {
        do{
          printf("Insert mode\n");
          printf("Please enter the number\n=> "); scanf("%d", &num);
        }while(num < 0);
        printf("Please enter the name\n=> "); scanf("%s", name);

        result = insert_data(table, num, name);

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

        result = delete_data(table, num);

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

int insert_data(DATA table[], int id, char name[]) {
  int id_temp = id;
  int key;
  int hash_count = 0; //リハッシュする回数、TABLE_SIZE回リハッシュしたら強制終了

  do{
    key = hash_function(id_temp);
    if(table[key].state == 1){
      if(table[key].id == id) return -1;
      id_temp++;
      hash_count++;
    }
    if(hash_count > TABLE_SIZE) return -1; //全部の配列を見てダメだったら失敗
  }while(table[key].state == 1);

  table[key].id = id;
  strcpy(table[key].name, name);
  table[key].state = 1;

  return 0;
}

int delete_data(DATA table[], int id)
{
  int id_temp = id;
  int key;
  int hash_count = 0;

  while("infinity loop"){
    key = hash_function(id_temp);
    printf("key => %d\n", key);
    if(table[key].state == 0) return -1;//続くデータがない場合は失敗
    if(table[key].id == id && table[key].state == 1) break;
    printf("rehash!\n");
    hash_count++;
    id_temp++;
    if(hash_count > TABLE_SIZE) return -1;//調べ尽くした場合も失敗
  }

  table[key].state = 2;
  return 0;
}

void show_data(DATA table[])
{
  int i;
  for(i = 0;i < TABLE_SIZE;i++){
    if(table[i].state == 1){
      printf("[%d]%s\n", table[i].id, table[i].name);
    }
  }
}

int hash_function(int num) {
  return num % TABLE_SIZE;
}
