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
    
    void rightSideView(TreeNode* root,int level,set<int>& st,vector<int>& ans)
 {
     if(root==NULL)
     {
         return ;
     }
     
     if(st.find(level) == st.end())
     {
         st.insert(level);
         ans.push_back(root->val);
     }
     
     rightSideView(root->right,level+1,st,ans);
    rightSideView(root->left,level+1,st,ans);
 }

    
    vector<int> rightSideView(TreeNode* root) {
     set<int>st;
   vector<int>ans;
   rightSideView(root,1,st,ans);
   return ans;
    }
};