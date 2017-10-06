#include <stdio.h>
#include "minunit.h"
#include "keyboard.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testUnit() {
  char* words[] = {"kaka","tete","alaska", "dad", "test"};
  int num_words = 5;

  //char* expected[] = {"alaska", "dad"};
  char* expected[] = {"kaka", "tete", "alaska", "dad"};
  char** result = keyboardRoom(words, num_words);
  int areEqual = 1;
  int boolResult = compareResult(expected, result, 4);
  muAssert("It should return true", areEqual == boolResult);
  return 0;
}

int compareResult(char ** expected, char** result, int num_words_expected){
  int i;
  int count = 0;
  for(i = 0; i < num_words_expected; i++){
    if(*expected[i] == *result[i]){
      count++;
    }
  }
  if(count == num_words_expected){
    return 1;
  }
  return 0;
}

static char * allTests() {
  muRunTest(testUnit);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
