#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "keyboard.h"

char** keyboardRoom(char** words, int wordsSize){
  int i;
  int j;
  int k;
  int wordLen;

  char *a = "qwertyuiop";
  char *b = "asdfghjkl";
  char *c = "zxcvbnm";

  int aCount = 0;
  int bCount = 0;
  int cCount = 0;
  int count = 0;
  char **res;
  char *word;

  res = malloc(sizeof(char *) *sizeof(words));

  for(i = 0; i < wordsSize; i++){
    word = words[i];
    wordLen = strlen(word);
    aCount = 0;
    bCount = 0;
    cCount = 0;
    for(j = 0; j < wordLen; j++){
      for(k = 0; k < strlen(a); k++){
        if(word[j] == a[k]){
          aCount++;
        }
      }
      for(k = 0; k < strlen(b); k++){
        if(word[j] == b[k]){
          bCount++;
        }
      }
      for(k = 0; k < strlen(c); k++){
        if(word[j] == c[k]){
          cCount++;
        }
      }
    }
    if(aCount == wordLen || bCount == wordLen || cCount == wordLen){
      res[count++] = strdup(word);
      printf("It should save %s\n", word);
    }
  }
  for(i = 0; i < count; i++){
    printf("Res in pos %i is %s\n", i, res[i]);
  }
  return res;
  /*
  for(i = 0; i < sizeof(words); i++){
    word = words[i];
    for(j = 0; j < strlen(word); j++){
      for(k = 0; k < sizeof(a); k++){
        if(word[j] == a[k]){
          aCount++;
        }
      }
      for(k = 0; k < sizeof(b); k++){
        if(word[j] == b[k]){
          bCount++;
        }
      }
      for(k = 0; k < sizeof(c); k++){
        if(word[j] == c[k]){
          cCount++;
        }
      }
    }
    if(aCount == strlen(word) || bCount == strlen(word) || cCount == strlen(word)){
      res[count++] = strdup(word);
    }
    aCount = 0;
    bCount = 0;
    cCount = 0;
  }
  */

}
