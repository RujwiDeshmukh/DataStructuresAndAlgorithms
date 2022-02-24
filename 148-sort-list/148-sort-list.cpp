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
    
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                curr->next = l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            
            curr=curr->next;
        }
        
        while(l1!=NULL)
        {
            curr->next=l1;
            l1=l1->next;
            curr=curr->next;
        }
        
        while(l2!=NULL)
        {
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        //if list has single node or 0 node
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        //find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            temp = slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        
        temp->next=NULL;
        
        ListNode* firstHalf=sortList(head);
        ListNode* secondHalf=sortList(slow);
        
       return mergeList(firstHalf,secondHalf);
    }
};