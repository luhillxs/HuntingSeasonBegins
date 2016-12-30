/*
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        else if (lists.size()==1){
            return lists[0];
        }
        else if(lists.size()==2){
            return mergeTwoLists(lists[0],lists[1]);
        }
        
        int size = lists.size();
        int k;
        while(size>1){
            k = (size+1)/2;
            for(int i=0;i<size/2;i++){
                lists[i] = mergeTwoLists(lists[i],lists[i+k]);
            }
            size = k;
        }
        return lists[0];
    }

private: 
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