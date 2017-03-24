/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define MIN(a,b) (a) < (b) ? (a) : (b)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void getMinimumDifferenceInternal(struct TreeNode* root, int *prev, int *min) {
  if(root->left) getMinimumDifferenceInternal(root->left, prev, min);
  int current = INT_MAX;
  if(*prev >= 0){
    current = root->val - *prev;
  }
  *min = MIN(current, *min);
  *prev = root->val;
  if(root->right) getMinimumDifferenceInternal(root->right, prev, min);
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
  if(root == NULL) return INT_MAX;
  int *prev = malloc(sizeof(int));
  int *min = malloc(sizeof(int));
  *prev = -1;
  *min = INT_MAX;
  getMinimumDifferenceInternal(root, prev, min);
  return *min;
}
