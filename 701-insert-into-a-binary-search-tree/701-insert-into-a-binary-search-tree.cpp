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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        //bcoz everytime new node will be inserted to leaf 
        //so whenever null is encountered then we are setting value
        //as we are iterating in a pattern so first time we are getting
        //NULL then there we have to insert value for sure
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        
        if(root->val > val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        else
        {
            root->right = insertIntoBST(root->right,val);
        }
        
        return root;
        
    }
};