#include <stdio.h>
#include <stdlib.h>

#define FOMURA_SIZE 100

int set_fomura(char[], char[]);
int calc_fomura(char[]);
void push(int);
int pop();

int stack_index;
int stack[FOMURA_SIZE];

int main(void)
{
  char /*input[FOMURA_SIZE],*/ fomura[FOMURA_SIZE] = "142*+6-";
  int ans;

  /*printf("Please enter the fomura\n=> ");
  fgets(input, FOMURA_SIZE, stdin);

  set_fomura(input, fomura);

  printf("Fomura is %s", fomura);*/

  ans = calc_fomura(fomura);

  printf("Answer is %d\n", ans);

  return 0;
}

int set_fomura(char input[], char output[])
{
  int i = 0, chara = 0;
  for(i = 0;input[i] != '\0';i++){
    if(input[i] != ' '){
      output[chara] = input[i];
      chara++;
    }
  }

  //porand

  return chara;
}

int calc_fomura(char fomura[])
{
  int ans = 0;
  int i;
  int a, b;
  for(i = 0;fomura[i] != '\0';i++){
    if('0' <= fomura[i] && fomura[i] <= '9'){
      char ch = fomura[i];
      push(atoi(&ch));
    }else{
      b = pop();
      a = pop();
      printf("%d %c %d\n", a, fomura[i], b);
      switch(fomura[i]){
        case '+':
          ans = a + b;
        break;

        case '-':
          ans = a - b;
        break;

        case '*':
          ans = a * b;
        break;

        case '/':
          ans = a / b;
        break;

        default:
          printf("Error.\n");
        break;
      }
      push(ans);
    }
  }

  return ans;
}

void push(int num)
{
  stack[stack_index] = num;
  printf("stack! => %d\n", num);
  stack_index++;
}

int pop(void)
{
  int temp = stack[--stack_index];
  printf("pop! => %d\n", temp);
  return temp;
}
