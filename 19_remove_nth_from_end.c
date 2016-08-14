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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* h1;
    struct ListNode* h2;
    h1 = h2 = head;
    int i = 0;
    for(i = 0; i < n; i++){
        h1 = h1->next;
    }
    if(h1 == NULL){
        head = head->next;
        free(h2);
    } else {
        while(h1->next != NULL){
            h1 = h1->next;
            h2 = h2->next;
        }
        if(n == 1){
            h2->next = NULL;
            free(h1);
        } else {
            struct ListNode* tmp = h2->next;
            h2->next = tmp->next;
            free(tmp);
        }
    }
    return head;

}

int main(){
    struct ListNode* h1 = malloc(sizeof(struct ListNode* ));
    h1->next = NULL;
    removeNthFromEnd(h1, 1);
    return 0;
}