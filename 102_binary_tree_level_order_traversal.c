/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct ListNodeLevel {
    struct TreeNode* val;
    struct ListNodeLevel *next;
    int level;
};

struct ListNodeLevel* insertList(struct ListNodeLevel* head, struct ListNodeLevel* node){
	if(head == NULL){
		printf("insert list: first node\n");
		head = node;
		return node;
	}
	struct ListNodeLevel* newHead = head;
	while(head->next){
		head = head->next;
	}
	head->next = node;
	printf("insert list: not first node, %x\n", newHead);
	return newHead;
}

struct TreeNode* getFirst(struct ListNodeLevel* head){
	if(head == NULL){
		return NULL;
	}
	return head->val;
}

struct ListNodeLevel* removeListHead(struct ListNodeLevel* head){
	if(head == NULL){
		printf("error");
		return NULL;
	}
	struct ListNodeLevel* newHead = head->next;
	free(head);
	printf("remove now head: %x\n", newHead);
	return newHead;
}
struct Queue
{
	struct ListNodeLevel* head;
};

bool isQueueEmpty(struct Queue* q){
	return q->head == NULL;
}

void enQueue(struct Queue* q, struct TreeNode* node, int level){
	struct ListNodeLevel *newNode = malloc(sizeof(struct ListNodeLevel));
	newNode->val = node;
	newNode->level = level;
	newNode->next = NULL;
	struct ListNodeLevel *newHead = insertList(q->head, newNode);
	printf("enQueue %x, %x\n", newNode, node->val);
	q->head = newHead;
}

struct TreeNode* deQueue(struct Queue* q){
	struct TreeNode* val = getFirst(q->head);
	struct ListNodeLevel* node = removeListHead(q->head);
	q->head = node;
	
	printf("deQueue %x, %x\n", q->head, val);
	return val;
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
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if(root == NULL){
		return NULL;
	}
    struct Queue* q = malloc(sizeof(struct Queue));
    enQueue(q, root, 0);
    returnSize = malloc(sizeof(int));
    columnSizes = malloc(sizeof(int) * 1024);
    int **result = malloc(sizeof(int) * 1024);
    while(isQueueEmpty(q) == false){
    	struct TreeNode* node = deQueue(q);
    	//printf("%d\n", node->val);

    	if(node->left) enQueue(q, node->left, node->level + 1);
    	if(node->right) enQueue(q, node->right, node->level + 1);
    	count = node->level + 1;
    	result[node->level][columnSizes[node->level]] = node->val;
    	columnSizes[node->level]++;

    }
    return NULL;
}