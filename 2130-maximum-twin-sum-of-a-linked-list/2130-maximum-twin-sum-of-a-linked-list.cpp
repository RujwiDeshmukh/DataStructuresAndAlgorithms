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
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout<<slow->val<<endl;
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL;

        while(head != NULL)
        {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head= nextNode;
        }
        
        return prev;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode* mid = middleNode(head);
        cout<<mid->val<<endl;
        ListNode* midNext = mid->next;
        cout<<midNext->val<<endl;
        int maxValue=0;
        mid->next=NULL;
        
        midNext = reverseList(midNext);
        cout<<midNext->val<<endl;
        
        while(midNext != NULL)
        {
           maxValue = max(maxValue,(midNext->val + head->val));
           midNext = midNext->next;
           head = head->next;
        }
        
        return maxValue;
    }
};