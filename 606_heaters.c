/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX(x,y) (x) > (y) ? (x) : (y)
#define MIN(x,y) (x) < (y) ? (x) : (y)

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

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
  if(houses == NULL || heaters == NULL){
    return 0;
  }
  int max = 0;
  quickSort(houses, 0, housesSize - 1);
  quickSort(heaters, 0, heatersSize - 1);
  for(int i = 0; i < housesSize; i++){
    int tmp = 0;
    for(int j = 0; j < heatersSize; j++){
      if(heaters[j] == houses[i]) {
        break;
      }
      if(heaters[j] < houses[i]){
        if(j == heatersSize - 1){
          tmp = houses[i] - heaters[j];
          max = MAX(tmp, max);
        } else if(heaters[j + 1] >= houses[i]){
          max = MAX(MIN(heaters[j + 1] - houses[i],  houses[i] - heaters[j]), max);
          break;
        }
      } else {
        tmp = heaters[j] - houses[i];
        max = MAX(tmp, max);
        break;
      }
    }    printf("%d, %d\n", i, max);

  }
  return max;
}
