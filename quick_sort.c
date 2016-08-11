/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdio.h>
#include "util.h"

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

/*
int main(){
    int array[] = {1,9,19,2,3,4,8};    
    printf("test for quickSort\n");
    quickSort(array, 0, 6);
    for( int i = 0; i < 7; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
*/