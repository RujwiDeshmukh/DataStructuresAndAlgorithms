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
    
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return 1 + max(left,right);
        
    }
    
    int sumDeepestLeaves(TreeNode* root,int maxDepth,int depth)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        if(depth == maxDepth)
        {
            return root->val;
        }
            
        int left = sumDeepestLeaves(root->left,maxDepth,depth+1);
        int right = sumDeepestLeaves(root->right,maxDepth,depth+1);
        
        return left+right;
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxDepth(root);
        return sumDeepestLeaves(root,depth,1);
    }
};