#include <stdio.h>
#include <stdlib.h>

#define makeTREE() (TREE *)malloc(sizeof(TREE *))

typedef struct TREE {
  struct TREE *left;
  int value;
  struct TREE *right;
} TREE;

void printTREE(TREE *root)
{
  printf("/%d", root -> value);
  if(root -> right != NULL) printTREE(root -> right);
  if(root -> left != NULL) printTREE(root -> left);
  printf("/..");
}

void print_TREE(TREE *root, int depth)
{
  int i;
  if(root -> right != NULL) print_TREE(root -> right, depth+1);
  for(i = 0;i < depth;i++){
    printf("     ");
  }
  printf("%d\n", root -> value);
  if(root -> left != NULL) print_TREE(root -> left, depth+1);
}

int search(int data, TREE *root)
{
  if(data < root -> value){
    if(root -> left != NULL) data = search(data, root -> left);
    else return -1;
  }
  if(root -> value < data){
    if(root -> right != NULL) data = search(data, root -> right);
    else return -1;
  }
  if(data == root -> value){
    if(root -> right != NULL){
      if(data == root -> right -> value) data = search(data, root -> right);
    }
    return ++data;
  }

  return data;
}

void searchTREE(TREE *root)
{
  int data, result;
  do{
    printf("Please enter the search number. => ");
    scanf("%d", &data);

    result = search(data, root);

    if(result != -1){
      printf("Search success! %dfound.\n", result - data);
    }else{
      printf("Search Failed...\n");
    }
  }while(0 < data);
}

int main(void)
{
    TREE *root = makeTREE();
    root -> right = NULL;
    root -> left = NULL;

    int data;
    TREE *t = root;

    printf("Init num => ");
    scanf("%d", &data);
    root -> value = data;

    while(1){
      printf("Please enter the number. => ");
      scanf("%d", &data);

      if(0 < data){
        t = root;
        while(1){
          printf("(%d) -> ", t -> value);
          if(data == t -> value){
            puts("Eroor. Value is equel.");
            break;
          }
          if(data < t -> value){
            if(t -> left == NULL){
              t -> left = makeTREE();
              t = t -> left;
              printf("makeLEFT\n");
              break;
            }
            t = t -> left;
          }else{
            if(t -> right == NULL){
              t -> right = makeTREE();
              t = t -> right;
              printf("makeRIGHT\n");
              break;
            }
            t = t -> right;
          }
        }
        t -> value = data;
        t -> left = NULL;
        t -> right = NULL;
      }
      else break;
    }

    print_TREE(root, 0);

    searchTREE(root);

    return 0;
}
