/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void findTargetSumWaysInternal(int *nums, int numsSize, int start, int target, int sum, int *count){
  if(start == numsSize && target == sum){
    (*count)++;
    return;
  } else if(start == numsSize){
    return;
  }
  findTargetSumWaysInternal(nums, numsSize, start + 1, target, sum + nums[start], count);
  findTargetSumWaysInternal(nums, numsSize, start + 1, target, sum, count);
}

int findTargetSumWays(int* nums, int numsSize, int S) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int sum = 0;
  for(int i = 0; i < numsSize; i++){
    sum += nums[i];
  }
  if((sum - S) % 2 == 1 || (sum - S < 0)){
    return 0;
  }
  int target = (sum - S) /2;
  int *count = malloc(sizeof(int));
  *count = 0;
  findTargetSumWaysInternal(nums, numsSize, 0, target, 0, count);
  return *count;
}
