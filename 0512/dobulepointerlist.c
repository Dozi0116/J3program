#include <stdio.h>

typedef struct CELL {
  int value;
  struct CELL *next;
  struct CELL *prev;
} CELL;

int main(void)
{
  CELL *root;
  CELL **p = &root;

  printf("%p", p);

  return 0;
}
