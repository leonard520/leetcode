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
 struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL || p == root || q == root){
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL){
        return right;
    } else if(right == NULL){
        return left;
    } else if(left == NULL && right == NULL){
        return root;
    }
    return root;
}

int main(){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 6;
    struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
    t1->val = 2;
    struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
    t2->val = 8;
    struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
    t3->val = 0;
    struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
    t4->val = 4;
    struct TreeNode* t5 = malloc(sizeof(struct TreeNode));
    t5->val = 7;
    struct TreeNode* t6 = malloc(sizeof(struct TreeNode));
    t6->val = 9;
    struct TreeNode* t7 = malloc(sizeof(struct TreeNode));
    t7->val = 3;
    struct TreeNode* t8 = malloc(sizeof(struct TreeNode));
    t8->val = 5;

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;
    t4->left = t7;
    t4->right = t8;

    printf("%p, %p\n", root, lowestCommonAncestor(root, t1, t2));
    printf("%p, %p\n", t1, lowestCommonAncestor(root, t1, t4));
    printf("%p, %p\n", t1, lowestCommonAncestor(root, t4, t1));
    printf("%p, %p\n", root, lowestCommonAncestor(root, t3, t6));
    printf("%p, %p\n", t2, lowestCommonAncestor(root, t5, t6));
}