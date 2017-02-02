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
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  if(nums == NULL || numsSize == 0){
    return NULL;
  }
  int *result = malloc(numsSize * sizeof(int));
  *returnSize = 0;
  int i = 0;
  for(i = 0; i < numsSize; i++){
    int index = abs(nums[i]) - 1;
    nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
  }
  for(i = 0; i < numsSize; i++){
    if(nums[i] > 0){
      result[*returnSize] = i + 1;
      (*returnSize)++;
    }
  }
  return result;
}

int main(){
  int a[] = {4,3,2,7,8,2,3,1};
  int *p;
  findDuplicates(a, 8, p);
}
