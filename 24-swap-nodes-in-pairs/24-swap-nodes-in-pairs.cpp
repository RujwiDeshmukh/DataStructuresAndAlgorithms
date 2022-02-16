/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* swapNodes(ListNode* head)
    {
        
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* temp = head;
        
        int value = temp->val;
        
        if(temp->next != NULL)
        {
            temp->val = temp->next->val;
            temp->next->val=value;
            temp = temp->next->next;
        }
        else
        {
         return NULL;   
        }
        
        swapNodes(temp);
        
        return head;
    }
    
    ListNode* swapPairs(ListNode* head) {
          
        if(head==NULL)
        {
            return head;
        }
        
        if(head->next==NULL)
        {
            return head;
        }
        
        return swapNodes(head);
    }
};