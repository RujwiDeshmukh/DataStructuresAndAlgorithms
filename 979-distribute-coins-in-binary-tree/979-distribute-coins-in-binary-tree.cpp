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
    
    int ans=0;
    int findmoves(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=findmoves(root->left);  // excess left
        int r=findmoves(root->right); // excess right
        ans+=abs(l)+abs(r); // excess value is no of moves
        return root->val+l+r-1;  // excess value
        
    }
    
    
    int distributeCoins(TreeNode* root) {
        
        findmoves(root);
        return ans;
    }
};