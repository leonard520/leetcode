/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *node1, *node2;
    node1 = headA, node2 = headB;
    while(node1 != node2){
        node1 = node1 ? node1->next : headB;
        node2 = node2 ? node2->next : headA;
    }
    return node1;
}

int main(){
    struct ListNode* head = malloc(sizeof(struct ListNode*));
    struct ListNode* node1 = malloc(sizeof(struct ListNode*));
    struct ListNode* node2 = malloc(sizeof(struct ListNode*));
    struct ListNode* node3 = malloc(sizeof(struct ListNode*));
    head->next = node1; 
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    struct ListNode* head2 = malloc(sizeof(struct ListNode*));
    head2->next = NULL;

    printf("%p, %p", node2, getIntersectionNode(head, head2));
    return 0;
}