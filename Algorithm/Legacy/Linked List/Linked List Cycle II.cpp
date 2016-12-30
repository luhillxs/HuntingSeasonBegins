/*
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

    Note: Do not modify the linked list.

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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){
            return NULL;
        }
        ListNode *ptr1,*ptr2;
        ptr1 = head;
        ptr2 = head;
        while(ptr1&&ptr2&&ptr2->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2){
                break;
            }
            if(!ptr1||!ptr2||!ptr2->next){
                return NULL;
            }
        }
        ptr1 = head;
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};