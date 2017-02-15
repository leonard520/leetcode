/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
  struct TreeLinkNode *node = root;
  while(node != NULL){
    struct TreeLinkNode *cur = node;
    while(cur != NULL){
      if(cur->left != NULL){
        cur->left->next = cur->right;
      }
      if(cur->next != NULL && cur->right != NULL){
        cur->right->next = cur->next->left;
      }
      cur = cur->next;
    }
    node = node->left;
  }
}
