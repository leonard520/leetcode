/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647

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

int findPairs(int* nums, int numsSize, int k) {
  if(nums == NULL || numsSize == 0) return 0;
  quickSort(nums, 0, numsSize - 1);
  int count = 0;
  int x, y;
  x = y = INT_MAX;
  for(int i = 0; i < numsSize - 1; i++){
    for(int j = i + 1; j < numsSize; j++){
      if((nums[i] != x && nums[j] != y) && (nums[j] - nums[i] == k)){
        x = nums[i];
        y = nums[j];
        count++;
        break;
      }
    }
  }
  return count;
}
