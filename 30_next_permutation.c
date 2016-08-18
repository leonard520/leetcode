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

void nextPermutation(int* nums, int numsSize) {
    if(nums == NULL){
        return;
    }
    int i = numsSize - 1;
    for(i = numsSize - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1])
            break;
    }
    if(i == -1){
        quickSort(nums, 0, numsSize - 1);
    } else {
        int point = nums[i];
        for(int j = numsSize - 1; j > i; j--){
            if(nums[j] > point){
                swap(&nums[j], &nums[i]);
                break;
            }
        }
        quickSort(nums, i + 1, numsSize - 1);
        
    }
    return;
}

int main(){
    int nums[] = {3, 2, 1};
    nextPermutation(nums, 3);
    for(int i = 0; i < 3; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}