/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for(int i = 0; i < numsSize; i++){
        result ^= nums[i];
    }
    return result;
}