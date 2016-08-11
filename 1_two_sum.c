/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}
