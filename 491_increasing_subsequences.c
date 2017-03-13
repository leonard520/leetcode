/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 64
void dfs(int *nums, int numsSize, int p, int l, int* returnSize, int **columnSizes, int **result, int *current){
  if(p == numsSize){
    for(int i = 0; i < l; i++){
      result[*returnSize][i] = current[i];
    }
    (*columnSizes)[*returnSize] = l;
    (*returnSize)++;
    return;
  }
  for(int i = p; i < numsSize; i++){
    if(l == 0 || result[*returnSize][l - 1] < nums[p]){
      current[l] = nums[p];
      l++;
      dfs(nums, numsSize, i + 1, l, returnSize, columnSizes, result, current);
      l--;
    }
    dfs(nums, numsSize, i + 1, l, returnSize, columnSizes, result, current);
  }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int** columnSizes, int* returnSize) {
  int **result = malloc(sizeof(int *) * MAX);
  *columnSizes = malloc(sizeof(int) * MAX);
  for(int i = 0; i < MAX; i++){
    result[i] = malloc(sizeof(int) * 15);
    (*columnSizes)[i] = 0;
  }
  *returnSize = 0;
  int *current = malloc(sizeof(int) * 15);
  dfs(nums, numsSize, 0, 0, returnSize, columnSizes, result, current);
  return result;
}

int main() {
  //int nums[] = {4, 6, 7, 7};
  int nums[] = {1, 2, 3};
  int numsSize = 3;
  int **columnSizes = malloc(sizeof(int *) * MAX);
  int *returnSize = malloc(sizeof(int));
  findSubsequences(nums, numsSize, columnSizes, returnSize);
  return 0;
}
