/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * rotate(struct ListNode *head, int n){
    struct ListNode *node = head;
    for(int i = 0; i < n - 1; ++i)
    {
        node = node->next;
    }
    return node;
}

void dump(struct ListNode *node, int n){
    for(int i = 0; i < n; i++)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int maxRotateFunction(int* A, int ASize) {
    if(A == NULL || ASize == 0) return 0;
    int i = 0, j = 0;
    int sum = 0;
    int max = INT_MIN;
    struct ListNode *head = malloc(sizeof(struct ListNode *));
    head->val = 0;
    struct ListNode *node;
    struct ListNode *previous = head;
    for(i = 1; i < ASize; i++){
        node = malloc(sizeof(struct ListNode *));
        node->val = i;
        previous->next = node;
        previous = node;
    }
    node->next = head;
    for(i = 0; i < ASize; i++){
        sum = 0;
        node = head;
        for(j = 0; j < ASize; j++){
            sum += j * A[node->val];
            node = node->next;
        }
        max = max > sum ? max : sum;
        head = rotate(head, ASize);
    }
    return max;
}

int main(){
    int A[] = {4, 3, 2, 6};
    printf("%d\n", maxRotateFunction(A, 4));
    return 0;
}