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
bool hasCycle(struct ListNode *head) {
	if(head == NULL) return false;
    struct ListNode *node1, *node2;
    node1 = node2 = head;
    while(node1 != NULL && node2 != NULL){
    	node1 = node1->next;
    	node2 = node2->next;
    	if(node2 != NULL) node2 = node2->next;
    	else return false;

    	if(node1 == node2) return true;
    }
    return false;
}