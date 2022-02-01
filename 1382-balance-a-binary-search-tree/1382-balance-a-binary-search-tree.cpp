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
    
    void inOrder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
        {
            return ;
        }
        
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    
    TreeNode* constructTree(vector<int>& ans,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int mid = (start+end)/2;
        
        TreeNode* root = new TreeNode(ans[mid]);
        
        root->left = constructTree(ans,start,mid-1);
        root->right = constructTree(ans,mid+1,end);
        
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);
        int size = ans.size()-1;
        
      
        return constructTree(ans,0,size);
        
        
    }
};