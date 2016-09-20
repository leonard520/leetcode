/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int* nums, int low, int high) {
    int flag, i, j;
    if(low < high){
        flag = low;
        i = low;
        j = high;
        while(i < j){
            while(nums[i] <= nums[flag] && i <= high){
                i++;
            }
            while(nums[j] > nums[flag] && j >= low){
                j--;
            }
            if(i < j){
                swap(&nums[i], &nums[j]);
            }
        }
        swap(&nums[j], &nums[flag]);
        quickSort(nums, low, j - 1);
        quickSort(nums, j + 1, high);
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1 == NULL || nums2 == NULL) {
        returnSize = 0;
        return NULL;
    }
    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);
    int i, j;
    i = j = 0;
    int *result = malloc(sizeof(int) * 1024);
    int count = 0;
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]) i++;
        else if(nums1[i] > nums2[j]) j++;
        else {
            result[count] = nums1[i];
            count++;
            i++; j++;
        }
    }
    *returnSize = count;
    return result;
}