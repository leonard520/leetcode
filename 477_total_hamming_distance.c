/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int totalHammingDistance(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int zero, one;
  int n = 0;
  int result = 0;
  for(int i = 0; i < 32; i++){
    zero = one = 0;
    for(int j = 0; j < numsSize; j++){
      if((nums[j] & (1 << n)) == 0){
        zero++;
      } else {
        one++;
      }
    }
    n++;
    result += zero * one;
  }
  return result;
}
