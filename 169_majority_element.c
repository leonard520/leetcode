/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int maybeMajority = nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++){
        if(maybeMajority != nums[i]){
            count--;
        } else {
            count++;
        }
        if(count < 0){
            maybeMajority = nums[i];
            count = 1;
        }
    }
    return maybeMajority;
}