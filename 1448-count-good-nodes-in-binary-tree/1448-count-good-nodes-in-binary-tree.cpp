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
    //performing preorder as we want to keep track of maximum value till now
    int countGoodNodes(TreeNode* root,int maxi,int& count)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->val >= maxi)
        {
            count++;
            maxi = max(maxi,root->val);
        }
        
        countGoodNodes(root->left,maxi,count);
        countGoodNodes(root->right,maxi,count);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
    
    int maxi =INT_MIN;
        int count=0;
       return countGoodNodes(root,maxi,count);
    }
};