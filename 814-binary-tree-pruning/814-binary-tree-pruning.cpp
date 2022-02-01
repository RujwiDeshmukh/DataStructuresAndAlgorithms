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
    TreeNode* pruneTree(TreeNode* root) {
        
        //here we dont have any problem with inbetween node having zero value
        //we are checking those nodes only having value zero and both childs as NULL
        
        if(root==NULL)
        {
            return NULL;
        }
        
        //here we are performing postorder as after zero , one can be encountered
        
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        //now process the node
        
        if(root->val==0 && root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        
        return root;
    }
};