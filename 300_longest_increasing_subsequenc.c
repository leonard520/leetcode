/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int BS(int* nums, int l, int h, int k){
	int m;
	while(l <= h){
		if(l == h) {
			return nums[l] >= k ? l : l + 1;
		}
		m = (l + h) / 2;
		if(nums[m] < k && nums[m + 1] >= k){
			return m + 1;
		} else if(nums[m] <= k && nums[m + 1] > k){
			return m;
		} else if(nums[m] > k){
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	return l;
}

int lengthOfLIS(int* nums, int numsSize) {
	if(nums == NULL || numsSize == 0){
		return 0;
	}
	int *p = malloc(sizeof(int) * numsSize);
	int len = 1;
	p[0] = nums[0];
	for(int i = 1; i < numsSize; i++){

		if(nums[i] > p[len - 1]){
			p[len] = nums[i];
			len++;
		} else {
			p[BS(p, 0, len - 1, nums[i])] = nums[i];
		}
	}
	return len;
}