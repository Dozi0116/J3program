#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 5
#define TEMP_SIZE 15

#define NONE -1
#define FALSE 0
#define TRUE 1

// realloc(DFAstate, sizeof(STATE *) * TEMP_SIZE * 新要素数)と同義
#define STATEalloc(num) realloc(DFAstate, sizeof(STATE *) * TEMP_SIZE * num)

typedef struct STATE{
  int index; //状態の通し番号。基本的には配列の番号と同じ。
  char condition[SIZE]; // 遷移する条件。a〜zはその文字に対応。!はイプシロンに対応。
  struct STATE *next[SIZE]; //次の遷移先
} STATE;

typedef struct DFA_TABLE{
  //ここからつくる　DFA状態表
  STATE *state_address[TEMP_SIZE];
  char condition;
  int check_flg;
} DFA_TABLE;

void init_state(STATE *state);
void clear_temp_set(STATE *temp_set[]);
void init_DFAtable(DFA_TABLE DFAtable[]);
void set_transition(STATE *state, int index, char condition, STATE *next);
void show_about_state(STATE state);
void show_about_DFAstate(DFA_TABLE table[]);
void show_about_temp_set(STATE *temp_set[]);
int calc_upsilon(STATE *state, STATE *set[TEMP_SIZE], int set_index);
void set_DFAstate(STATE *set[TEMP_SIZE], char condition, DFA_TABLE table[]);
int check_no_flg_DFAtable(DFA_TABLE table[]);
int check_diff_DFAstate(STATE *set[TEMP_SIZE], DFA_TABLE table[]);
void init_flg(int flg[], int initial);

int main(void) {
  //make NFAstate
  STATE state[15];
  int i, j;
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

  for(i = 0;i < 10;i++){
    printf("state[%d] : %p\n", i, &state[i]);
    show_about_state(state[i]);
  }

  // // STATE *DFAstate[0][TEMP_SIZE];と同じ。
  // // STATEalloc(新要素数);で量を取り直すこと。
  // int count_state_size = 0;
  // STATE **DFAstate = (STATE **)malloc(sizeof(STATE *) * TEMP_SIZE * count_state_size++);

  //convert to DFA
  STATE *temp_set[TEMP_SIZE];
  DFA_TABLE DFAtable[TEMP_SIZE];
  init_DFAtable(DFAtable);

  //初期状態のイプシロン遷移を求め、DFA状態表に登録する。
  clear_temp_set(temp_set);
  temp_set[0] = &state[0]; //要修正
  calc_upsilon(&state[0], &temp_set[1], 0);
  set_DFAstate(temp_set, 0, DFAtable);

  show_about_DFAstate(DFAtable);

  int table_index;

  //DFA状態表に印がついていない状態が存在するならループ
  while(check_no_flg_DFAtable(DFAtable) != -1){
    table_index = check_no_flg_DFAtable(DFAtable);
    //DFA状態に印をつける
    DFAtable[table_index].check_flg = TRUE;
    printf("check ... DFAtable[%d]\n", table_index);

    char search;
    int set_index = 0;
    //すべての文字cについて(数字にも対応予定)
    for(search = 'a';search <= 'z';search++){
      for(i = 0;DFAtable[table_index].state_address[i] != NULL;i++){
        clear_temp_set(temp_set);
        set_index = 0;
        //DFA状態に含まれるNFA状態から、文字cで遷移可能なNFA状態の集合を求める。
        for(j = 0;DFAtable[table_index].state_address[i] -> condition[j] == search;j++){
          printf("hit! condition : %c\n", search);
          temp_set[set_index++] = DFAtable[table_index].state_address[i] -> next[i];
        }
        int set_index2 = set_index;
        //求めた集合のイプシロン遷移を求める
        show_about_temp_set(temp_set);
        for(set_index--;set_index >= 0;set_index--){
          printf("set_index = %d, set_index2 = %d\n", set_index, set_index2);
          calc_upsilon(temp_set[set_index], &temp_set[set_index2], 0);
        }

        //もし、DFA状態表に未登録であるなら、
        if(check_diff_DFAstate(temp_set, DFAtable) && temp_set[0] != NULL){
          //DFA状態表に登録する。
          set_DFAstate(temp_set, search, DFAtable);
        }
      }
    }
  }

  show_about_DFAstate(DFAtable);

  return 0;
}

//状態の初期化。
void init_state(STATE *state) {
  int i;
  for(i = 0;i < SIZE;i++){
    state -> condition[i] = 0;
    state -> next[i] = NULL;
  }
}

//temp_setを使いまわすための初期化。
void clear_temp_set(STATE *temp_set[]) {
  int i;
  for(i = 0;i < TEMP_SIZE;i++){
    temp_set[i] = NULL;
  }
}

//DFAtableの初期化。
void init_DFAtable(DFA_TABLE DFAtable[]) {
  int i, j;
  for(i = 0;i < TEMP_SIZE;i++){
    for(j = 0;j < TEMP_SIZE;j++){
      DFAtable[i].state_address[j] = NULL;
    }
    DFAtable[i].check_flg = NONE;
    DFAtable[i].condition = 0;
  }
}

//状態遷移の登録。
void set_transition(STATE *state, int index, char condition, STATE *next) {
  state -> condition[index] = condition;
  state -> next[index] = next;
}

//NFA,DFAの表示
void show_about_state(STATE state) {
  int i;
  for(i = 0;state.condition[i] != 0;i++){
    printf("  condition[%d] = %c\n", i, state.condition[i]);
    printf("    next[%d] = %p\n", i, state.next[i]);
  }

  printf("\n");
}

//DFA状態表の表示
void show_about_DFAstate(DFA_TABLE table[]) {
  int i, j;
  for(i = 0;table[i].check_flg != NONE;i++){
    printf("state[%d], condition = %c\n", i, table[i].condition);
    for(j = 0;table[i].state_address[j] != NULL;j++){
      printf("  address[%d] : %p\n", j, table[i].state_address[j]);
    }
    printf("\n");
  }
}

void show_about_temp_set(STATE *temp_set[]) {
  int i;
  for(i = 0;temp_set[i] != NULL;i++){
    printf("temp_set[%d] : %p\n", i, temp_set[i]);
  }
}

//イプシロン遷移を求める(再帰処理が間違っている可能性が…)
int calc_upsilon(STATE *state, STATE *set[TEMP_SIZE], int set_index) {
  int i = 0;
  int temp_set_index = set_index;

  int next_index = 0;
  for(i = 0;state -> next[i] != NULL;i++){
    //この上の文章に問題あり…?
    if(state -> condition[i] == '!'){
      set_index = calc_upsilon(set[i], set, set_index);
    }
  }
  //
  // if(set_index == temp_set_index){
  //   return set_index;
  // }
  // int k = set_index - 1;
  //
  // for(;k >= temp_set_index;k--){
  //   set_index = calc_upsilon(set[k], set, set_index);
  // }

  set[set_index++] = state;
  return set_index;
}

//DFA状態表(DFAstate)に状態を登録する。
void set_DFAstate(STATE *set[TEMP_SIZE], char condition, DFA_TABLE table[]) {
  static int table_index = 0;
  int i;

  for(i = 0;set[i] != NULL;i++){
    table[table_index].state_address[i] = set[i];
  }

  table[table_index].check_flg = FALSE;
  table[table_index].condition = condition;
  table_index++;
}

//DFA状態表を参照し、check_flgがFALSEのときに、FALSEのインデックスを返す
int check_no_flg_DFAtable(DFA_TABLE table[]) {
  int i;
  for(i = 0;i < TEMP_SIZE;i++){
    if(table[i].check_flg == FALSE) return i;
  }

  return -1;
}

//DFAtableの中に同じ状態がないか確認。　同じ状態があるなら、FALSEを返す。
int check_diff_DFAstate(STATE *set[], DFA_TABLE table[]) {
  int i, j, k, l;
  int diff_flg[TEMP_SIZE];
  int result;
  init_flg(diff_flg, TRUE);

  for(i = 0;table[i].check_flg != NONE;i++){
    for(j = 0;set[j] == NULL;j++){
      for(k = 0;table[i].state_address[k] != NULL;k++){
        if(set[j] == table[i].state_address[k]){
          diff_flg[j] = FALSE;
        }
      }
    }

    for(l = 0;l < TEMP_SIZE;l++){
      result += diff_flg[l];
    }
    if(result == 0){
      return FALSE;
    }
  }

  return TRUE;
}

void init_flg(int flg[], int initial) {
  int i;
  for(i = 0;i < TEMP_SIZE;i++){
    flg[i] = initial;
  }
}
