#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word-len.h"

int getWordLen(char* str){
  int i;
  int count = 0;
  for(i = strlen(str)-1; i >= 0; i--){
    if(str[i] != ' '){
      count++;
    }else{
      break;
    }
  }
  return count;
}
