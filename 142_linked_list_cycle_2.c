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

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode *node1, *node2;
    node1 = node2 = head;
    int count = 0;
    while(node1 != NULL && node2 != NULL){
        node1 = node1->next;
        node2 = node2->next;
        if(node2 != NULL) node2 = node2->next;
        else return NULL;
        count++;
        if(node1 == node2) break;
    }
    if(node2 == NULL) {
        return NULL;
    }
    printf("%d\n", count);
    node1 = node2 = head;
    for(int i = 0; i < count; i++){
        node1 = node1->next;
    }
    while(node1 != node2){
        node1 = node1->next;
        node2 = node2->next;
    }
    return node1;
}

int main(){
    struct ListNode* head = malloc(sizeof(struct ListNode*));
    struct ListNode* node1 = malloc(sizeof(struct ListNode*));
    struct ListNode* node2 = malloc(sizeof(struct ListNode*));
    struct ListNode* node3 = malloc(sizeof(struct ListNode*));
    head->next = node1; 
    node1->next = NULL;
    node2->next = node3;
    node3->next = node1;
    printf("%p, %p", node1, detectCycle(head));
    return 0;
}