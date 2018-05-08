#include <stdio.h>

void fff(int, int, int);
void stars(int);
void spaces(int);

int main(void)
{
  fff(3, 4, 1);
  return 0;
}

void fff (int n, int k, int s)
{
  if (n > 0){
    fff (n - 1, k, s);
    // printf("%d, %d, %d\n", n, k, s);
    spaces(k); stars(s); printf("\n");
    fff (n - 1, s, k);
  }
}

void stars(int num)
{
  if(num > 0) {
    printf("*");
    stars(num - 1);
  }
}

void spaces(int num)
{
  if(num > 0) {
    printf(" ");
    spaces(num - 1);
  }
}
