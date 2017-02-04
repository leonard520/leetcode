/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

struct ListNodeLevel {
    struct TreeNode* val;
    struct ListNodeLevel *next;
    int level;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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
	return newHead;
}

struct TreeNode* getFirst(struct ListNodeLevel* head){
	if(head == NULL){
		return NULL;
	}
	return head->val;
}

struct ListNodeLevel* removeListHead(struct ListNodeLevel* head, int *l){
	if(head == NULL){
		printf("error\n");
		l = 0;
		return NULL;
	}
	struct ListNodeLevel* newHead = head->next;
	*l = head->level;
	free(head);
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
  printf("enQueue: %d, %d\n", node->val, level);
	struct ListNodeLevel *newNode = malloc(sizeof(struct ListNodeLevel));
	newNode->val = node;
	newNode->level = level;
	newNode->next = NULL;
	struct ListNodeLevel *newHead = insertList(q->head, newNode);
	q->head = newHead;
}

struct TreeNode* deQueue(struct Queue* q, int *l){
	struct TreeNode* val = getFirst(q->head);
	struct ListNodeLevel* node = removeListHead(q->head, l);
  printf("deQueue: %d, %d\n", val->val, *l);
	q->head = node;
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
 int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if(root == NULL){
		return NULL;
	}
	int i = 0, j = 0;
    struct Queue* q = malloc(sizeof(struct Queue));
    enQueue(q, root, 0);
    *columnSizes = malloc(sizeof(int) * 10);
    for(i = 0; i < 10; i++){
    	(*columnSizes)[i] = 0;
    }
    int **result = malloc(sizeof(int *) * 10);
    int **result2 = malloc(sizeof(int *) * 10);
    int temp = 1;
    for(i = 0; i < 10; i++){
    	result[i] = malloc(sizeof(int) * temp);
      result2[i] = malloc(sizeof(int) * temp);
      temp *= 2;
    }
    int level = 0;
    while(isQueueEmpty(q) == false){
    	int *l = malloc(sizeof(int));
    	struct TreeNode* node = deQueue(q, l);
    	level = *l;
    	int ll = (*columnSizes)[level];
    	printf("levle value, %d, ll %d\n", *l, ll);
    	printf("node value %d\n", node->val);
    	result[level][ll] = node->val;
    	(*columnSizes)[level] = ll + 1;;
    	free(l);
    	if(node->left) enQueue(q, node->left, level + 1);
    	if(node->right) enQueue(q, node->right, level + 1);
    }

    *returnSize = level + 1;
    for(i = 0; i < (level + 1) / 2; i++){
      int t = (*columnSizes)[i];
      (*columnSizes)[i] = (*columnSizes)[level - i];
      (*columnSizes)[level - i] = t;
    }
    for(i = 0; i < level + 1; i++){
      for(j = 0; j < (*columnSizes)[i]; j++){
        result2[i][j] = result[level - i][j];
      }
    }
    return result2;
}

int main(){
  //[3,9,20,null,null,15,7]

	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = 3;
	struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
	t1->val = 9;
	struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
	t2->val = 20;
	struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
	t3->val = 15;
	struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
	t4->val = 7;

	root->left = t1;
	root->right = t2;
	t1->left = NULL;
	t1->right = NULL;
	t2->left = t3;
	t2->right = t4;
	t3->left = t3->right = t4->left = t4->right = NULL;

	int* columnSizes = malloc(sizeof(int) * 10);
  int **result;
	int* returnSize = malloc(sizeof(int));
	result = levelOrderBottom(root, &columnSizes, returnSize);

  printf("return size: %d\n", *returnSize);
  for(int i = 0; i < *returnSize; i++){
    for(int j = 0; j < columnSizes[i]; j++){
      printf("%d, ", result[i][j]);
    }
    printf("\n");
  }
}
