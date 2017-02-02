/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// void moveZeroes(int* nums, int numsSize) {
//   if(nums == NULL || numsSize == 0){
//     return;
//   }
//   int i = 0, j = numsSize - 1;
//   while(nums[j] == 0) j--;
//   while(i < j && i < numsSize && j >= 0){
//     if(nums[i] != 0 && i < numsSize) i++;
//     if(nums[j] == 0 && j >= 0) j--;
//     if(i < j && i < numsSize && j >= 0){
//       swap(&nums[i], &nums[j]);
//       i++;
//       j--;
//     }
//   }
// }

void moveZeroes(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return;
  }
  int j = 0;
  while(j < numsSize && nums[j] == 0) j++;
  if(numsSize == j){
    return;
  }
  for(int i = 0; i < numsSize; i++){
    if(nums[i] == 0){
      if(j < i) j = i + 1;
      while (j < numsSize && nums[j] == 0) {
        j++;
      }
      if(j < numsSize){
        swap(&nums[i], &nums[j]);
      }
    }
    if(j == numsSize){
      break;
    }
  }
}

int main(){
  int a[] = {1,1,0,0,1};
  moveZeroes(a, 5);
  for(int i = 0; i < 5; i++) {
    printf("%d\n", a[i]);
  }
}
