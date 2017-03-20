/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int singleNonDuplicate(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int mid = (numsSize - 1) / 2;
  int start = 0;
  int end = numsSize - 1;
  while(start < end){
    mid = (start + end) / 2;
    if(mid % 2 == 1){
      printf("1 %d %d %d\n", start, end, mid);
      if(nums[mid] == nums[mid + 1]){
        end = mid - 1;
      } else if(nums[mid] == nums[mid - 1]){
        start = mid + 1;
      }
    } else {
      printf("2 %d %d %d\n", start, end, mid);
      if(nums[mid] == nums[mid - 1]){
        end = mid - 2;
      } else if(nums[mid] == nums[mid + 1]){
        start = mid + 2;
      } else {
        return nums[mid];
      }
    }
  }
  return nums[start];
}

int main(){
  int nums[] = {1, 1, 2, 3, 3};
  singleNonDuplicate(nums, 5);
}
