/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

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
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    struct ListNode* node3;
    while(node2 != NULL){
        node3 = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = node3;
    }
    head->next = NULL;
    return node1;
}