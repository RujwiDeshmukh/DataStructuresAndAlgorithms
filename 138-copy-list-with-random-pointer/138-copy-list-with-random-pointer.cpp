/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* dummyNode = new Node(1000001);
        Node* runner = dummyNode;
        Node* current = head;
        //storing oldNode and newNode references
        unordered_map<Node*,Node*>mp;
        
        //copying list with next pointer only
        while(current != NULL)
        {
            Node* newNode = new Node(current->val);
            runner->next = newNode;
            mp[current] = newNode;
            current = current->next;
            runner = runner->next;
        }
        
        current = head;
        runner = dummyNode->next;
        
        //here we are setting random pointers
        //as that are already setted in original list
        while(current != NULL)
        {
            if(current->random != NULL)
            {
                runner->random = mp[current->random];
            }
            
            runner = runner->next;
            current = current->next;
        }
        
        return dummyNode->next;
    }
};