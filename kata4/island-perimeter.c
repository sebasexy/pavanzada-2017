#include <stdlib.h>
#include <stdio.h>
#include "island-perimeter.h"

/* islandPerimeter
* From a matrix of integers, 0 - represents water, 1 - represents land
* it calculates the perimeter of the island.
* cells are connected horizontally/vertically (not diagonally)
* @params:
*     array - the matrix of integers
*     rows - how many rows the matrix has
      columns - how many columns the matrix has
* @ return:
*   int - what is the perimeter of the island
*
*/
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
        if(i+1 < rows && array[i+1][j] == 1){
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
