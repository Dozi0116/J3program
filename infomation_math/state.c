#include <stdio.h>

#define CHARACTERS 200
#define WORDS 10
#define WORD_CHARACTERS 20

void buffer_to_array(char buffer[CHARACTERS], char note[WORDS][WORD_CHARACTERS]);

int main(void)
{
  char buffer[CHARACTERS] = "My name is Dozi!";
  char note[WORDS][WORD_CHARACTERS];

  printf("%s\n", buffer);
  buffer_to_array(buffer, note);
  return 0;
}

void buffer_to_array(char buffer[CHARACTERS], char note[WORDS][WORD_CHARACTERS])
{
  int i, j = 0, k = 0;
  for(i = 0;buffer[i] != '\0';){
    note[j][k] = buffer[i];
    //printf("note[%d][%d] = %c\n", j, k, note[j][k]);
    i++;
    k++;
    if(buffer[i] == ' '){
      note[j][k] = '\0';
      j++;
      k = 0;
      i++;
    }
  }
  note[j][k] = '\0';
  note[j+1][0] = '\0';

  for(j = 0;note[j][0] != '\0';j++){
    printf("%s\n", note[j]);
  }
}
