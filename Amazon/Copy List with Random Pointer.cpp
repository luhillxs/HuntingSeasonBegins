/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;        
        
        RandomListNode *res;
        RandomListNode *cur = head;
        
        // insert new nodes
        while(cur != NULL){
            RandomListNode *temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        
        // apply random pointer
        cur = head;
        while(cur != NULL){
            RandomListNode *temp = cur->next;
            if(cur->random != NULL)
                temp->random = cur->random->next;
            else
                temp->random = NULL;
            cur = temp->next;
        }
        
        // disconnect 2 linked lists
        cur = head;
        res = cur->next;
        while(cur != NULL){
            RandomListNode *temp = cur->next;
            cur->next = temp->next;
            if(cur->next != NULL)
                temp->next = cur->next->next;
            cur = cur->next;
        }
        
        return res;
    }
};