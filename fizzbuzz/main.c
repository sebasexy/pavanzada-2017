#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "kata5.h"
#define MAX_LENGTH 100

/* Add function signatures here */
/**
 * fizzBuzz
 * given an integer "n":
 * it returns an array of size n with the digits from 1 - n
 * but if n is multiple of 3, it saves Fizz
 * if n is multiple of 5, it saves Buzz
 * if n is multiple of both 3 and 5, it saves FizzBuzz
 * @params
 * n - from 1 to n, the number you want to try out
 * returnSize - the size of the char ** that will be returned
 * Return
 * char ** the list from 1 - n with Fizz | Buzz | FizzBuzz modifiers
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** fizzBuzz(int n, int* returnSize){
  char ** fBArray;
  *returnSize = n;
  fBArray = malloc(sizeof(char*)*n);
  int i;
  char str[n];
  for(i = 1; i <= n; i++){
    if(i%3 == 0 && i%5 == 0){
      fBArray[i-1] = strdup("FizzBuzz");
      continue;
    }
    if(i%3==0){
      fBArray[i-1] = strdup("Fizz");
      continue;
    }
    if(i%5==0){
      fBArray[i-1] = strdup("Buzz");
      continue;
    }
    else{
      sprintf(str, "%d", i);
      fBArray[i-1] = strdup(str);
    }
  }
  return fBArray;
}


int main(int argc, char **argv) {
  int returnSize;
  int *n;
  n = malloc(sizeof(int)*MAX_LENGTH);
  int i;
  printf("Type number: ");
  scanf("%d", n);
  char** result = fizzBuzz(*n, &returnSize);

  for(i = 0; i < returnSize; i++){
    printf("%s\n", result[i]);
  }
  return 0;
}
