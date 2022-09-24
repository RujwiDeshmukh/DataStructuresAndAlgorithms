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
    
    void sumPaths(TreeNode* root,int targetSum,int sum,vector<int>& ans,
                                 vector<vector<int>>& res)
    {
        if(root==NULL)
        {
            return ;
        }
        
        sum += root->val;
        ans.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL && sum==targetSum)
        {
            res.push_back(ans);
            ans.pop_back();
            return ;
        }
        
        sumPaths(root->left,targetSum,sum,ans,res);
        sumPaths(root->right,targetSum,sum,ans,res);
        ans.pop_back();
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          vector<int>ans;
          vector<vector<int>>res;
          int sum=0;
        
          sumPaths(root,targetSum,sum,ans,res);
        
          return res;
    }
};