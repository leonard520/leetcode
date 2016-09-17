/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct ListNode* reverseListInternal(struct ListNode* node1, struct ListNode* node2) {
    if(node2 == NULL){
        return node1;
    }
    struct ListNode* node3 = node2->next;
    node2->next = node1;
    return reverseListInternal(node2, node3);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* result = reverseListInternal(head, head->next);
    head->next = NULL;
    return result;
}