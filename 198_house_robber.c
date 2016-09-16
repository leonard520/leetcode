/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int robInternal(int *nums, int start, int end){
	if(start > end){
		return 0;
	} else if(start == end){
		return nums[start];
	}
	int sum1 = nums[start] + robInternal(nums, start + 2, end);
	int sum2 = robInternal(nums, start + 1, end);
	return sum1 > sum2 ? sum1 : sum2;
}

int rob(int* nums, int numsSize) {
	if(nums == NULL || numsSize == 0){
		return 0;
	}
    return robInternal(nums, 0, numsSize - 1);
}

int main(){
	int nums[] = {9,23,5,1,100};
	printf("sum %d", rob(nums, 5));
}