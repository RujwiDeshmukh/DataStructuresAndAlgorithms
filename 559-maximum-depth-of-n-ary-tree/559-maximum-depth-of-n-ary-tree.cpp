/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int ans=0;
        
        for(Node *t : root->children)
        {
            int h = maxDepth(t);
            ans = max(ans,h);
        }
        
        return ans+1;
    }
};