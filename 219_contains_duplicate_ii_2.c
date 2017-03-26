/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define N 70000

int bitmap[N];

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  if(nums == NULL || numsSize == 0){
    return false;
  }
  memset(bitmap, 0, sizeof(N));
  for(int i = 0; i < numsSize; i++){
    if(bitmap[nums[i] + 35000] != 0){
      bitmap[nums[i] + 35000] = i;
    } else {
      if(i - bitmap[nums[i] + 35000] <= k){
        return true;
      }
    }
  }
  return false;
}
