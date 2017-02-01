/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int missingNumber(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int n = 0;
  for(int i = 0; i < numsSize + 1; i++){
    n ^= i;
  }
  for(int i = 0; i < numsSize; i++){
    n ^= nums[i];
  }
  return n;
}
