/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void tree2strInternal(struct TreeNode* t, char* r) {
  if(t == NULL) {
    strcat(r, "(");
    strcat(r, ")");
    return;
  }
  strcat(r, "(");
  char str[10];
  sprintf(str, "%d", t->val);
  strcat(r, str);
  if(t->left || t->right){
    tree2strInternal(t->left, r);
    if(t->right){
      tree2strInternal(t->right, r);
    }
  }
  strcat(r, ")");
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* tree2str(struct TreeNode* t) {
  if(t == NULL) return "";
  char* result = malloc(sizeof(char) * 102400);
  char str[10];
  sprintf(str, "%d", t->val);
  strcat(result, str);
  tree2strInternal(t->left, result);
  tree2strInternal(t->right, result);
  return result;
}

int main() {
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = 1;
  struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
  t1->val = 2;
  struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
  t2->val = 3;
  root->left = t1;
  root->right = t2;
  return 0;
}
