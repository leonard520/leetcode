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

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k;
    int min = INT_MAX;
    int result;
    int diff = 0;
    int count = 0;
    int sum;
    i = 0; j = i + 1; k = numsSize - 1;
    quickSort(nums, 0, numsSize - 1);
    while( i < numsSize - 2 && i < j && j < k){
        sum = nums[i] + nums[j] + nums[k];
        bool bigger = false;
        if(sum - target > 0){
            bigger = true;
            diff = sum - target;
        } else if(sum - target < 0){
            bigger = false;
            diff = target - sum;
        } else {
            return target;   
        }
        if(min > diff){
            min = diff;
            result = sum;
        }

        if(bigger == false){
            if(j + 1 < k) {
                do{
                    j++;
                } while(j + 1 < k && nums[j] == nums[j - 1]);
                
            } else {
                do {
                   i++;
                } while(i < numsSize - 2 && nums[i] == nums[i - 1]);
                j = i + 1;
                k = numsSize - 1;
            }
        } else if(bigger == true){
            if(k - 1 > j){
                do {
                    k--;
                } while(k - 1 > j && nums[k] == nums[k + 1]);
            } else {
                do {
                  i++;
                } while(i < numsSize - 2 && nums[i] == nums[i - 1]);
                j = i + 1;
                k = numsSize - 1;
            }
        }
        if(j > k - 1){
            do {
                  i++;
                } while(i < numsSize - 2 && nums[i] == nums[i - 1]);
            j = i + 1;
            k = numsSize - 1;
        } 
    }
    return result;
}

int main(){
    int array[] = {0,1,2}; 
    int result = threeSumClosest(array, 3, 0);
    printf("%d\n", result);
    
    return 0;
}