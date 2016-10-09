/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if(nums == NULL || numsSize == 0){
        return NULL;
    }
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i = 0;
    int product = 1;
    for(i = 0; i < numsSize; i++){
        result[i] = product;
        product *= nums[i];
    }
    product = 1;
    for(i = numsSize - 1; i >= 0; i--){
        result[i] *= product;
        product *= nums[i];
    }
    return result;
}