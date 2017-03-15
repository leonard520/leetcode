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

bool dfs(int *nums, int numsSize, int end, int target){
  if(target == 0){
    return true;
  }
  bool flag = false;
  for(int i = end; i >= 0; i--){
    int temp = nums[i];
    if(temp != 0){
      nums[i] = 0;
      flag |= dfs(nums, numsSize, end - 1, target - temp);
      if(flag == true) return true;
    }
    nums[i] = temp;
    flag |= dfs(nums, numsSize, end - 1, target);
    if(flag == true) return true;
  }
  return flag;
}

bool makesquare(int* nums, int numsSize) {
  if(numsSize < 4 || nums == NULL){
    return false;
  }
  int sum = 0;
  for(int i = 0; i < numsSize; i++){
    sum += nums[i];
  }
  if(sum % 4 != 0){
    return false;
  }

  quickSort(nums, 0, numsSize - 1);
  bool flag = true;
  flag &= dfs(nums, numsSize, numsSize - 1, sum / 4);
  flag &= dfs(nums, numsSize, numsSize - 1, sum / 4);
  flag &= dfs(nums, numsSize, numsSize - 1, sum / 4);
  flag &= dfs(nums, numsSize, numsSize - 1, sum / 4);
  return flag;
}
