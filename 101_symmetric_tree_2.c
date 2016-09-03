/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isSymmetricTree(struct TreeNode* left, struct TreeNode* right){
	if(left == NULL && right == NULL){
		return true;
	} else if(left == NULL || right == NULL){
		return false;
	} else if(left->val != right->val){
		return false;
	} else {
		return isSymmetricTree(left->left, right->right) && isSymmetricTree(right->left, left->right);
	}
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL){
    	return true;
    }
    return isSymmetricTree(root->left, root->right);
}