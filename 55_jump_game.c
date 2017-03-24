/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool canJump(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return false;
  }
  if(numsSize == 1) return true;
  int max = 0;
  for(int i = 0; i <= max; i++){
    if(nums[i] + i > max){
      if(nums[i] + i >= numsSize - 1){
        return true;
      } else {
        max = nums[i] + i;
      }
    }
  }
  return false;
}
