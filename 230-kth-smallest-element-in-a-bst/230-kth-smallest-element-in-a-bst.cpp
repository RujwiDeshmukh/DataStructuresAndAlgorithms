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
    int count=0;
    int ans=0;
    void findSmallest(TreeNode *root,int &currCount,const int k,int &result)
    {
        if(root == NULL)
        {
            return;
        }
        
        findSmallest(root->left,currCount,k,result);
        currCount++;
        
        if(currCount == k)
        {
            result = root->val;
            return;
        }
        
        findSmallest(root->right,currCount,k,result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        int count=0;
        findSmallest(root,count,k,res);
        return res;
    }
};