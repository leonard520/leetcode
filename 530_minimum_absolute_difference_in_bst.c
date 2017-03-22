/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getMinimumDifferenceInternal(struct TreeNode* root) {
  if(root == NULL){
    return INT_MAX;
  }
  int left = INT_MAX;
  int right = INT_MAX;
  if(root->left) left = root->val - root->left->val;
  if(root->right) right = root->right->val - root->val;
  int left_child = getMinimumDifferenceInternal(root->left);
  int right_child = getMinimumDifferenceInternal(root->right);
  int t1 = left < right ? left : right;
  int t2 = left_child < right_child ? left_child : right_child;
  return t1 < t2 ? t1 : t2;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
  return getMinimumDifferenceInternal(root);
}
