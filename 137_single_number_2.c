/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int singleNumber(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int result = 0;
  int *c = malloc(sizeof(int) * 32);
  memset(c, 0, sizeof(int) * 32);
  for(int i = 0; i < 32; i++){
    for(int j = 0; j < numsSize; j++){
      c[i] += ((nums[j] & (1 << i))) >> i;
    }
  }
  for(int i = 0; i < 32; i++){
    c[i] %= 3;
    result += c[i] * (1 << i);
  }
  return result;
}
