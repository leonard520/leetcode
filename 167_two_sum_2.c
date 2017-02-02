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
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  if(numbers == NULL){
    return NULL;
  }
  *returnSize = 2;
  int *result = malloc(2 * sizeof(int));
  int start = 0, end = numbersSize - 1;
  while(start < end){
    if(numbers[start] + numbers[end] == target){
      result[0] = start + 1;
      result[1] = end + 1;
      return result;
    } else if(numbers[start] + numbers[end] > target){
      end--;
    } else {
      start++;
    }
  }
  return result;
}
