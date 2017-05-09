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

int distributeCandies(int* candies, int candiesSize) {
  if(candies == NULL || candiesSize == 0){
    return 0;
  }
  quickSort(candies, 0, candiesSize - 1);
  int summary = 1;
  int prev = candies[0];
  for(int i = 1; i < candiesSize; i++){
    if(prev != candies[i]){
      prev = candies[i];
      summary++;
    }
  }
  return summary > candiesSize / 2 ? candiesSize / 2 : summary;
}
