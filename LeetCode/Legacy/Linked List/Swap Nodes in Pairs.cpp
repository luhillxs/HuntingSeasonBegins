/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL||head->next == NULL){
            return head;
        }
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;
        head = ptr2;
        while(ptr1!=NULL){
            // swap(ptr1->val,ptr2->val);
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            
            ListNode *ptrtemp = ptr1;
            
            ptr1 = ptr1->next;
            if(ptr1!=NULL&&ptr1->next!=NULL){
                ptr2 = ptr1->next; 
                ptrtemp->next = ptr2;
            }
            else{
                break;
            }
        }
        return head;
    }
    
    // void swap(int &a, int &b){
    //     int temp;
    //     temp = a;
    //     a = b;
    //     b = temp;
    // }
};