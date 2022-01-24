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
    
void dfs(TreeNode* root, int level,map<int,vector<int>>& mp)
    {
         if(root == NULL)
         {
             return ;
         }
        
    mp[level].push_back(root->val);
    dfs(root->left,level+1,mp);
    dfs(root->right,level+1,mp);

    }
    
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        map<int,vector<int>>mp;
        dfs(root,0,mp);
        for(auto m : mp)
    {
        vector<int>res = m.second;
        long double sum=0;
          for(int i=0;i<res.size();i++)
          {
              sum+= res[i];
          }
        int size = res.size();
        ans.push_back(sum/size);
    }
        return ans;
    }
};