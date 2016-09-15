/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void rotateInternal(int *nums, int start, int end){
	if(end - start < 0) return;
	int mid = (end - start) / 2;
	for(int i = 0; i <= mid; i++){
		int tmp = nums[i + start];
		nums[i + start] = nums[end - i];
		nums[end - i] = tmp;
	}
}

void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
    rotateInternal(nums, 0, numsSize - 1);

    rotateInternal(nums, 0, k - 1);

    rotateInternal(nums, k, numsSize - 1);
}