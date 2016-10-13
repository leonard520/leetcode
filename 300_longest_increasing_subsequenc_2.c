/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int lengthOfLIS(int* nums, int numsSize) {
	int *p = malloc(sizeof(int) * numsSize);
	int flag = 0;
	p[0] = 1;
	int *flag = malloc(sizeof(int) * numsSize);
	flag[0] = nums[0];
	for(int i = 1; i < numsSize; i++){
		if(nums[i] > flag){
			p[i] = p[i - 1] + 1;
			flag = num[i];
		} else {
			p[i] = p[i - 1];
			flag = (flag < nums[i]) ? flag:nums[i];
		}
	}
	for(int i = 0; i < numsSize; i++){
		printf("%d ", p[i]);
	}
	return p[numsSize - 1];
}