#include <stdio.h>
//1 -> 2(1) -> 3(1)(2) -> 4(1)(2)(3) -> 5(1)(2)(3)(4) -> ...
//1 -> 0,(1) -> 1,(1),(0,1) -> 0,(1)(0,1)(1,1,0,1) ->

void new_hanoi(int n)
{
  int i;
  int to;
  to = n % 2;
  printf("move!(%d)", n);
  switch(to){
    case 0:
      printf("left\n");
    break;
    case 1:
      printf("right\n");
    break;
  }
  for(i = 1;i < n;i++){
    new_hanoi(i);
  }
}

int main(void)
{
  int i;
  for(i = 1;i <= 5;i++){
    new_hanoi(i);
  }
  return 0;
}
