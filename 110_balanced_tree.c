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
int maxDepth(struct TreeNode* root) {
    if(root == NULL){
    	return 0;
    }
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if(l < 0 || r < 0 || l - r > 1 || r - l > 1) return -2;
    else return l > r ? l + 1 : r + 1;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    return maxDepth(root) < 0 ? false : true;
}