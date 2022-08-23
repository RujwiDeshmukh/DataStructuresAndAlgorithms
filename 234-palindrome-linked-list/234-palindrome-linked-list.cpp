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
    bool isPalindrome(ListNode* head) {
        
        ListNode* ptr = head;
        string str = "", st="";
        
        while(ptr != NULL)
        {
            str += to_string(ptr->val);
            ptr = ptr->next;
        }
        
        st = str;
     
        reverse(str.begin(),str.end());
        
        if(str==st)
        {
            return true;
        }
        
        return false;
    }
};