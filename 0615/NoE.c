#include <stdio.h>

void ff(int);

int main(void)
{
  ff(3);

  return 0;
}

void ff(int n){
  if(n>0){
    if (n%2==0) {printf("****\n"); ff(n-1);}
    else {printf("*\n"); ff(n-1);}
  }
}
