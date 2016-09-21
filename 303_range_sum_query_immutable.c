/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct NumArray {
    int sum[1024];
    int number;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* result = malloc(sizeof(struct NumArray*));
    result->sum[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        result->sum[i] = result->sum[i - 1] + nums[i];
    }
    result->number = numsSize;
    return result;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if(i < 0 || j > numsSize);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);