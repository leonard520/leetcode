/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define N 268435455

int bitmap[N];
int bitmap_neg[N];

bool containsDuplicate(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return false;
  }
  memset(bitmap, 0, N);
  memset(bitmap_neg, 0, N);
  int a = 0;
  int b = 0;
  for(int i = 0; i < numsSize; i++){
    if(nums[i] >= 0){
      a = nums[i] % 32;
      b = nums[i] / 32;
      if((bitmap[b] & (1 << a)) != 0){
        return true;
      }
      bitmap[b] |= (1 << a);
    } else {
      a = -nums[i] % 32;
      b = -nums[i] / 32;
      if((bitmap_neg[b] & (1 << a)) != 0){
        return true;
      }
      bitmap_neg[b] |= (1 << a);
    }
  }
  return false;
}

int main(){
  int a[] = {-1200000005,-1200000005};
  printf("%d", containsDuplicate(a, 2));
  return 0;
}
