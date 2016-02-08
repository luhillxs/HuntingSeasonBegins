/*
    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2){
            return NULL;
        }
        else if(!l1||!l2){
            return !l2? l1:l2;
        }
        
        ListNode *ptr1,*ptr2,*temp,*head;
        ListNode dummy(0);
        ptr1 = l1;
        ptr2 = l2;
        temp = &dummy;
        
        
        while(ptr1&&ptr2){
            if(ptr1->val<=ptr2->val){
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            }
            else if(ptr2->val<ptr1->val){
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
        }
        
        if(!ptr1&&!ptr2){
            return dummy.next;
        }
        if(ptr1){
            temp->next = ptr1;
        }
        else if(ptr2){
            temp->next = ptr2;
        }
        
        return dummy.next;
        
    }
};