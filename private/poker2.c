#include <stdio.h>
#include <stdlib.h>
#include <termio.h>

#define CARD 53

typedef struct card {
  int surt; //(dia, clab, heart, spade) = (0, 1, 2, 3)
  int number; //Joker is 0
} card;

void init(card cards[])
{
  //set surt and number
  int i;
  for(i = 0;i < CARD - 1;i++){
    cards[i].surt = i / 13;
    cards[i].number = i % 13 + 1;
  }
  cards[i].surt = 4;
  cards[i].number = 0;
}

int main(void){
  card cards[CARD];
  init(cards);

  return 0;
}
