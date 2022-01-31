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
    
    TreeNode* constructTree(vector<int>& postorder,unordered_map<int,int>&mp, int start,int end,int & postIndex)
    {
        if(start>end)
        {
            return NULL;
        }
        
        //Create Node by 
        TreeNode* root = new TreeNode(postorder[postIndex]);
        //finding the index from inorder as inorder is populated in map
        int currentIndex = mp[postorder[postIndex]];
        postIndex--;
        
    root->right = constructTree(postorder,mp,currentIndex+1,end,postIndex);
    root->left = constructTree(postorder,mp,start,currentIndex-1,postIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        //Populate the inorder traversal into map
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        int postIndex = postorder.size()-1;
        
        return constructTree(postorder,mp,0,inorder.size()-1,postIndex);
    }
};