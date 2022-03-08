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
    int pairSum(ListNode* head) {
        
        ListNode* curr = head;
        stack<int>st;
        
        while(curr != NULL)
        {
           st.push(curr->val);
           curr=curr->next;
        }
        
        curr=head;
        int count=0;
        int size=st.size();
        int maxValue=0;
        
        while(count < (size)/2)
        {
            maxValue = max(maxValue, st.top()+curr->val);
            st.pop();
            curr=curr->next;
            count++;
        }
        
        return maxValue;
    }
};