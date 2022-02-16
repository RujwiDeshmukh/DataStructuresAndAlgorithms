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
    
    ListNode* pairSwap(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        //in this question we are just changing links not updating
        //or swapping values
        
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        
        ListNode* tempList = pairSwap(head->next->next);
        
        firstNode->next = tempList;
        secondNode->next = firstNode;
        
        
        return secondNode;
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
        
       return pairSwap(head);
    }
};