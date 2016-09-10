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

void hasPathSum(struct TreeNode* root, int sum, int length, int *array, int **result, int *columnSizes, int *returnSize){
	if(root == NULL){
		return;
	}

	array[length] = root->val;
	length++;
	if(root->val == sum && !root->left && !root->right){
		int size = *returnSize;
		for(int i = 0; i < length; i++){
			result[size][i] = array[i];
		}
		columnSizes[size] = length;
		
		*returnSize = size + 1;
	} else {
		hasPathSum(root->left, sum - root->val, length, array, result, columnSizes, returnSize);
		hasPathSum(root->right, sum - root->val, length, array, result, columnSizes, returnSize);
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {

	int *columns = malloc(sizeof(int) * 5);
	memset(columns, 0, 5);
	int **result = malloc(sizeof(int) * 5);
	memset(result, 0, 5);
	for(int i = 0; i < 5; i++){
		result[i] = malloc(sizeof(int) * 32);
		memset(result[i], 0, 32);
	}
    int *array = malloc(sizeof(int) * 32);
    memset(array, 0, 32);
    int i, j;
    hasPathSum(root, sum, 0, array, result, columns, returnSize);
    *columnSizes = columns;
    free(array);
    array = NULL;
    return result;
}

int main(){
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = 5;
	struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
	t1->val = 4;
	struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
	t2->val = 8;
	struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
	t3->val = 11;
	struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
	t4->val = 13;
	struct TreeNode* t5 = malloc(sizeof(struct TreeNode));
	t5->val = 4;
	struct TreeNode* t6 = malloc(sizeof(struct TreeNode));
	t6->val = 7;
	struct TreeNode* t7 = malloc(sizeof(struct TreeNode));
	t7->val = 2;
	struct TreeNode* t8 = malloc(sizeof(struct TreeNode));
	t8->val = 5;
	struct TreeNode* t9 = malloc(sizeof(struct TreeNode));
	t9->val = 1;

	root->left = t1;
	root->right = t2;
	t1->left = t3;
	t1->right = NULL;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;
	t5->left = t8;
	t5->right = t9;

	int** columnSizes, **result;
	int* returnSize = malloc(sizeof(int));
	columnSizes = malloc(sizeof(int));

	result = pathSum(root, 22, columnSizes, returnSize);

	for(int i = 0; i < *returnSize; i++){
		for(int j = 0; j < (*columnSizes)[i]; j++){
			printf("%d, ", result[i][j]);
		}
		printf("\n");
	}

}
