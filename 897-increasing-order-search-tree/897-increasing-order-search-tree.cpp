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
    
    void inOrder(TreeNode* root,TreeNode* &ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        inOrder(root->left,ans);
        //we have to create new node 
        //ans->right = root; here root is only ptr 
        //so it wont set value
        //as we want to create new tree so everytime we have to create new node
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        inOrder(root->right,ans);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* res;
        TreeNode* ans = new TreeNode(-1);
         res = ans;
        inOrder(root,ans);
        return res->right;
    }
};