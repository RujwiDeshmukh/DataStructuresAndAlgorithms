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
    
    TreeNode* BSTtoGST(TreeNode* root, int &sum)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        //first need to visit all the right nodes
        //then process the root node
        //modify the value of the root node
        //then visit all the left nodes
        BSTtoGST(root->right,sum);
        //passing by refernce as we want to hold the value of the node
        sum += root->val;
        root->val = sum;
        
        BSTtoGST(root->left,sum);
        
        return root;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
       return BSTtoGST(root,sum);
    }
};