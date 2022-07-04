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
        
       // https://leetcode.com/problems/partition-list/discuss/1157903/Simple-1-Pass-Partition-w-Two-Pointers-Explained-or-Beats-100
        
        ListNode* lesser = new ListNode(-1);
        ListNode* greater = new ListNode(-1);
        ListNode* lesser_head = lesser;
        ListNode* greater_head = greater;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                lesser->next = head;
                lesser = lesser->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            
            head=head->next;
        }
        
        greater->next = NULL;
        lesser->next = greater_head->next;
        
        return lesser_head->next;
    }
};