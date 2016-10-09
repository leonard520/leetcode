/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int maxProduct(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0){
        return 0;
    }
    int max = INT_MIN;
    int sum = 1;
    int i;
    for(i = 0; i < numsSize; i++){
        sum *= nums[i];
        max = sum > max ? sum : max;
        if(sum == 0){
            sum = 1;
        }
    }
    sum = 1;
    for(i = numsSize - 1; i >= 0; i--){
        sum *= nums[i];
        max = sum > max ? sum : max;

        max = sum > max ? sum : max;
        if(sum == 0){
            sum = 1;
        }
    }
    return max;
}