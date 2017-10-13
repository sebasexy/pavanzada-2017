#include <stdlib.h>
#include <stdio.h>
#include "island-perimeter.h"

int islandPerimeter(int** array, int rows, int columns){
  int perimeter = 0;
  short neighbors;
  int *row;
  int i;
  int j;

  for(i = 0; i < rows; i++){
    for(j = 0; j < columns; j++){
      neighbors = 0;
      if(array[i][j] == 1){
        if((i-1) >= 0 && array[i-1][j] == 1){
          neighbors++;
        }
        if(i+1 < columns && array[i+1][j] == 1){
          neighbors++;
        }
        if(j-1 >= 0 && array[i][j-1] == 1){
          neighbors++;
        }
        if(j+1 < columns && array[i][j+1] == 1){
          neighbors++;
        }
        perimeter += (4 - neighbors);
      }
    }
  }

  return perimeter;
}
