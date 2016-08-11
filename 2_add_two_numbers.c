/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* result = NULL;
	int ten = 0;
	struct ListNode* previous;
	int flag = true;
	while(l1 != NULL && l2 != NULL){
		if(flag == true){
			flag = false;
			result = malloc(sizeof(struct ListNode));
			result->next = NULL;
			result->val = (l1->val + l2->val + ten) % 10;
			ten = (l1->val + l2->val + ten) >= 10 ? 1:0;
			previous = result;
		} else {
			struct ListNode* nextBit = malloc(sizeof(struct ListNode));
			previous->next = nextBit;
			nextBit->val = (l1->val + l2->val + ten) % 10;
			nextBit->next = NULL;
			ten = (l1->val + l2->val + ten) >= 10 ? 1:0;
			previous = nextBit;
		}
		
		l1 = l1->next;
		l2 = l2->next;
	}

	while(l1 != NULL){
		if(flag == true){
			flag = false;
			result = malloc(sizeof(struct ListNode));
			result->val = (l1->val + ten) % 10;
			result->next = NULL;
			ten = (l1->val + ten) >= 10 ? 1:0;
			previous = result;
		} else {
			struct ListNode* nextBit = malloc(sizeof(struct ListNode));
			previous->next = nextBit;
			nextBit->val = (l1->val + ten) % 10;
			nextBit->next = NULL;
			ten = (l1->val + ten) >= 10 ? 1:0;
			previous = nextBit;
		}
		
		l1 = l1->next;
	}

	while(l2 != NULL){
		if(flag == true){
			flag = false;
			result = malloc(sizeof(struct ListNode));
			result->next = NULL;
			result->val = (l2->val + ten) % 10;
			ten = (l2->val + ten) >= 10 ? 1:0;
			previous = result;
		} else {
			struct ListNode* nextBit = malloc(sizeof(struct ListNode));
			previous->next = nextBit;
			nextBit->val = (l2->val + ten) % 10;
			nextBit->next = NULL;
			ten = (l2->val + ten) >= 10 ? 1:0;
			previous = nextBit;
		}	

		l2 = l2->next;
	}

	if(ten == 1){
		struct ListNode* nextBit = malloc(sizeof(struct ListNode));
		previous->next = nextBit;
		nextBit->val = 1;
		nextBit->next = NULL;
	}
	return result;
}