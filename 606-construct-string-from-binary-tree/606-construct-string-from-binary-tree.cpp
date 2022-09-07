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
    string tree2str(TreeNode* root) {
        
        string ans = to_string(root->val);
        
        if(root->left != NULL)
        {
            ans += "(";
            //as tree2str is returning value it should be added to
            //ans evrytime
            ans += tree2str(root->left);
            ans += ")";
        }
        
        if(root->right != NULL)
        {
            if(root->left==NULL)
            {
                ans += "()";
            }
                ans += "(";
                ans  += tree2str(root->right);
                ans += ")";
        }
        
        return ans;
    }
};