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
void sumPath(TreeNode* root,int targetSum,int value,vector<vector<int>>&ans,vector<int>& res)
{
    if(root==NULL)
    {
        return;
    }
    
     res.push_back(root->val);
    if(root->left==NULL && root->right==NULL && value+root->val==targetSum)
    {
        ans.push_back(res);
        res.pop_back();
        return;
    }
    
    sumPath(root->left,targetSum,value+root->val,ans,res);
    sumPath(root->right,targetSum,value+root->val,ans,res);
    res.pop_back();
    
}
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        sumPath(root,targetSum,0,ans,res);
        return ans;
    }
};