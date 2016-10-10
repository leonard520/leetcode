/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int findLength(struct ListNode* head){
    int step = -1;
    struct ListNode* node;
    node = head;
    while(node){
        node = node->next;
        step++;
    }
    return step;
}

struct ListNode* nthNode(struct ListNode* head, int n){
    struct ListNode* node = head;
    for(int i = 0; i < n; i++){
        node = node->next;
    }
    return node;
}

struct TreeNode* sortedArrayToBSTInternal(struct ListNode* head, int num){
	
	if(head == NULL || num < 0){
    	return NULL;
    }
    int mid = num / 2;
    struct ListNode* midNode = nthNode(head, mid);
    struct TreeNode* node = malloc(sizeof(struct TreeNode* ));
    node->val = midNode->val;
    node->left = sortedArrayToBSTInternal(head, mid - 1);
    node->right = sortedArrayToBSTInternal(midNode->next, num - mid - 1);
    return node;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int n = findLength(head);
    return sortedArrayToBSTInternal(head, n);
}