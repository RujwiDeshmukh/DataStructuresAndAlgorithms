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
    
    bool isPresent(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        
         if(subRoot == NULL || root == NULL || root->val != subRoot->val)
        {
            return false;
        }
        
       bool left =  isPresent(root->left,subRoot->left);
       bool right = isPresent(root->right,subRoot->right);
     
      return left && right;
        
    }

    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == NULL || root == NULL)
        {
            return false;
        }
        
        return isPresent(root,subRoot) || isSubtree(root->left,subRoot)
            || isSubtree(root->right,subRoot);
    }
};