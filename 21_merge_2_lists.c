/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 == NULL){
        return NULL;
    } else if(l1 == NULL){
        return l2;
    } else if(l2 == NULL){
        return l1;
    }
    struct ListNode* head;
    struct ListNode* point;
    if(l1->val <= l2->val){
        head = point = l1;
        l1 = l1->next;
    } else {
        head = point = l2;
        l2 = l2->next;
    }
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            point->next = l1;
            point = l1;
            l1 = l1->next;
        } else {
            point->next = l2;
            point = l2;
            l2 = l2->next;
        }
    }
    if(l1 == NULL){
        while(l2 != NULL){
            point->next = l2;
            point = l2;
            l2 = l2->next;
        }
    }
    if(l2 == NULL){
        while(l1 != NULL){
            point->next = l1;
            point = l1;
            l1 = l1->next;
        }
    }
    return head;
}