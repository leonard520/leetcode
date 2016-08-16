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
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    struct ListNode* previous = head;
    while(node1 != NULL){
        if(node2 == NULL){
            if(node1 != head){
                previous->next = node1;
            }
            return head;
        }
        struct ListNode* tmp = node2->next;
        if(head == node1){
            head = node2;
            head->next = node1;
            previous = node1;
        } else {
            previous->next = node2;
            node2->next = node1;
            previous = node1;
        }
        node1 = tmp;
        if(node1 != NULL){
            node2 = node1->next;
        } else {
            previous->next = NULL;
            return head;
        }
    }
    previous->next = NULL;
    return head;
}

int main(){
    int *returnSize = malloc(sizeof(int));
    char **r = generateParenthesis(8, returnSize);

}