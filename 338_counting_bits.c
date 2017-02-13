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
int* countBits(int num, int* returnSize) {
  *returnSize = num + 1;
  if(num < 0){
    return NULL;
  }
  int offset = 1;
  int *result = malloc(sizeof(int) * num + 1);
  result[0] = 0;
  for(int i = 1; i <= num; i++){
    if(offset * 2 == i){
      offset *= 2;
    }
    result[i] = result[i - offset] + 1;
  }
  return result;
}
