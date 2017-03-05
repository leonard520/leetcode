/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isLeave(struct TreeNode* root){
  return ((root->left == NULL) && (root->right == NULL));
}

int sumOfLeftLeavesInternal(struct TreeNode* root, bool isLeft){
  int result = 0;
  if(isLeave(root) == true){
    return (isLeft == true ? root->val : 0);
  }
  if(root->left) result += sumOfLeftLeavesInternal(root->left, true);
  if(root->right) result += sumOfLeftLeavesInternal(root->right, false);
  return result;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
  if(root == NULL){
    return 0;
  }
  return sumOfLeftLeavesInternal(root, false);
}
