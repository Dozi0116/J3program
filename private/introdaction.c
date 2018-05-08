#include <stdio.h>

int main(int argc, char const *argv[]) {
  int *a = NULL; //init is important
  printf("%p\n", a);
  return 0;
}

typedef struct{
  int value;
  int *vp;
} cell;
