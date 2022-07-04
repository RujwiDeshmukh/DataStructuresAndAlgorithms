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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lesser = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        ListNode* lesser_head = lesser;
        ListNode* greater_head = greater;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                lesser->next = new ListNode(head->val);
                lesser = lesser->next;
            }
            else
            {
                greater->next = new ListNode(head->val);
                greater = greater->next;
            }
            
            head=head->next;
        }
        
        lesser->next = greater_head->next;
        
        return lesser_head->next;
    }
};