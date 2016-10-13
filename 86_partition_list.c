/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

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
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL){
        return NULL;
    }
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
    struct ListNode* tmpp;
    struct ListNode* prevHead = head;
    struct ListNode* tmp;
    while(node != NULL && node->val > x){
        tmp = node->next;
        tmpp = p->next;
        p->next = node;
        node->next = tmpp;
        p = tmpp;
        head = tmp;
        node = tmp;
        prevHead = node;
    }
    if(node != pHead){
        while(node != pHead){
            if(node->val > x){
                tmp = node->next;
                tmpp = p->next;
                p->next = node;
                node->next = tmpp;
                p = tmpp;
                prevHead->next = tmp;

            } else {
                prevHead = node;
                node = node->next;
            }
        }
    }
    node = node->next;
    pHead = p;
    while(node){
        if(node->val < x){
            tmp = node->next;
            tmpp = prevHead->next;
            prevHead->next = node;
            node->next = tmpp;
            prevHead = tmpp;
            pHead->next = tmp;
        } else {
            pHead = node;
            node = node->next;
        }
    }
    return head;
}

int main(){
    //5>1>6>2>4>3>1

    struct ListNode* head = malloc(sizeof(struct ListNode*));
    struct ListNode* n1 = malloc(sizeof(struct ListNode*));
    struct ListNode* n2 = malloc(sizeof(struct ListNode*));
    head->val = 3;
    n1->val = 2;
    n2->val = 1;
    head->next = n1;
    n1->next = n2;
    n2->next = NULL;
    partition(head, 2);
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}