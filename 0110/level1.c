/* a(a|b)*aの状態遷移を作る */
#include <stdio.h>

#define SIZE 5

typedef struct STATE{
  char condition[SIZE]; // 遷移する条件。a〜zはその文字に対応。!はイプシロンに対応。
  struct STATE *next[SIZE]; //次の遷移先
} STATE;

void init_state(STATE *state);
void set_transition(STATE *state, int index, char condition, STATE *next);
void show_about_state(STATE state);

int main(void)
{
  STATE state[15];
  int i;
  for(i = 0;i < 15;i++){
    init_state(&state[i]);
  }

  set_transition(&state[0], 0, 'a', &state[1]);
  set_transition(&state[1], 0, '!', &state[2]);
  set_transition(&state[2], 0, '!', &state[3]);
  set_transition(&state[3], 0, 'a', &state[4]);
  set_transition(&state[4], 0, '!', &state[7]);
  set_transition(&state[2], 1, '!', &state[5]);
  set_transition(&state[5], 0, 'b', &state[6]);
  set_transition(&state[6], 0, '!', &state[7]);
  set_transition(&state[7], 0, '!', &state[2]);
  set_transition(&state[2], 2, '!', &state[8]);
  set_transition(&state[8], 0, 'a', &state[9]);
  set_transition(&state[9], 0, 0, NULL);

  for(i = 0;i < 8;i++){
    show_about_state(state[i]);
  }
  return 0;
}

void init_state(STATE *state)
{
  int i;
  for(i = 0;i < SIZE;i++){
    state -> condition[i] = 0;
    state -> next[i] = NULL;
  }
}

void set_transition(STATE *state, int index, char condition, STATE *next)
{
  state -> condition[index] = condition;
  state -> next[index] = next;
}

void show_about_state(STATE state)
{
  printf("statenumber => %d\n", state.number);

  int i;
  for(i = 0;state.condition[i] != 0;i++){
    printf("condition[%d] = %c\n", i, state.condition[i]);
    printf("next[%d] = %p\n", i, state.next[i]);
  }

  printf("\n");
}
