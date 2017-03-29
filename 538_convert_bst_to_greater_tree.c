/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void convertBSTInternal(struct TreeNode* root, int* sum) {
  if(root == NULL){
    return;
  }
  convertBSTInternal(root->right, sum);
  root->val = root->val + *sum;
  *sum = root->val;
  convertBSTInternal(root->left, sum);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* convertBST(struct TreeNode* root) {
  if(root == NULL) return root;
  int sum = 0;
  convertBSTInternal(root, &sum);
  return root;
}
