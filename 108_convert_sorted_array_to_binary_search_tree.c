/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBSTInternal(int *nums, int low, int high){
	
	if(nums == NULL || (high - low) < 0){
    	return NULL;
    }
    int mid = (high + low) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode* ));
    node->val = nums[mid];
    node->left = sortedArrayToBSTInternal(nums, low, mid - 1);
    node->right = sortedArrayToBSTInternal(nums, mid + 1, high);
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayToBSTInternal(nums, 0, numsSize - 1);

}