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
class Solution {
public:
    
    bool ifTarget(TreeNode* root, int sum,unordered_set<int>& st)
    {
        //as it is reaching up to null means we have not found that value
        //we can get the value from either left or right branch
        if(root==NULL)
        {
            return false;
        }
        
        if(st.find(sum-root->val) != st.end())
        {
            return true;
        }
        
        st.insert(root->val);
        bool left = ifTarget(root->left,sum,st);
        bool right = ifTarget(root->right,sum,st);
        
        return left || right;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        unordered_set<int>st;
        return ifTarget(root,k,st);
    }
};