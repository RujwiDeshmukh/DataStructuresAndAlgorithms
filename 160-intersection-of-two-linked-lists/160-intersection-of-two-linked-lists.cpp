/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        int len1=0, len2=0;
        int d=0;
        
        while(temp1 != NULL)
        {
            temp1 = temp1->next;
            len1++;
        }
        
        while(temp2 != NULL)
        {
            temp2 = temp2->next;
            len2++;
        }
        
        if(len1 > len2)
        {
            d=len1-len2;
            temp1 = headA;
            temp2 = headB;
        }
        else
        {
            d=len2-len1;
            temp1 = headB;
            temp2= headA;
        }
        
        //might be possible that the one is empty and other one is traversed
        //till last so temp1 now will point to NULL
        while(d != 0)
        {
            temp1 = temp1->next;
            d--;
        }
        
        //so here we checking if both are not null
        //as it is possibility that 2 LL are not intersecting
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};