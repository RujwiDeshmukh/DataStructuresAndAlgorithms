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
    
    bool isValid(TreeNode* root,long long int & prev)
    {
        if(root==NULL)
        {
            return true;
        }
        
        bool leftAns = isValid(root->left,prev);
        
        //As we are traversing whole left side first then prev cant ever be greater than current element, if its then it cant be bst
        
        if(root->val <= prev)
        {
            return false;
        }
        
        prev = root->val;
        
        bool rightAns = isValid(root->right,prev);
        
        return leftAns && rightAns;
    }
    
    bool isValidBST(TreeNode* root) {
        
        long long int prev = -99999999999;
        return isValid(root,prev);
    }
};