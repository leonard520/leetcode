/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isSubtreeInternal(struct TreeNode* s, struct TreeNode* t) {
	if(s == NULL && t == NULL) return true;
	if(s == NULL || t == NULL) return false;
	if(s->val == t->val){
		return (isSubtreeInternal(s->right, t->right) && isSubtreeInternal(s->left, t->left));
	} else {
		return false;
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
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if(isSubtreeInternal(s, t) == true) return true;
	if(s == NULL || t == NULL) return false;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
