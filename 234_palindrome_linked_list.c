/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

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
bool isPalindrome(struct ListNode* head) {
    if(head == NULL){
        return true;
    }
    struct ListNode* node1 = head;
    struct ListNode* node2 = head;
    struct ListNode* n1 = head;
    struct ListNode* n2 = head->next;
    bool odd = true;
    while(node2->next){
        node2 = node2->next;
        if(node2->next){
            node2 = node2->next;
        } else {
            odd = false;
            break;
        }

        node1 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = node1;
    }
    head->next = NULL;
    if(odd == true){
        printf("odd\n");
        n1 = n1->next;
        while(n2){
            if(n1->val != n2->val){
                return false;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
    } else {
        while(n2){
            if(n1->val != n2->val){
                return false;
            }
            n2 = n2->next;
            n1 = n1->next;
        }
    }
    return true;
}

int main(){
    struct ListNode* node1 = malloc(sizeof(struct ListNode*));
    struct ListNode* node2 = malloc(sizeof(struct ListNode*));
    struct ListNode* node3 = malloc(sizeof(struct ListNode*));
    struct ListNode* node4 = malloc(sizeof(struct ListNode*));
    struct ListNode* node5 = malloc(sizeof(struct ListNode*));
    node1->next = node2; node1->val = 1;
    node2->next = node3; node2->val = 2;
    node3->next = node4; node3->val = 3;
    node4->next = node5; node4->val = 2;
    node5->next = NULL; node5->val = 1;
    printf("%d\n", isPalindrome(node1));

    return 0;
}