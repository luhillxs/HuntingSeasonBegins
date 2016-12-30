/*
    Reverse a singly linked list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return NULL;
        }
        else if (!head->next){
            return head;
        }
        else {
            ListNode* newhead = head;
            while(newhead->next){
                newhead = newhead->next;
            }
            ListNode* dummy = iterateReverse(head);
            return newhead;
        }
    }
    
    
    ListNode* iterateReverse(ListNode* cur){
        if(!cur->next){
            return cur;
        }
        ListNode* rlist = iterateReverse(cur->next);
        rlist->next = cur;
        cur->next = NULL;
        return cur;
    }
};