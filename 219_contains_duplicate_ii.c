/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  if(nums == NULL || numsSize == 0){
    return false;
  }
  for(int i = 0; i < numsSize; i++){
    for(int j = 1; j <= k; j++){
      if(i + j < numsSize){
        if(nums[i] == nums[i + j]){
          return true;
        }
      }
    }
  }
  return false;
}
