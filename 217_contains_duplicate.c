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

bool containsDuplicate(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i + 1])
            return true;
    }
    return false;
}