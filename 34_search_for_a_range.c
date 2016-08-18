/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int binarySearch(int *nums, int s, int e, int target){
	if( s > e ) {
		return -1;
	}
	int m = (s + e) / 2;
	if(nums[m] == target){
		return m;
	} else if(nums[m] < target){
		return binarySearch(nums, m + 1, e, target);
	} else {
		return binarySearch(nums, s, m - 1, target);
	}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	if(nums == NULL){
		return NULL;
	}
	int point = binarySearch(nums, 0, numsSize - 1, target);
	int *result = malloc(sizeof(int) * 2);
	if(point != -1){
		int i = 1, j = 1, k;
		while(point - i >= 0 && nums[point - i] == target) i++;
		while(point + j < numsSize && nums[point + j] == target) j++;
		*returnSize = j + i - 1;
	    result[0] = point - i + 1;
	    result[1] = point + j - 1;
	    
	} else {
		result[0] = -1;
		result[1] = -1;
		
	}
	*returnSize = 2;
	return result;
}
int main(){
	int array[] = {1,3,5,6};
	searchInsert(array, 4, 5);
	return 0;
}