/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBSTInternal(struct TreeNode* root, int f, int l, int h, bool f1, bool f2) {
    if(root == NULL){
        return true;
    }
    bool flag;
    if(f == 0){
        if(l == INT_MIN && root->val == INT_MIN && !f1){
            flag = true;
            f1 = true;
        }
        else if(h == INT_MAX && root->val == INT_MAX && !f2){
            flag = true;
            f2 = true;
        }
    } else {
        if(l == INT_MIN && root->val == INT_MIN && !f1){
            flag = true;
            f1 = true;
        }
        else if(h == INT_MAX && root->val == INT_MAX && !f2){
            flag = true;
            f2 = true;
        }
        else flag = (root->val < h && root->val > l)? true:false;
    }    
    printf("%d,%d,%d,%d,%d,%d\n", root->val, l, h, flag, f1, f2);
    
    if(f == 0){
        if(root->left){
            flag &= root->val > root->left->val ? true:false;
            flag &= isValidBSTInternal(root->left, 1, INT_MIN, root->val, f1, f2);
        }
        if(root->right){
            flag &= root->val < root->right->val ? true:false;
            flag &= isValidBSTInternal(root->right, -1, root->val, INT_MAX, f1, f2);
        }
    } else {
        if(root->left){
            flag &= root->val > root->left->val ? true:false;
            flag &= isValidBSTInternal(root->left, 1, l, root->val, f1, f2);
        }
        if(root->right){
            flag &= root->val < root->right->val ? true:false;
            flag &= isValidBSTInternal(root->right, -1, root->val, h, f1, f2);
        }
    }
    
    return flag;
}

bool isValidBST(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    return isValidBSTInternal(root, 0, root->val, root->val, false, false);
}