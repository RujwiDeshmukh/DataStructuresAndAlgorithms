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
    
    void sumLeaves(TreeNode* root,int &ans,bool isLeaf)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->left==NULL && root->right==NULL && isLeaf==true)
        {
            ans += root->val;
        }
        
        sumLeaves(root->left,ans,true);
        sumLeaves(root->right,ans,false);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        int ans=0;
        sumLeaves(root,ans,false);
        return ans;
        
    }
};