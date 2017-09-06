#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "add-digits.h"

/* addDigits
* Receives a positive integer number and returns the sum of the digits
* (it sums all the digits until the last sum is a single digit)
* @param
* unsigned int
* @return
* int, using the formula retreived from:
* https://en.wikipedia.org/wiki/Digital_root
*/
int addDigits(unsigned int number){
  return 1 + ((number-1)%9);
}
