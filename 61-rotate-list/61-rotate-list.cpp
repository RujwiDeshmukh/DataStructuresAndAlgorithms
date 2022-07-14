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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k==0)
        {
            return head;
        }
        
        ListNode* temp=head;
        int length=0;
        
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
    
       if(k>length)
       {
          k = k%length;
       }

        
        while(k>0)
        {
           ListNode* last = head;
            
            while(last->next->next != NULL)
            {
                last = last->next;
            }
            
            ListNode *t = new ListNode(last->next->val);
            last->next = NULL;
            t->next = head;
            head = t;
            k--;
        }
        
        return head;
    }
};