/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL) return false;
    if(root->val == sum && !root->left && !root->right) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}