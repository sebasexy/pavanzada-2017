#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "texto.h"

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  FILE *myFile;
  assert(argc==2);
  myFile = fopen(argv[1], "r");
  assert(myFile != NULL);
  int temperature;
  double average;
  int count = 0;

  while(!feof(myFile)){
    fscanf(myFile, "temp %d\n", &temperature);
    printf("temp = %d \n", temperature);
    if(feof(myFile)){
      break;
    }
    if(count == 0){
      average = temperature;
      count = 1;
    }else{
      average = average * count + temperature;
      count++;
      average = average / count;
    }
  }
  fclose(myFile);
  printf("The average is = %lf \n", average);
  return 0;
}

/*  FILE *myFile;
  assert(argc==2);
  myFile = fopen(argv[1], "r");
  assert(myFile != NULL);
  int c;
  while((c = fgetc(myFile)) != EOF){
    putchar(toupper(c));
  }
  fclose(myFile);
  return 0;
  */
