/*
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

  For example,
  Given 1->2->3->3->4->4->5, return 1->2->5.
  Given 1->1->1->2->3, return 2->3.
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
        ListNode tempHead = ListNode(0);
        ListNode *ptr_cur,*ptr_temp;
        ptr_cur = head;
        ptr_temp = &tempHead;
        ptr_temp->next = head;
        while(ptr_cur&&ptr_cur->next){
            if(ptr_cur->val!=ptr_cur->next->val){
                ptr_temp = ptr_cur;
                ptr_cur = ptr_cur->next;
            }
            else{
                int temp = ptr_cur->val;
                ptr_cur = ptr_cur->next;
                while(ptr_cur&&ptr_cur->val == temp){
                    ptr_cur = ptr_cur->next;
                }
                ptr_temp->next = ptr_cur;
            }
        }
        head = tempHead.next;
        return head;

    }
};
