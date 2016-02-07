/*
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,

  Given 1->1->2, return 1->2.

  Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *ptr_temp,*ptr_cur;
        ptr_temp = head;
        ptr_cur = head->next;

        while(ptr_cur){
            if(ptr_cur->val!=ptr_temp->val){
                ptr_temp->next = ptr_cur;
                ptr_temp = ptr_temp->next;
            }
            else{
                ptr_temp->next = ptr_cur->next;
            }
            ptr_cur = ptr_cur->next;
        }

        return head;

    }
};
