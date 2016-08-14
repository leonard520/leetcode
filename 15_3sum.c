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

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, j, k;
    int **result = malloc(sizeof(int) * 1024);
    *returnSize = 0;
    int sum = 0;
    int count = 0;
    i = 0; j = i + 1; k = numsSize - 1;
    quickSort(nums, 0, numsSize - 1);
    while( i < numsSize - 2 && i < j && j < k){
        sum = nums[i] + nums[j] + nums[k];
        if(sum == 0){
            int *array = malloc(sizeof(int) * 3);
            array[0] = nums[i];
            array[1] = nums[j];
            array[2] = nums[k];

            result[count++] = array;
            do{
                j++;
            } while(j < k && nums[j] == nums[j - 1]);
            do {
                k--;
            } while(k > j && nums[k] == nums[k + 1]);
            
            
        } else if(sum < 0){
            if(j + 1 < k) {
                do{
                    j++;
                } while(j < k && nums[j] == nums[j - 1]);
                
            } else {
                do {
                   i++;
                } while(i < numsSize - 2 && nums[i] == nums[i - 1]);
                j = i + 1;
                k = numsSize - 1;
            }
        } else if(sum > 0){
            if(k - 1 > j){
                do {
                    k--;
                } while(k > j && nums[k] == nums[k + 1]);
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
    *returnSize = count;
    return result;
}

int main(){
    int array[] = {0,0,0}; 
    int *returnSize = malloc(sizeof(int));
    int **result = threeSum(array, 6, returnSize);
    printf("%d\n", *returnSize);
    
    return 0;
}