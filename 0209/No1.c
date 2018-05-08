#include <stdio.h>

void state0(char *index, int *state);
void state1(char *index, int *state);
void state2(char *index, int *state);

int main(void) {
  char str[] = "aba";
  char *index = str;
  int state = 0;

  state0(index, &state);

  if(state == 2){
    printf("Match!!!\n");
  }else{
    printf("Not match!!!\n");
  }

  return 0;
}

void state0(char *index, int *state) {
  if(*index == 'a'){
    *state = 1;
    state1(++index, state);
  }else{
    return;
  }
}

void state1(char *index, int *state) {
  if(*index == 'a'){
    *state = 2;
    state2(++index, state);
  }else if(*index == 'b'){
    *state = 1;
    state1(++index, state);
  }else{
    return;
  }
}

void state2(char *index, int *state) {
  if(*index == 'a'){
    *state = 2;
    state2(++index, state);
  }else if(*index == 'b'){
    *state = 1;
    state1(++index, state);
  }else{
    if(*index != '\0') *state = -1;
    return;
  }
}
