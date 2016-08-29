/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int *result = NULL;
    if(digits == NULL){
      *returnSize = 1;
      result = malloc(sizeof(int));
      result[0] = 1;
      return result;
    }
    int i = 0, j = 1;
    bool flag = true;
    for(i = 0; i < digitsSize; i++){
      if(digits[i] != 9){
        flag = false;
      }
    }
    if(flag == true){
      result = malloc(sizeof(int) * (1 + digitsSize));
      j = digitsSize + 1 - 1;
    } else {
      result = malloc(sizeof(int) * (digitsSize));
      j = digitsSize - 1;
    }
    int carry = 1;
    for(i = digitsSize - 1; i >= 0; i--, j--){
      if(digits[i] + carry == 10 ){
        carry = 1;
        result[j] = 0;
      } else {
        result[j] = digits[i] + carry;
        carry = 0;
      }
    }
    if(carry == 1){
      result[j] = 1;
      *returnSize = digitsSize + 1;
    } else {
      *returnSize = digitsSize;
    }
    return result;
}