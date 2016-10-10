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
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* node = head;
    struct ListNode* p;
    while(node){
        if(node->val == x){
            p = node;
            break;
        }
        node = node->next;
    }
    node = head;
    struct ListNode* pHead = p;
    struct ListNode* tmp;
    struct ListNode* prev;
    struct ListNode* tmp2;
    while(node->val > x && node != pHead){
        tmp2 = node->next;
        tmp = p->next;
        p->next = node;
        node->next = tmp; 
        p = node;
        node = tmp2;
        head = node;
    }
    if(node != pHead){
        prev = node;
        node = node->next;
        while(node->next != pHead){
            if(node->val > x){
                tmp2 = node->next;
                tmp = p->next;
                p->next = node;
                node->next = tmp;
                p = node;
                node = tmp2;
            } else {
                node = node->next;
            }
        }
    }

    while(p != NULL){
        if(p->val < x){
            tmp2 = node->next;
            tmp = p->next;
            p->next = node;
            node->next = tmp;
            p = node;
            node = tmp2;
        } else {
            node = node->next;
        }
    }
}