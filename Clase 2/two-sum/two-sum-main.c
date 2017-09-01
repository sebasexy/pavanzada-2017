#include <stdio.h>
#include "two-sum.h"

int main(){
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int len = 4;
  int *result = getIndices(nums, len, target);
  //printf("Hello pipol");
  if(result != NULL && (nums[result[0]] + nums[result[1]] == target)){
    printf("Funciono\n");
  }else{
    printf("No funciono\n");
  }
  return 0;
}
