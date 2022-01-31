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
    
    TreeNode* constructTree(vector<int>& preorder,int &preIndex,int boundary)
    {
        //when array is over
        if(preIndex >= preorder.size())
        {
            return NULL;
        }
        
        if(preorder[preIndex] >= boundary)
        {
            return NULL;
        }
        
        //Construct Node
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        //updating boundary for each recursive call
        root->left = constructTree(preorder,preIndex,root->val);
        root->right = constructTree(preorder,preIndex,boundary);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;
        return constructTree(preorder,preIndex,10000);
    }
};