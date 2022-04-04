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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int cnt=1;
        ListNode* temp = head;
        
       while(cnt < k)
        {
           //cout<<cnt<<endl;
               //cout<<temp->val<<endl;
            temp = temp->next;
           cnt++;
        }
        
        ListNode* fast = temp;
        ListNode* slow = head;
        
        //traversing the n-k remaining nodes till last node
        //start from beginning so that to reach n-kth node from the starting point
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        swap(slow->val,temp->val);
        
        return head;
    }
};