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
    
    void dfs(int level,TreeNode* root,map<int,vector<int>>& mp)
    {
        if(root == NULL)
        {
            return ;
        }
        
        mp[level].push_back(root->val);
        
        dfs(level+1,root->left,mp);
        dfs(level+1,root->right,mp);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        map<int,vector<int>>mp;
        dfs(0,root,mp);
        
        for(auto m : mp)
        {
            vector<int>num = m.second;
            int size = num.size();
            cout<<size<<endl;
            double sum=0;
            
            for(int i=0;i<size;i++)
            {
                sum += num[i];
            }
            
            double avg = (double)sum/size;
            ans.push_back(avg);
        }
        
          return ans;
    }
};