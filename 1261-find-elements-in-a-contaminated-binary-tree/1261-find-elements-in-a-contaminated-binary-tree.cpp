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
class FindElements {
    
    private:
    unordered_set<int>st;
    
public:
    
    void recover(TreeNode* root,int value)
    {
        if(root==NULL)
        {
            return ;
        }
        
        //restoring original value
        root->val = value;
        st.insert(value);
        recover(root->left,2*value+1);
        recover(root->right,2*value+2);
    }
    
    FindElements(TreeNode* root) {
        //make the modified tree to original one
        recover(root,0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */