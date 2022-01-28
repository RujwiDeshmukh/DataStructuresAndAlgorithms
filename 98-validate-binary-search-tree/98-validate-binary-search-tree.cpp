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
    
    bool isValid(TreeNode* root, long long & prev)
    {
        //Perform InOrder Traversal
        if(root==NULL)
        {
            return true;
        }
        
        bool leftAns = isValid(root->left,prev);
        
        //process the node
        
        if(root->val <= prev)
        {
            return false;
        }
        
        prev = root->val;
        
        bool rightAns = isValid(root->right,prev);
        
        return leftAns && rightAns;
        
        
    }
    
    bool isValidBST(TreeNode* root) {
        long long prev = -99999999999;
        return isValid(root, prev);
    }
};