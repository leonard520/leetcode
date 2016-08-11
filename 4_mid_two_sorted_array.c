/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double result;
    int count = 0;
    int i = 0, j = 0;
    int a, b;
    int start;
    if(nums1 == NULL || nums2 == NULL){
        return 0;
    }

    if(((nums1Size + nums2Size) % 2) == 0){
        i = j = 0;
        start = (nums1Size + nums2Size) / 2;
        bool flag1 = (nums1Size > 0) ? true:false;
        bool flag2 = (nums2Size > 0) ? true:false;
        
        while(count < start){
            int tmp = flag2 ? nums2[j]:65535;
            if(flag1 && nums1[i] <= tmp){
                a = nums1[i];
                i++;
            } else if(flag2) {
                a = nums2[j];
                j++;
            }
            count++;
            flag1 = (nums1Size > i) ? true:false;
            flag2 = (nums2Size > j) ? true:false;

        }

        if(flag1 && flag2){
            b = nums1[i] > nums2[j] ? nums2[j]:nums1[i];
        } else if(flag1) {
            b = nums1[i];
        } else if(flag2){
            b = nums2[j];
        }
    } else {
        i = j = 0;
        start = (nums1Size + nums2Size) / 2 + 1;
        bool flag1 = (nums1Size > 0) ? true:false;
        bool flag2 = (nums2Size > 0) ? true:false;
            
        while(count < start){
            int tmp = flag2 ? nums2[j]:65535;
            if(flag1 && nums1[i] <= tmp){
                a = nums1[i];
                i++;
            } else if(flag2) {
                a = nums2[j];
                j++;
            }
            count++;
            flag1 = (nums1Size > i) ? true:false;
            flag2 = (nums2Size > j) ? true:false;
        }
        b = a;
    }
    result = ((double)a + (double)b)/2;
    return result;
}

int main(){
    int nums1[] = {1,4,7,9};
    int nums2[] = {};
    printf("%f", findMedianSortedArrays(nums1, 4, nums2, 0));
}