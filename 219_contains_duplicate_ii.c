/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int* nums, int low, int high) {
    int flag, i, j;
    if(low < high){
        flag = low;
        i = low;
        j = high;
        while(i < j){
            while(nums[i] <= nums[flag] && i <= high){
                i++;
            }
            while(nums[j] > nums[flag] && j >= low){
                j--;
            }
            if(i < j){
                swap(&nums[i], &nums[j]);
            }
        }
        swap(&nums[j], &nums[flag]);
        quickSort(nums, low, j - 1);
        quickSort(nums, j + 1, high);
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  if(nums == NULL || numsSize == 0){
    return false;
  }
  quickSort(nums, 0, numsSize - 1);
  int i, j;
  i = j = 0;
  while(i < numsSize){
    int v = nums[j] - nums[i];
    if( v == k){
      return true;
    } else if(v < k){
      j++;
    } else {
      i++;
    }
    if(j == numsSize){
      return false;
    }
  }
  return false;
}
