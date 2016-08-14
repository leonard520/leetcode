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
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, k, l;
    int **result = malloc(sizeof(int) * 1024);
    *returnSize = 0;
    int diff = 0, sum = 0;
    int count = 0;
    i = 0; j = i + 1; k = i + 2; l = numsSize - 1;
    quickSort(nums, 0, numsSize - 1);

    while( i < numsSize - 3 && i < j && j < k && k < l){
        //printf("%d,%d,%d,%d\n", i, j, k, l);
        if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        sum = nums[i] + nums[j] + nums[k] + nums[l];
        diff = sum - target;
        if(diff == 0){
            int *array = malloc(sizeof(int) * 4);
            array[0] = nums[i];
            array[1] = nums[j];
            array[2] = nums[k];
            array[3] = nums[l];

            result[count++] = array;

            do{
                k++;
            } while(k < l && nums[k] == nums[k - 1]);
            do {
                l--;
            } while(l > k && nums[l] == nums[l + 1]);

        } else if(diff < 0){
            if(k + 1 < l) {
                do{
                    k++;
                } while(k < l && nums[k] == nums[k - 1]);
                
            } else {
                do {
                    j++;
                } while((j < numsSize - 2 && nums[j] == nums[j - 1]) || nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2] < target);
                
                if(j >= numsSize - 2){
                    do {
                        i++;
                    } while((i < numsSize - 3 && nums[i] == nums[i - 1]) || nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target || nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target);
                    j = i + 1;
                    k = j + 1;
                    l = numsSize - 1;
                } else {
                    k = j + 1;
                    l = numsSize - 1;
                }
            }
        } else if(diff > 0){
            if(l - 1 > k){
                do {
                    l--;
                } while(l > k && nums[l] == nums[l + 1]);
            } else {
                do {
                    j++;
                } while((j < numsSize - 2 && nums[j] == nums[j - 1]) || nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2] < target);
                if(j >= numsSize - 2){
                    do {
                        i++;
                    } while((i < numsSize - 3 && nums[i] == nums[i - 1]) || nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target || nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target);
                    j = i + 1;
                    k = j + 1;
                    l = numsSize - 1;
                } else {
                    k = j + 1;
                    l = numsSize - 1;
                }
            }
        }
        if(k > l - 1){
            do {
                j++;
            } while((j < numsSize - 2 && nums[j] == nums[j - 1]) || nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2] < target);
            if(j >= numsSize - 2){
                do {
                    i++;
                } while((i < numsSize - 3 && nums[i] == nums[i - 1]) || nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target || nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target);
                j = i + 1;
                k = j + 1;
                l = numsSize - 1;
            } else {
                k = j + 1;
                l = numsSize - 1;
            }
        } 
        if(j > k - 1) {
            do {
                i++;
            } while((i < numsSize - 3 && nums[i] == nums[i - 1]) || nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target || nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target);
            j = i + 1;
            k = j + 1;
            l = numsSize - 1;
        }
    }
    *returnSize = count;
    return result;
}

int main(){
    int array[] = {-4,-10,-1,-5,-7,0,0,4,-1,7,-8}; 
    int *returnSize = malloc(sizeof(int));
    int **result = fourSum(array, 11, -8, returnSize);
    printf("%d\n", *returnSize);

    return 0;
}