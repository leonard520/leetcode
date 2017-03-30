/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int diameterOfBinaryTreeInternal(struct TreeNode* root, int *max) {
  if(root == NULL){
    return 0;
  }
  int a = diameterOfBinaryTreeInternal(root->left, max);
  int b = diameterOfBinaryTreeInternal(root->right, max);
  *max = (a + b) > *max ? (a + b) : *max;
  return 1 + (a > b ? a : b);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root) {
  if(root == NULL) return 0;
  int max = 0;
  diameterOfBinaryTreeInternal(root, &max);
  return max;
}
