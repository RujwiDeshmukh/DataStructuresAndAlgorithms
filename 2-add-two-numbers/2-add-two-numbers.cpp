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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *temp =res;
        int sum=0;
        int carry=0;
        
        while(l1 != NULL || l2 != NULL)
        {
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;
            
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            
            temp->next = new ListNode(sum);
            if(l1 !=NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            temp = temp->next;
        }
        
        if(carry)
        {
            temp->next = new ListNode(carry);
        }
        
        return res->next;
    }

};