#include <stdlib.h>
#include <stdio.h>
#include "operations.h"
#define MAX_LENGTH 10
#define printDebug(msg) do { char *value = getenv("OPER_DEBUG"); if (!strcmp(value, "t")) printf("%s", msg); } while (0)

/* Add function signatures here */
int suma(int a, int b){
  return a + b;
}
int resta(int a, int b){
  return a - b;
}

int main(int argc, char **argv) {
  /* Start your code here */
  char *operationName;
  char message[200];
  int operator1, operator2;
  int(*operation)(int, int);
  operationName = malloc(sizeof(char)*MAX_LENGTH);

  printf("Cual es la operacion\n");
  scanf("%s", operationName);
  scanf("%d", &operator1);
  scanf("%d", &operator2);
  sprintf(message, "operationName = %s\n", operationName);
  printDebug(message);
  sprintf(message, "operator1 = %d\n", operator1);
  printDebug(message);
  sprintf(message, "operator2 = %d\n", operator2);
  printDebug(message);

  if(!strcmp(operationName, "suma")){
    operation = suma;
  }
  if(!strcmp(operationName, "resta")){
    operation = resta;
  }
  printf("%d\n", operation(operator1, operator2));
  return 0;
}
