#include <stdio.h>

#define CHARACTERS 200
#define WORDS 10
#define WORD_CHARACTERS 20

void new_buffer_to_array(char buffer[CHARACTERS], char note[WORDS][WORD_CHARACTERS]);
int value(char ch);

int main(void)
{
  char buffer[CHARACTERS] = "My name is Dozi!";
  char note[WORDS][WORD_CHARACTERS];

  int states[4][3] = {
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 3},
    {3, 3, 3}
  };

  char  actions[4][3] = {
    {'c', 'a', 'c'},
    {'c', 'a', 'c'},
    {'b', 'a', 'c'},
    {'c', 'c', 'c'}
  };

  printf("%s\n", buffer);

  int i, j, k, now = 0, next;
  char action;

  for(i = 0;i < WORDS;i++){
    note[i][0] = '\0';
  }

  i = j = k = 0;

  while(now != 3){
    printf("k = %d\n", k);
    action = actions[now][value(buffer[k])];
    next = states[now][value(buffer[k])];
    printf("charcter => %c\n", buffer[k]);
    printf("action => %c\n", action);
    printf("next => %d\n\n", next);

    switch(action){
      case 'a':
      note[i][j] = buffer[k];
      k++;
      j++;
      break;
      case 'b':
      note[i][j] = '\0';
      j = 0;
      i++;
      k++;
      break;
      case 'c':
      note[i][j] = '\0';
      break;
    }
    now = next;
  }

  for(i = 0;note[i][0] != '\0';i++){
    printf("%s\n", note[i]);
  }

  return 0;
}

int value(char ch)
{
  switch(ch){
    case ' ':
    return 0;
    case '\0':
    return 2;
    default:
    return 1;
  }
  return -1;
}
