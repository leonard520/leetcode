/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

char* reverseString(char* s) {
    if(s == NULL){
        return NULL;
    }
    int m = strlen(s);
    if(s[0] == '-'){
	    for(int i = 1; i < m / 2; i++){
	        char tmp = s[i];
	        s[i] = s[m - i];
	        s[m - i] = tmp;
	    }
	} else {
		for(int i = 0; i < m / 2; i++){
	        char tmp = s[i];
	        s[i] = s[m - i - 1];
	        s[m - i - 1] = tmp;
	    }
	}
    return s;
}

char* itoa(int a, char *s){
    if(s == NULL) return NULL;
    int i = 0;
    if(a == 0){
        s[i] = '0';
        i++;
    }
    if(a < 0){
		a = -a;
		s[i] = '-';
		i++;
	}

	while(a > 0){
       s[i] = a % 10 + '0';
       a /= 10;
       i++;
	}
	s[i] = '\0';
	reverseString(s);
    return s;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void binaryTreePathsInternal(struct TreeNode* root, char** path, int* returnSize){
	if(root == NULL){
		return;
	}
	char s[10];
	char p[128];
	if(strlen(path[*returnSize]) > 0){
		strcat(path[*returnSize], "->");
	}
	strcat(path[*returnSize], itoa(root->val, s));
	strcpy(p, path[*returnSize]);
	if(root && root->left == NULL && root->right == NULL){
		*returnSize = *returnSize + 1;
		return;
	}

	if(root->left){
		binaryTreePathsInternal(root->left, path, returnSize);
	}
	if(root->right){
		strcpy(path[*returnSize], p);
		binaryTreePathsInternal(root->right, path, returnSize);
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	char **result = malloc(sizeof(char *) * 1024);
	for(int i = 0; i < 1024; i++){
		result[i] = malloc(sizeof(char) * 128);
		result[i][0] = '\0';
	}
    binaryTreePathsInternal(root, result, returnSize);
    return result;
}

int main(){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
    t1->val = 2;
    struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
    t2->val = 3;
    struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
    t3->val = 4;
    struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
    t4->val = 5;
    struct TreeNode* t5 = malloc(sizeof(struct TreeNode));
    t5->val = 6;
    struct TreeNode* t6 = malloc(sizeof(struct TreeNode));
    t6->val = 7;

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = NULL;
    t3->left = t6;
    t3->right = NULL;
    t4->left = NULL;
    t4->right = NULL;
    t5->left = NULL;
    t5->right = NULL;
    t6->left = NULL;
    t6->right = NULL;
    // struct TreeNode* root = malloc(sizeof(struct TreeNode));
    // root->val = 1;
    // struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
    // t1->val = 2;
    // struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
    // t2->val = 3;
    // struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
    // t3->val = 5;
    // root->left = t1;
    // root->right = t2;
    // t1->left = NULL;
    // t1->right = t3;
    // t2->left = NULL;
    // t2->right = NULL;
    char s[10];
    printf("%s\n", itoa(-93, s));

    int *returnSize = malloc(sizeof(int));

    char** result = binaryTreePaths(root, returnSize);
    for(int i = 0; i < *returnSize; i++){
    	printf("%s\n", result[i]);
    }
}