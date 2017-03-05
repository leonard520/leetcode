/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
  if(root == NULL){
    return 0;
  }
  int cl = count(root->left);
  if(cl == k - 1) {
    return root->val;
  } else if(cl < k - 1){
    return kthSmallest(root->right, k - cl - 1);
  } else {
    return kthSmallest(root->left, k);
  }
}

int count(struct TreeNode* root){
  if(root == NULL){
    return 0;
  }
  return 1 + count(root->left) + count(root->right);
}
