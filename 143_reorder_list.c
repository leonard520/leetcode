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

struct ListNode* reverseLinkedList(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* current;
    struct ListNode* node;
    struct ListNode* nextNode;
    current = head;
    node = current->next;
    while(node){
        nextNode = node->next;
        node->next = current;
        current = node;
        node = nextNode;
    }
    head->next = NULL;
    return current;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if(head == NULL){
        return;
    }
    struct ListNode* reverseHead = head;
    struct ListNode* node = head;
    int step = 0;
    while(node){
        node = node->next;
        step++;
    }
    if(step == 1){
        return;
    }
    node = head;
    int i;
    for(i = 0; i < step / 2; i++){
        node = node->next;
    }
    reverseHead = reverseLinkedList(node);
    node = head;
    struct ListNode* tmp;
    struct ListNode* node2 = reverseHead;
    struct ListNode* tmp2;
    for(i = 0; i < step / 2; i++){
        tmp = node->next;
        tmp2 = node2->next;
        node->next = node2;
        node2->next = tmp;
        node = tmp;
        node2 = tmp2;
    }
    if(step % 2 == 1){
        node->next = tmp2;
        node = node->next;
    }
    node->next = NULL;

}

int main(){
    struct ListNode* head = malloc(sizeof(struct ListNode*));
    struct ListNode* n1 = malloc(sizeof(struct ListNode*));
    struct ListNode* n2 = malloc(sizeof(struct ListNode*));
    head->val = 1;
    n1->val = 2;
    n2->val = 3;
    head->next = n1;
    n1->next = n2;
    n2->next = NULL;
    reorderList(head);
    return 0;
}