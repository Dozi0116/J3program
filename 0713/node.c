#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  struct NODE *left;
  int value;
  struct NODE *right;
} NODE;

NODE ** searchNODE(NODE **cell, int data);
NODE * makeNODE(int data);
void printNODE(NODE *cell, int depth);
void deleteNODE(NODE **p); //未完成

int main(void)
{
  NODE *root = NULL;
  NODE **insert = NULL;
  // NODE **delete = NULL;
  int data;

  //make
  do{
    printf("Input data => ");
    scanf("%d", &data);

    if(data > 0){
      insert = searchNODE(&root, data);
      if(*insert == NULL) *insert = makeNODE(data);
      else printf("Error. value was already added.\n");
    }
  }while(data > 0);

  printNODE(root, 0);

  // //search
  // do{
  //   printf("Search data => ");
  //   scanf("%d", &data);
  //
  //   if(data > 0){
  //     deleteNODE(root,data);
  //   }
  // }while(data > 0);

  return 0;
}

//各ノード内の値を探し、値が見つかればその値が入ったポインタを返す。見つからない場合は
//その値が入るべきポインタを返す。
NODE ** searchNODE(NODE **cell, int data)
{
  if(*cell != NULL){
    if((*cell) -> value > data){
      //printf("in left!\n");
      return searchNODE(&((*cell) -> left), data);
    }
    else if((*cell) -> value < data){
      //printf("in right!\n");
      return searchNODE(&((*cell) -> right), data);
    }
  }
  else return cell; //NULLだった場合の終着点(葉にたどり着いたところ)

  return cell; //同じ数字があった場合の終着点(その数が入ったポインタを返す)
}

//探索木のノードを作成し、そのポインタを返す。
NODE * makeNODE(int data)
{
  NODE *cell = (NODE *)malloc(sizeof(NODE *));
  cell -> left = NULL;
  cell -> right = NULL;
  cell -> value = data;
  return cell;
}

//二分探索木を通りがけ法により表示。
void printNODE(NODE *cell, int depth)
{
  int i;
  if(cell -> right != NULL) printNODE(cell -> right, depth+1);
  for(i = 0;i < depth;i++){
    printf("     ");
  }
  printf("%2d\n", cell -> value);
  if(cell -> left != NULL) printNODE(cell -> left, depth+1);
}

// //指定された値が入っているノードを削除
// void deleteNODE(NODE *root, int data)
// {
//   //値が入ったノードを見つける
//
// }
