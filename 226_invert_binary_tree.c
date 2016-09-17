/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void invertTreeInternal(struct TreeNode* root) {
    if(root == NULL){
        return NULL;
    }
    struct TreeNode* node = root->left;
    root->left = root->right;
    root->right = node;
    invertTreeInternal(root->left);
    invertTreeInternal(root->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    invertTreeInternal(root);
    return root;
}