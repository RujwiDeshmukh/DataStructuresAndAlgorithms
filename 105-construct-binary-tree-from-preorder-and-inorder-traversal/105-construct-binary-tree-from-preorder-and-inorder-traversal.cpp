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
    
    TreeNode* construct(vector<int>& preorder,map<int,int>&mp,int start,int end,int &preIndex)
    {
        //preIndex we are passing by reference as we want to retain its value
        //for every recursive call
        if(start>end)
        {
            return NULL;
        }
        
        //Create Node
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int currentIndex = mp[preorder[preIndex]];
        preIndex++;
        
        root->left = construct(preorder,mp,start,currentIndex-1,preIndex);
        root->right = construct(preorder,mp,currentIndex+1,end,preIndex);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        int preIndex=0;
        return construct(preorder,mp,0,inorder.size()-1,preIndex);
    }
};