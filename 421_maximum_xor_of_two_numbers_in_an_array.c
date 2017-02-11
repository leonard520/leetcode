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
  int a = 0;
  int max = -1;
  struct TreeNode *root = malloc(sizeof(struct TreeNode));
  root->left = root->right = NULL;
  struct TreeNode *current;
  for(int i = 0; i < numsSize; i++){
    current = root;
    for(int j = 31; j >= 0; j--){
      if((nums[i] & (1 << j)) == 0){
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
    }
  }
  for(int i = 0; i < numsSize; i++){
    a = 0;

    current = root;
    for(int j = 31; j >= 0; j--){
      a <<= 1;
      if((nums[i] & (1 << j)) == 0){
        if(current->right != NULL){
          current = current->right;
          a += 1;
        } else {
          current = current->left;
        }
      } else {
        if(current->left != NULL){
          current = current->left;
          a += 1;
        } else {
          current = current->right;
        }
      }
    }
    if(max < a) max = a;
  }
  return max;
}
