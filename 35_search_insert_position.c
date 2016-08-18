/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int binarySearch(int *nums, int s, int e, int target){
	if(s > e) {
		return -1;
	}
	printf("%d, %d\n", s, e);
	if(s == e) {
		if(target == nums[s] || (s - 1 >= 0 && target < nums[s] && target > nums[s - 1])) return s;
		else if(target > nums[s]) return s + 1;
		else return s - 1;
	} else if(s + 1 == e){
		if(target > nums[e]) return e + 1;
		else if(target == nums[s] || (s - 1 >= 0 && target < nums[s] && nums[s - 1] < target)) return s;
		else if(target < nums[s]) return s - 1;
		else return e;
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

int searchInsert(int* nums, int numsSize, int target) {
	if(nums == NULL){
		return 0;
	}
	int point = binarySearch(nums, 0, numsSize - 1, target);
	
	return (point < 0) ? 0 : ((point > numsSize) ? numsSize : point);
}

int main(){
	int array[] = {1,3,5,6};
	printf("%d",searchInsert(array, 4, 5));
	return 0;
}