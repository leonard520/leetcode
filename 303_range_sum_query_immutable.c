/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct NumArray {
    int *sum;
    int number;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray* result = malloc(sizeof(struct NumArray*));
    result->sum = malloc(sizeof(int) * numsSize);
    result->sum[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        result->sum[i] = result->sum[i - 1] + nums[i];
    }
    result->number = numsSize;
    return result;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if(i < 0 || j >= numArray->number) return 0;
    if(i == 0) return numArray->sum[j];
    else return (numArray->sum[j] - numArray->sum[i - 1]);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sum);
    free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

int main(){
    int nums[] = {-2, 0, 3, -5, 2, -1};
    int numsSize = 6;
    struct NumArray* numArray = NumArrayCreate(nums, numsSize);
    printf("%d", sumRange(numArray, 0, 1));
    printf("%d", sumRange(numArray, 1, 2));
    NumArrayFree(numArray);
}