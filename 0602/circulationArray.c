#include <stdio.h>

#define ELEMENT 5
#define next(a) (((a) + 1) % ELEMENT)

int menu(void);

int main(void)
{
  int array[ELEMENT] = {0};
  int ope;
  int data;
  int f, r;
  int i;
  f = r = 0;

  while(1){
    ope = menu();
    switch(ope){
      case 1:
        if(f == next(r)) break;
        printf("Please enter the number => ");
        scanf("%d", &data);
        array[r] = data;
        r = next(r);
      break;

      case 2:
        if(f == r) break;
        data = array[f];
        array[f] = 0;
        f = next(f);
        printf("%d is popped.\n", data);
      break;

      case 3:
        for(i = f;i != r;i = next(i)){
          printf("%d -> ", array[i]);
        }
        printf("\n");
      break;

      default:
        return 0;
      break;
    }
  }
  return 0;
}

int menu(void)
{
  int ope;
  puts("Prease enter the operation.");
  puts("1: add");
  puts("2: delete");
  puts("3: display");
  printf("=> ");
  scanf("%d", &ope);

  return ope;
}
