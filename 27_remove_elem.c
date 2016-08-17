/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0){
        return NULL;
    }
    int value = nums[0];
    int point = 1;
    int i = 1;
    int result = 0;
    while(i < numsSize){
        if(value != nums[i]){      
            nums[point] = nums[i];
            point++;
            value = nums[i];
        }
        i++;
    }
    return point;
}