/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findTiltInternal(struct TreeNode* root, int *result) {
  if(root == NULL) return 0;
  int left = findTiltInternal(root->left, result);
  int right = findTiltInternal(root->right, result);
  *result += abs(left - right);
  return left + right + root->val;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findTilt(struct TreeNode* root) {
  int a = 0;
  findTiltInternal(root, &a);
  return a;
}

int main() {
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = 1;
  struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
  t1->val = 2;
  struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
  t2->val = 3;
  root->left = t1;
  root->right = t2;
  findTilt(root);

  return 0;
}
