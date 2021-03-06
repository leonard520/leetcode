/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize) {
	if(nums == NULL || numsSize == 0){
		return 0;
	}
    if(numsSize == 1) return nums[0];
		if(numsSize == 2) return MAX(nums[0], nums[1]);

    int *mark = malloc(sizeof(int) * numsSize);
    mark[0] = nums[0];
    mark[1] = MAX(nums[0], nums[1]);
		//first time, no rob numsSize - 1
    for(int i = 2; i < numsSize - 1; i++){
    	mark[i] = MAX(mark[i - 1], mark[i - 2] + nums[i]);
    }
		int max = mark[numsSize - 2];
		//second time, no rob 0
		mark[0] = 0;
    mark[1] = nums[1];
    for(int i = 2; i < numsSize; i++){
    	mark[i] = MAX(mark[i - 1], mark[i - 2] + nums[i]);
    }
    return MAX(mark[numsSize - 1], max);
}

int main(){
	int nums[] = {9,23,5,1,100};
	printf("sum %d", rob(nums, 5));
}
