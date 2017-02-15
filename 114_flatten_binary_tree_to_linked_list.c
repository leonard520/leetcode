/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
	if(root == NULL) return;
	flatten(root->left);
	flatten(root->right);
	struct TreeNode* right = root->right;
	struct TreeNode* left = root->left;
	root->left = NULL;
	if(left){
		root->right = left;
		while(root->right != NULL){
			root = root->right;
		}
		root->right = right;
	}
}

int main(){
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = 1;
	struct TreeNode* left = malloc(sizeof(struct TreeNode));
	left->val = 3;
	struct TreeNode* right = malloc(sizeof(struct TreeNode));
	right->val = 5;
	root->left = left;
	root->right = right;

	flatten(root);
}
