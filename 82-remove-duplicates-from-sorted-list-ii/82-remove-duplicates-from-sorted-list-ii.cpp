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
    ListNode* deleteDuplicates(ListNode* head) {
        
        map<int,int>mp;
        //it will store the node value and its count
        
        ListNode* temp = head;
        ListNode* ans = new ListNode(-1000);
        
        while(temp != NULL)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        
        temp=ans;
        
        for(auto m : mp)
        {
            if(m.second==1)
            {
                ListNode* ptr = new ListNode(m.first);
                temp->next = ptr;
                temp=temp->next;
            }
        }
        
        return ans->next;
    }
};