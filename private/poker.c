#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termio.h>

#define TRAMP 52 //NO joker
#define HAND 5

void init(int []);
void swap(int *, int *);
void deal(int [], int [], int *);
void print_card(int);
void shuffle(int [], int);

void init(int cards[])
{
  srand((unsigned)time(NULL));
  int i;

  for(i = 0;i < TRAMP;i++){
    cards[i] = i;
  }
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void deal(int cards[], int hands[], int *current)
{
  int i;
  for(i = 0;i < HAND;i++){
    hands[i] = cards[*current];
    (*current)++;
  }
}

void print_card(int card)
{
  switch(card / 13){
    case 0:
      printf("♦ ");
    break;
    case 1:
      printf("♣ ");
    break;
    case 2:
      printf("♥ ");
    break;
    case 3:
      printf("♠ ");
    break;
  }
  printf("%2d  ", card % 13 + 1);

}


void shuffle(int cards[], int elements)
{
  int i, a, b;

  for(i = 0;i < elements * 3;i++){
    a = rand() % elements;
    b = rand() % elements;
    swap(&cards[a], &cards[b]);
  }
}

void exchange(int cards[], int hands[], int *current, int change[])
{
  int i = 0;
  for(i = 0;i < HAND;i++){
    if(change[i] == 0){
      hands[i] = cards[*current];
      (*current)++;
    }
  }
}

int check(int hands[])
{
  int i, j;
  int flag = 0;
  /* flag
  0 ... no pair
  1 ... one pair
  2 ... two pair(1+1)
  3 ... three cards(1+1+1)
  4 ... full house
  5 ... straight
  6 ... four cards
  7 ... flush
  8 ... straight flush
  9 ... royal straight flush*/

  //check pair
  int pair = 0;
  for(i = 0;i < HAND;i++){
    for(j = i + 1;j < HAND;j++){
      if(hands[i] % 13 == hands[j] % 13){
        pair++;
      }
    }
  }
  flag = pair;
  printf("pair OK\n");

  //check straight
  /*int chain;
    for(i = 0;i < HAND;i++){
      chain = 0;
      for(j = 0;j < HAND;i++){
        printf("before if\n");
        if(abs(hands[i] % 13 - hands[j] % 13) >= 2 || (hands[i] % 13 >= 11 && hands[j] % 13 == 0)){
          chain++;
        }
      }
      if(chain == 5){
        flag = 5;
      }
    }*/


  //check flush
  int marks[4] = {0};
  for(i = 0;i < HAND; i++){
    int temp = hands[i] / 13;
    marks[temp]++;
  }

  for(i = 0;i < 4;i++){
    if(marks[i] >= 5){
      if(flag == 5){
        flag = 8;
      }else{
        flag  = 7;
      }
    }
  }

  switch(flag){
    case 0:
      printf("no pair...\n");
    break;
    case 1:
      printf("one pair!\n");
    break;
    case 2:
      printf("two pairs!\n");
    break;
    case 3:
      printf("three of a kind!\n");
    break;
    case 4:
      printf("full house!!\n");
    break;
    case 5:
      printf("straight!!\n");
    break;
    case 6:
      printf("four of a kinds!!!\n");
    break;
    case 7:
      printf("flush!!\n");
    break;
    case 8:
      printf("straight flush!!!!!\n");
    break;
    case 9:
      printf("まだこの役は判別できないはずなのに…なぜ表示された？\n");
    break;
  }

  return flag;
}

char getChar(void)
{
	struct termio old_term, new_term;

	char	c;

	/* 現在の設定を得る */
	ioctl(0, TCGETA, &old_term);

	/* 設定のコピーをつくる */
	new_term = old_term;

	/* 入力文字のエコーを抑止する場合 */
	new_term.c_lflag &= ~(ICANON | ECHO);

	/* エコーは止めない場合 */
	//new_term.c_lflag &= ~(ICANON);

	/* 新しい設定を反映する */
	ioctl(0, TCSETAW, &new_term);

	/* 1 文字入力 */
	c = getchar();

	/* 古い設定に戻す */
	ioctl(0, TCSETAW, &old_term);

	return (c);
}


int main(void)
{
  int cards[TRAMP]; //tramps
  int hands[HAND];
  int change[HAND] = {0};
  int current_deck = 0;
  int i;
  char ch;

  init(cards);
  shuffle(cards, TRAMP);

  /*for(i = 0;i < TRAMP;i++){
    print_card(cards[i]);
    printf("\n");
  }*/ //debug

  deal(cards, hands, &current_deck);

    system("clear");
    for(i = 0;i < HAND;i++){
      print_card(hands[i]);
      printf(",");
    }
  do{
    printf("\033[1;1H");
    printf("\n");
    for(i = 0;i < HAND;i++){
      if(change[i] == 1){
        printf(" HOLD! ");
      }
      else{
        printf("       ");
      }
    }
    printf("\n");

    ch = getChar();
    switch(ch){
      case 'r':
        change[0] = (change[0] + 1) % 2;
      break;
      case 't':
        change[1] = (change[1] + 1) % 2;
      break;
      case 'y':
        change[2] = (change[2] + 1) % 2;
      break;
      case 'u':
        change[3] = (change[3] + 1) % 2;
      break;
      case 'i':
        change[4] = (change[4] + 1) % 2;
      break;
    }
  }while(ch != '\n');

  exchange(cards, hands, &current_deck, change);

  for(i = 0;i < HAND;i++){
    print_card(hands[i]);
    printf(",");
  }
  printf("\n");

  check(hands);

  return 0;
}
