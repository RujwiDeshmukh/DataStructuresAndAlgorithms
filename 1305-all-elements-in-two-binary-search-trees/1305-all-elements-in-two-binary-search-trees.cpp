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
    
    void inOrder(TreeNode* root,vector<int> &v)
    {
        if(root == NULL)
        {
            return ;
        }
        
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      
        vector<int>v;
        vector<int>tree1,tree2;
        inOrder(root1,tree1);
        inOrder(root2,tree2);
        
        int n = tree1.size();
        int m = tree2.size();
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(tree1[i]<=tree2[j])
            {
                v.push_back(tree1[i]);
                i++;
            }
            else
            {
              v.push_back(tree2[j]);   
              j++;
            }
        }
        
        while(i<n)
        {
            v.push_back(tree1[i]);
            i++;
        }
        
        while(j<m)
        {
            v.push_back(tree2[j]);
            j++;
        }
        
        
        return v;
    }
};