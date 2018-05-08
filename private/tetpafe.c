#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define I 1
#define J 2
#define L 3
#define O 4
#define S 5
#define T 6
#define Z 7

void shuffle_box(int mino[]);
char i2b(int num);

int main(void)
{
    srand((unsigned)time(NULL));
    int i, j, k;
    int flg, success = 0, failed = 0;

    int answer[36][3] = {{I, J, T}, {I, O, J}, {I, S, J}, {I, T, J}, {I, T, L},
                         {I, T, O}, {I, T, S}, {I, Z, L}, {J, I, T}, {J, S, T},
                         {J, T, I}, {J, Z, S}, {L, I, T}, {L, T, I}, {O, I, J},
                         {O, J, I}, {O, J, T}, {S, I, J}, {S, J, I}, {T, I, J},
                         {T, I, L}, {T, I, O}, {T, I, S}, {T, J, I}, {T, J, L},
                         {T, J, S}, {T, L, I}, {T, L, J}, {T, O, I}, {T, S, J},
                         {T, S, Z}, {T, Z, S}, {Z, I, L}, {Z, J, S}, {Z, L, I},
                         {Z, S, J}};

    int hold_table[8][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {0, 2, 1},
                            {1, 2, 3}, {1, 2, 0}, {1, 0, 3}, {1, 0, 2}};

    int mino[7] = {I, J, L, O, S, T, Z};

    for(i = 0;i <100000;i++){
        shuffle_box(mino);
        printf("mino => %c, %c, %c, %c",
        i2b(mino[0]), i2b(mino[1]), i2b(mino[2]), i2b(mino[3]));
        flg = 0;
        for(j = 0;j < 36;j++){
            for(k = 0;k < 8;k++){
              if(mino[hold_table[k][0]] == answer[j][0] && mino[hold_table[k][1]] == answer[j][1] && mino[hold_table[k][2]] == answer[j][2]){
                    if(flg == 1){
                      printf("                  ");
                    }
                    flg = 1;
                    printf(" => hold! %c, %c, %c\n",
                     i2b(mino[hold_table[k][0]]),
                     i2b(mino[hold_table[k][1]]),
                     i2b(mino[hold_table[k][2]]));
               }
            }
        }
        if(flg == 1){
            success++;
        }else{
            failed++;
            printf(" => failed...\n");
        }
    }

    printf("success : %d\nfailed : %d\n", success, failed);
    return 0;
}

void shuffle_box(int mino[])
{
    int a, b, i, temp;

    for(i = 0; i < 20;i++){
    a = rand() % 7;
    b = rand() % 7;

    //swap
    temp = mino[a];
    mino[a] = mino[b];
    mino[b] = temp;
    }

}

char i2b(int num)
{
    switch(num){
      case I:
      return 'I';
      case J:
      return 'J';
      case L:
      return 'L';
      case O:
      return 'O';
      case S:
      return 'S';
      case T:
      return 'T';
      case Z:
      return 'Z';
    }

    return '*';
}
