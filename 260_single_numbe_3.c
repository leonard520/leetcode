/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
  if(nums == NULL || numsSize == 0){
    return NULL;
  }
  int c = 0;
  for(int i = 0; i < numsSize; i++){
    c ^= nums[i];
  }
  c &= -c;
  *returnSize = 2;
  int *result = malloc(sizeof(int) * 2);
  result[0] = result[1] = 0;
  for(int i = 0; i < numsSize; i++){
    if((nums[i] & c) == 0){
      result[0] ^= nums[i];
    } else {
      result[1] ^= nums[i];
    }
  }
  return result;
}

int main(){
  int nums[] = {1, 2, 1, 3, 2, 5};
  int *returnSize = malloc(sizeof(int));
  singleNumber(nums, 6, returnSize);
}
