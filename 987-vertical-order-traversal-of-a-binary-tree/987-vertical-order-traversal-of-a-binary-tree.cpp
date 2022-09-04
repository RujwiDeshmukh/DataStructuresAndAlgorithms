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
        
       /* queue<TreeNode*>q;
        q.push(root); */
      //  it wont work as we need to maintain level and vertcle for node
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        map<int,map<int,multiset<int>>>mp;
        
        while(!q.empty())
        {
            auto value = q.front();
            q.pop();
            
            TreeNode* node = value.first;
            int level = value.second.first;
            int verticle = value.second.second;
            
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
        
        vector<vector<int>>res;
        
        for(auto m : mp)
        {
            vector<int>ans;
            for(auto st : m.second)
            {
              ans.insert(ans.end(),st.second.begin(),st.second.end()); 
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};