/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    //by storing the inorder traversal in vector we can iterator over vector and return the values
    //for this 
    //SC => O(N)
    //TC => O(1)
    
    stack<TreeNode*>st;
    //SC => O(H)
    //TC => O(1)
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        pushAll(topNode->right);
        return topNode->val;
    }
    
    void pushAll(TreeNode* root)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    
    bool hasNext() {
        
        if(!st.empty())
        {
            
            return true;
        }
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */