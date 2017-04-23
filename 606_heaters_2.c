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

int binarySearch(int *heaters, int heatersSize, int house){
  int low = 0;
  int high = heatersSize - 1;
  int mid = (low + high) / 2;

  do{
    printf("%d, %d, %d\n", );
    if(heaters[mid] == house){
      return 0;
    }
    if(heaters[mid] < house){
      if(mid != heatersSize - 1 && heaters[mid + 1] > house){
        return MIN(house - heaters[mid], heaters[mid + 1] - house);
      } else if(mid == heatersSize - 1){
        return house - heaters[mid];
      } else{
        mid = (mid + 1) / 2 + high / 2 + ((mid + 1) % 2 + high % 2) / 2;
      }
    } else if(heaters[mid] > house){
      if(mid == 0){
        return heaters[mid] - house;
      } else {
        mid = mid / 2 + (low - 1) / 2 + (mid % 2 + (low - 1) % 2) / 2;
      }
    }
  } while(true);
  return -1;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
  if(houses == NULL || heaters == NULL){
    return 0;
  }
  int max = 0;
  quickSort(houses, 0, housesSize - 1);
  quickSort(heaters, 0, heatersSize - 1);
  for(int i = 0; i < housesSize; i++){
    int tmp = binarySearch(heaters, heatersSize, houses[i]);
    max = MAX(max, tmp);
  }
  return max;
}
