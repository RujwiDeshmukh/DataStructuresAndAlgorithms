/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        //here we have to perform steps level wise 
        //so we are going to apply level order traversal
        
        if(root==NULL)
        {
            return root;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
           int size = q.size();
            //here we are defining previous for every level
            //no 2 levels are connected with each other
            Node* prev = NULL;
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(prev != NULL)
                {
                    prev->next = temp;
                }
                
                prev=temp;
                
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
            //here previous will be the last element present in the current level
            prev->next=NULL;
        }
        
        return root;
    }
};