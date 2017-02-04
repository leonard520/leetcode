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

void traverse(struct TreeNode* root, int **list, int *max, int *c, int *p, int *b){
  if(root == NULL){
    return;
  }
  if(root->left){
    traverse(root->left, list, max, c, p, b);
  }
  *b = 1;
  if(*p == -1) {
    (*list)[0] = root->val;
    *max = 1;
    *c = 1;
    *p = 0;
  } else if(root->val == (*list)[*p]){
    (*c)++;
    if(*max < *c){
      *max = *c;
      (*list)[0] = root->val;
      *p = 0;
    }
  } else {
    if(*max == *c){
      (*list)[++(*p)] = root->val;
      *c = 1;
      *b = 0;
    } else {
      (*list)[*p] = root->val;
      *c = 1;
      *b = 0;
    }
  }

  if(root->right){
    traverse(root->right, list, max, c, p, b);
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
int* findMode(struct TreeNode* root, int* returnSize) {
  int *result = malloc(sizeof(int) * 100);
  int *max = malloc(sizeof(int));
  int *p = malloc(sizeof(int));
  int *c = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  *max = *p = *c = *b = -1;
  traverse(root, &result, max, c, p, b);
  if(*b == 0){
    *returnSize = (*p);
  } else {
    *returnSize = (*p) + 1;
  }

  free(max);
  free(p);
  free(c);
  free(b);
  return result;
}

int main(){
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = 1;
	struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
	t1->val = 2;
	struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
	t2->val = 2;

  root->left = NULL;
	root->right = t1;
	t1->left = t2;
  t1->right = NULL;
  t2->left = t2->right = NULL;

  int* returnSize = malloc(sizeof(int));
  findMode(root, returnSize);
}
