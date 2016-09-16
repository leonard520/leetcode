/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head && head->val == val){
        head = head->next;
    }
    if(head == NULL){
        return NULL;
    }
    struct ListNode* node1 = head->next;
    struct ListNode* node2 = head;
    while(node1){
        if(node1->val == val){
            node2->next = node1->next;
            free(node1);
            node1 = node2->next;
        } else {
            node2 = node1;
            node1 = node1->next;
        }
    }
    return head;
}