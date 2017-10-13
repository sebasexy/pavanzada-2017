#include <stdio.h>
#include "minunit.h"
#include "island-perimeter.h"

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

/*
printf("%d", myArray[0]);
printf("%d", myArray[1]);
printf("%d", myArray[2]);
printf("%d", myArray[3]);
int * row = &myArray[0];

printf("%d", row[0]);
printf("%d", row[1]);
printf("%d", row[2]);
printf("%d", row[3]);
*/

//  printf("%d", myArray[1]);

static char * testUnit() {
  int ** array;
  int i;
  int j;
  int columns = 4;
  int rows = 4;
  int expected = 16;

  array = (int**) calloc(rows, sizeof(int*));
  for(i = 0; i < rows; i++){
  	array[i] = (int*)calloc(columns, sizeof(int));
  }

  array[0][0] = 0;
  array[0][1] = 1;
  array[0][2] = 0;
  array[0][3] = 0;

  array[1][0] = 1;
  array[1][1] = 1;
  array[1][2] = 1;
  array[1][3] = 0;

  array[2][0] = 0;
  array[2][1] = 1;
  array[2][2] = 0;
  array[2][3] = 0;

  array[3][0] = 1;
  array[3][1] = 1;
  array[3][2] = 0;
  array[3][3] = 0;

  int result = islandPerimeter(array, rows, columns);
  muAssert("Error, perimeter is wrong", expected == result);
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
