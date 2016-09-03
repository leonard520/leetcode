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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node1, *node2, *node3;
    node1 = head;
    while(node1 && node1->next){
      node2 = node1->next;
      if(node1->val == node2->val){
        node3 = node2->next;
        free(node2);
        node1->next = node3;
      } else {
        node1 = node1->next;
      }
    }
    return head;
}