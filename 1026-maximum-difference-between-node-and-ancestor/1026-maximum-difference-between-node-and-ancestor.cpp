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
    
    int findmax(TreeNode* root,int maxi,int mini)
    {
        if(root==NULL)
        {
           // cout<<maxi<<" "<<mini<<endl;
            return (maxi-mini);
        }
        maxi=max(root->val,maxi);   // UPDATE MAX
        mini=min(root->val,mini);   // UPDATE MIN
        int l=findmax(root->left,maxi,mini);   
        int r=findmax(root->right,maxi,mini);
        return max(l,r);           // TRAVERSE BOTH SIDES AND RETURN MAX AS ANS
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN,mini=INT_MAX;
       int ans= findmax(root,maxi,mini);
        return ans;
    }
};