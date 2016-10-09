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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void preOrder(struct TreeNode* root) {
    if(root == NULL) return;
    printf("%d\n", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

 void postOrder(struct TreeNode* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n", root->val);
}

void inOrder(struct TreeNode* root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d\n", root->val);
    inOrder(root->right);
}

int main(){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 6;
    struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
    t1->val = 2;
    struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
    t2->val = 7;
    struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
    t3->val = 1;
    struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
    t4->val = 4;
    struct TreeNode* t5 = malloc(sizeof(struct TreeNode));
    t5->val = 9;
    struct TreeNode* t6 = malloc(sizeof(struct TreeNode));
    t6->val = 3;
    struct TreeNode* t7 = malloc(sizeof(struct TreeNode));
    t7->val = 5;
    struct TreeNode* t8 = malloc(sizeof(struct TreeNode));
    t8->val = 8;

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = NULL;
    t2->right = t5;
    t4->left = t6;
    t4->right = t7;
    t5->left = t8;
    t5->right = NULL;

    inOrder(root);
}