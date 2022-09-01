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
    
    void countNodes(TreeNode* root,int value,int & count)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->val >= value)
        {
            value = max(value,root->val);
            count++;
        }
        
        countNodes(root->left,value,count);
        countNodes(root->right,value,count);
        
    }
    
    
    int goodNodes(TreeNode* root) {
        
        int count=0;
        countNodes(root,root->val,count);
        return count;
        
    }
};