/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int sum = m + n - 1;
    while(i >= 0 && j >= 0){
      if(nums1[i] <= nums2[j]){
        nums1[sum] = nums2[j];
        j--;
      } else {
        nums1[sum] = nums1[i];
        i--;
      }
      sum--;
    }
    if(i < 0){
      for(; j >=0; j--){
        nums1[sum--] = nums2[j];
      }
    }
}

int main(){
  int nums1[9] = {1,1,1,3,4,6};
  int m = 6;
  int nums2[] = {1,2,3};
  int n = 3;
  merge(nums1, m, nums2, n);
  for(int i = 0; i < m + n; i++){
    printf("%d ", nums1[i]);
  }
  return 0;
}