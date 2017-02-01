/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include "util.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
int i, j;
    int *result = malloc(2 * sizeof(int));
    int *shadow = malloc(numsSize * sizeof(int));

    for(int t = 0; t < numsSize; t++){
        shadow[t] = nums[t];
    }

    quickSort(nums, 0, numsSize - 1);
    i = 0;
    j = numsSize - 1;

    while(nums[i] + nums[j] != target){
        if(nums[i] + nums[j] > target){
            j--;
        } else if(nums[i] + nums[j] < target){
            i++;
        }
    }
    if(nums[i] + nums[j] == target){
        int k = 0;
        for(k = 0; k < numsSize; k++){
            if(shadow[k] == nums[i]){
                result[0] = k;
                break;
            }
        }
        for(int l = 0; l < numsSize; l++){
            if(l != k) {
                if(shadow[l] == nums[j]){
                    result[1] = l;
                }
            }
        }

        return result;
    }
    return NULL;
}

int main(){
    int array[] = {1,9,19,2,3,4,8};
    int *result = twoSum(array, 7, 6);
    if(result){
        for( int i = 0; i < 2; i++){
            printf("%d ", result[i]);
        }
    }

    return 0;
}
