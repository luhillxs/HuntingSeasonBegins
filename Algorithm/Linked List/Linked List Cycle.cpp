/*
    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next){
            return false;
        }
        ListNode *ptr1,*ptr2;
        ptr1 = head;
        ptr2 = head;
        
        while(ptr1&&ptr2&&ptr2->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1==ptr2){
                return true;
            }
        }
        return false;
    }
};