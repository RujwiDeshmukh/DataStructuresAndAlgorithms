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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        
        while(h1 != NULL && h2 != NULL)
        {
            if(h1->val > h2->val)
            {
                ptr->next = h2;
                h2 = h2->next;
            }
            else
            {
                ptr->next = h1;
                h1 = h1->next;
            }
            
            ptr=ptr->next;
        }
        
        while(h1 != NULL)
        {
            ptr->next =h1;
            h1 = h1->next;
            ptr = ptr->next;
        }
        
        while(h2 != NULL)
        {
            ptr->next = h2;
            h2 = h2->next;
            ptr=ptr->next;
        }
        
        return dummy->next;
    }
};