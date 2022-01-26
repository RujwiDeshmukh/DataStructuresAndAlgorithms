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
    
    int calcDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int leftDepth = 1+calcDepth(root->left);
        int rightDepth = 1+calcDepth(root->right);
        
        return max(leftDepth,rightDepth)+1;
    }
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        int leftDepth = calcDepth(root->left);
        cout<<leftDepth<<endl;
        int rightDepth = calcDepth(root->right);
        cout<<rightDepth<<endl;
        
        if(leftDepth == rightDepth)
        {
            return root;
        }
        
        else if(leftDepth > rightDepth)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
          return lcaDeepestLeaves(root->right);
        }
    }
};