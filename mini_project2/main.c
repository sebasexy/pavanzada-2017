#include <stdlib.h>
#include <stdio.h>
#include "sum-two-integers.h"

/* @param
* int x, int y
* sumTwoIntegers
*   Given x and y, it returns the sum
*   of x and y, wtihout using the operators + or -
* @return
*   int
*   Returns the sum of x and y
* References:
*   For the FULL-ADDER Logic -> https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Comb/adder.html
*   For the BITWISE Operators -> https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
**/
int sumTwoIntegers(int x, int y){
  if(x == 0){
    return y;
  }
  else{
    int carry = x&y;
    int sum = x^y;
    return sumTwoIntegers(carry << 1, sum);
  }
}

int main(int argc, char **argv) {
  int x;
  int y;
  int result;
  printf("Give me the first int: ");
  scanf("%d", &x);
  printf("Give me the second int: ");
  scanf("%d", &y);

  result = sumTwoIntegers(x,y);

  printf("The sum of %d and %d is: %d\n", x, y, result);
  return 0;
}
