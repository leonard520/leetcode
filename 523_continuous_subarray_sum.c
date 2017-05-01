/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
  if(numsSize == 1) return false;
  k = abs(k);
  if(k == 0) return false;
  int flag[k];
  memset(flag, -1, sizeof(int) * k);

  int sum = 0;
  for(int i = 0; i < numsSize; i++){
    sum += nums[i];
    sum %= k;
    if(i != 0 && sum % k == 0){
      return true;
    }
    if(flag[sum] == -1) {
      flag[sum] = i;
    } else {
      if(i - flag[sum] > 1){
        return true;
      }
    }
  }
  return false;
}
