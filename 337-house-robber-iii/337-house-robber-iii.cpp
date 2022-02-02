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
    
    int maxMoney(TreeNode* root,unordered_map<TreeNode*,int>& mp)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(mp.find(root) != mp.end())
        {
            return mp[root];
        }
        
        //include the root node
        int consider = root->val;
        
        if(root->left != NULL)
        {
            consider += maxMoney(root->left->left,mp)+maxMoney(root->left->right,mp);
        }
        
        if(root->right != NULL)
        {
            consider += maxMoney(root->right->left,mp)+maxMoney(root->right->right,mp);
        }
        
        //not include that node
        int notConsider = maxMoney(root->left,mp)+maxMoney(root->right,mp);
        
        mp[root] =  max(consider,notConsider);
        
        return mp[root];
        
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode* ,int>mp;
        return maxMoney(root,mp);
    }
};