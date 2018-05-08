#include <stdio.h>
#include <stdlib.h>

#define FOMURA_SIZE 100

int set_fomura(char[], char[]);
int calc_fomura(char[]);
void push_num(int, int *, int[]);
int pop_num(int *, int []);
void push_ch(char, int *, char []);
char pop_ch(int *stack_index, char stack[]);
int level(char);
int len(char[]);

int main(void)
{
  char input[FOMURA_SIZE], fomura[FOMURA_SIZE] = "11 4 2 * + 6 -"; //example 1 2 +
  int ans;

  printf("Please enter the fomura\n=> ");
  fgets(input, FOMURA_SIZE, stdin);

  set_fomura(input, fomura);

  printf("Fomura is %s", fomura);

  ans = calc_fomura(fomura);

  printf("Answer is %d\n", ans);

  return 0;
}

int set_fomura(char input[], char fomura[])
{
  char output[FOMURA_SIZE];
  int i = 0, j = 0, k = 0, chara = 0;
  char temp;
  // insert before element
  printf("%s", input);
  for(i = 0, j = 0;input[i] != '\0';){
    output[j++] = input[i++];
    printf("%c = %c\n", output[j-1], input[i]);
    if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
      output[j++] = ' ';
      output[j++] = input[i++];
      output[j++] = ' ';
    }
  }
  output[j-1] = '\0';

  printf("%s\n", output);

  //porand
  char token[FOMURA_SIZE];

  int stack_index = 0;
  char stack[FOMURA_SIZE];

  for(i = 0, j = 0;output[i] != '\0';i++){
    j = 0;
    puts("pass2");
    while(output[i] != ' ' && output[i] != '\0'){
      token[j++] = output[i++];
    }
    token[j] = '\0';

    printf("%s\n", token);

    if(atoi(token) != 0 || token[0] == '0'){ //number
      for(j = 0;token[j] != '\0';){
        fomura[k++] = token[j++];
      }
      fomura[k++] = ' ';
    }else if(token[j] == ')'){
      do{
        temp = pop_ch(&stack_index, stack);
        if(temp != '\0' && temp == '('){
          push_ch(temp, &stack_index, stack);
        }
      }while(temp != '\0');
    }else if(token[j] == '('){
      push_ch(temp, &stack_index, stack);
    }else{

      do{
        temp = pop_ch(&stack_index, stack);
        if(temp == '\0' || (level(temp) <= level(token[0]))){
          fomura[k++] = token[j++];
          fomura[k++] = ' ';
        }else{
          fomura[k++] = temp;
          fomura[k++] = ' ';
        }
      }while(!(temp == '\0' || (level(temp) <= level(token[0]))));
    }
  }

  for(i = 0;i < 50;i++){
    printf("%c", fomura[i]);
  }
  printf("%s\n", fomura);

  return chara;
}

int calc_fomura(char fomura[])
{
  int ans = 0;
  int i;
  int a = 0, b = 0;

  int stack_index;
  int stack[FOMURA_SIZE];

  for(i = 0;fomura[i] != '\0';i++){
    if('0' <= fomura[i] && fomura[i] <= '9'){
      a = atoi(&fomura[i]);
      i += len(&fomura[i]);
      push_num(a, &stack_index, stack);
    }else{
      b = pop_num(&stack_index, stack);
      a = pop_num(&stack_index, stack);
      //printf("%d %c %d\n", a, fomura[i], b);
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
      push_num(ans, &stack_index, stack);
      i++;
    }
  }

  return ans;
}

void push_num(int num, int *stack_index, int stack[])
{
  stack[*stack_index] = num;
  //printf("stack! => %d\n", num);
  (*stack_index)++;
}

int pop_num(int *stack_index, int stack[])
{
  if((*stack_index) == 0) return -1;
  int temp = stack[--(*stack_index)];
  //printf("pop! => %d\n", temp);
  return temp;
}

void push_ch(char ch, int *stack_index, char stack[])
{
  stack[*stack_index] = ch;
  //printf("stack! => %c\n", ch);
  (*stack_index)++;
}

char pop_ch(int *stack_index, char stack[])
{
  if((*stack_index) == 0) return '\0';
  char temp = stack[--(*stack_index)];
  //printf("pop! => %c\n", temp);
  return temp;
}

int len(char str[])
{
  int i;

  for(i = 0;str[i] != ' ';i++){}

  return i;
}

int level(char operand)
{
  switch (operand) {
    case '+': case '-':
    return 1;
    case '*': case '/':
    return 2;
    case '(': case ')':
    return 3;
    case '^':
    return 4;
  }

  return -1;
}
