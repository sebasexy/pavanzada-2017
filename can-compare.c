#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "can-compare.h"


/*************************************
* canCompare
* Given two strings (a, b), check if b can create a with its characters
* returns 1 if it's true and 0 if it's false (can create or not)
* @param:
*   a: string one
*   b: string two
* @return:
*   integer 1 || 0
*
*/
int canCompare(char* a, char* b){
  // Initialize Variables
  int i;
  int j;
  int creates=0;
  int lenA = strlen(a);
  int lenB = strlen(b);
  char stringA[lenA];
  char stringB[lenB];

  /* Changes char* a to a char[]
  * to be able to modify characters
  */
  for(i = 0; i < lenA; i++){
    stringA[i] = a[i];
  }
  for(i = 0; i < lenB; i++){
    stringB[i] = b[i];
  }

  /*
  * Compares each letter of b with each letter of a
  * and if it's contained in a, change the characters with an
  * empty space
  */
  for(i = 0; i < lenB; i++){
    for(j = 0; j < lenA; j++){
      if(stringB[i] == stringA[j]){
        stringB[i] = ' ';
        stringA[j] = ' ';
      }
    }
  }

  /*
  * If every single character of "a" is now empty,
  * returns 1 = true
  * else returns 0 = false and breaks the loop
  */
  for(i = 0; i < lenA; i++){
    if(stringA[i] == ' '){
      creates = 1;
    }else{
      creates = 0;
      break;
    }
  }

  return creates;
}
