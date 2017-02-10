/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
};


int findMaximumXOR(int* nums, int numsSize) {
  if(nums == NULL || numsSize == 0){
    return 0;
  }
  int n = 0;
  int a = 0;
  int max = -1;
  struct TreeNode *root = malloc(sizeof(struct TreeNode));
  struct TreeNode *current;
  for(int i = 0; i < numsSize; i++){
    n = 0;
    current = root;
    for(int j = 0; j < 32; j++){
      if((nums[i] & (n << j)) == 0){
        if(current->left == NULL){
          current->left = malloc(sizeof(struct TreeNode));
        }
        current = current->left;
      } else {
        if(current->right == NULL){
          current->right = malloc(sizeof(struct TreeNode));
        }
        current = current->right;
      }
      n++;
    }
  }
  for(int i = 0; i < numsSize; i++){
    n = 0;
    a = 0;
    for(int j = 0; j < 32; j++){
      a *= 2;
      if((nums[i] & (n << j)) == 0){
        if(current->right != NULL){
          current = current->right;
          a += 1;
        }
      } else {
        if(current->left != NULL){
          current = current->left;
        }
      }
      n++;
    }
    if(max < a) max = a;
  }
  return max;
}
