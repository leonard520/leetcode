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
int removeElement(int* nums, int numsSize, int val) {
    if(nums == NULL || numsSize == 0){
        return NULL;
    }
    int d = 0, i = 0;
    while(i < numsSize){
        if(nums[i] != val) nums[d++] = nums[i];
        i++;
    }
    return d;
}