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
            while(nums[i] >= nums[flag] && i <= high){
                i++;
            }
            while(nums[j] < nums[flag] && j >= low){
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

int thirdMax(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return -1;
  }
  int *top = malloc(3 * sizeof(int));
  top[0] = nums[0];
  int count = 1;
  for(int i = 1; i < numsSize; i++){

    if(count == 1 && nums[i] != top[0]){
      top[1] = nums[i];
      count++;
    } else if(count == 2 && nums[i] != top[0] && nums[i] != top[1]){
      top[2] = nums[i];
      count++;
      quickSort(top, 0, 2);
    } else if(count == 3){
      if(nums[i] > top[0]){
        top[2] = top[1];
        top[1] = top[0];
        top[0] = nums[i];
      } else if(nums[i] > top[1] && nums[i] != top[0]){
        top[2] = top[1];
        top[1] = nums[i];
      } else if(nums[i] > top[2] && nums[i] != top[1] && nums[i] != top[0]){
        top[2] = nums[i];
      }
    }
  }

  if(count == 1){
    return top[0];
  } else if(count == 2){
    return top[0] > top[1] ? top[0] : top[1];
  } else {
    return top[2];
  }
}

int main(){
  int a[] = {3,2};
  printf("%d\n", thirdMax(a, 2));
}
