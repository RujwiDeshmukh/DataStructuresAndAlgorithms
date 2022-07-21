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
        
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        
        ListNode *slow=head, *fast=head, *entry=head; 
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            //either this will be true
            //or either upper condition will be false
            //so have to check which one is failing
            if(slow==fast)
            {
               break;
            }
        }
        
        if(fast == NULL || fast->next == NULL)
        {
            return NULL;
        }
        
        while(slow != entry){
                    entry=entry->next;
                    slow=slow->next;
                }
       return entry;
    }
};