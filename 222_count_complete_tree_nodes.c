/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int height(struct TreeNode* root){
  if(root == NULL){
    return 0;
  }
  return 1 + height(root->left);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
  if(root == NULL){
    return 0;
  }
  int h = height(root);
  int hr = height(root->right);
  if(hr == h - 1){
    return (1 << (h - 1)) + countNodes(root->right);
  } else {
    return (1 << hr) + countNodes(root->left);
  }
}
