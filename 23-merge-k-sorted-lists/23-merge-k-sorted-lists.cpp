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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        ListNode* curr=NULL;
        
        for(auto list : lists)
        {
            curr = list;
            
            while(curr != NULL)
            {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        
        while(!pq.empty())
        {
            int val = pq.top();
            pq.pop();
            ListNode* curr = new ListNode(val);
            temp->next = curr;
            temp = temp->next;
        }
        
        return ans->next;
    }
};