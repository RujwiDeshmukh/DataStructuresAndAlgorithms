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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
          queue<pair<TreeNode*,pair<int,int>>>q;
          q.push({root,{0,0}});
          
          map<int,map<int,multiset<int>>>mp;
        
          while(!q.empty())
          {
              auto curr = q.front();
              q.pop();
              
              TreeNode* node = curr.first;
              int level = curr.second.first;
              int verticle = curr.second.second;
              
              mp[verticle][level].insert(node->val);
              
              if(node->left != NULL)
              {
                  q.push({node->left,{level+1,verticle-1}});
              }
              
              if(node->right != NULL)
              {
                  q.push({node->right,{level+1,verticle+1}});
              }
          }
        
         vector<vector<int>>ans;
        
          for(auto p : mp)
          {
              vector<int>col;
              for(auto q : p.second)
              {
                  col.insert(col.end(),q.second.begin(),q.second.end());
              }
              
              ans.push_back(col);
          }
        
        return ans;
    }
};