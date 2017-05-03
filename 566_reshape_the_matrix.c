/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
  if(nums == NULL) return NULL;
  if(numsRowSize * numsColSize != r * c) {
    *returnSize = numsRowSize;
    *columnSizes = malloc(numsRowSize * sizeof(int));
    for(int i = 0; i < numsRowSize; i++){
      (*columnSizes)[i] = numsColSize;
    }
     return nums;
   }
  int **result = malloc(r * sizeof(int *));
  *returnSize = r;
  *columnSizes = malloc(r * sizeof(int));
  for(int i = 0; i < r; i++){
    (*columnSizes)[i] = c;
  }

  int m, n;
  m = n = 0;
  for(int i = 0; i < r; i++){
    result[i] = malloc(c * sizeof(int));
    for(int j = 0; j < c; j++){
      if(n == numsColSize){
        n = 0;
        m++;
      }
      result[i][j] = nums[m][n];
      n++;
    }
  }
  return result;
}
