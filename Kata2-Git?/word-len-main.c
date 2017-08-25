#include <stdio.h>
#include "word-len.h"

int main(){
  char* palabraDelSenor = "Surprise MoFo Watchu Doin Ma Brother from another Mother in the hoodie";
  int res = getWordLen(palabraDelSenor);
  printf("And the length of the word is... = %d \n", res);
  //printf("Length of string b = %d \n",strlen(b));
  return 0;
}
