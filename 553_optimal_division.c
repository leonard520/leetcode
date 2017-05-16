/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

char* optimalDivision(int* nums, int numsSize) {
  char *result = malloc(sizeof(char) * 1024);
  result[0] = '\0';
  if(nums == NULL || numsSize == 0){
    strcat(result, "");
    return result;
  }
  char buffer[5];
  if(numsSize == 1){
    snprintf(buffer, 5, "%d", nums[0]);
    strcat(result, buffer);
  } else if(numsSize == 2){
    snprintf(buffer, 5, "%d", nums[0]);
    strcat(result, buffer);
    strcat(result, "/");
    snprintf(buffer, 5, "%d", nums[1]);
    strcat(result, buffer);
  } else {
    snprintf(buffer, 5, "%d", nums[0]);
    strcat(result, buffer);
    strcat(result, "/(");
    snprintf(buffer, 5, "%d", nums[1]);
    strcat(result, buffer);
    for(int i = 2; i < numsSize; i++){
      snprintf(buffer, 5, "%d", nums[i]);
      strcat(result, "/");
      strcat(result, buffer);
    }
    strcat(result, ")");
  }
  return result;
}
