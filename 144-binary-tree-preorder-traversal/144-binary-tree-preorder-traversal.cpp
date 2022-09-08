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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        stack<TreeNode*>st;
        
        //TreeNode* curr = root;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            
            //as we want left part first will push right part
            //left part will be at the top always and can be processed first
            if(node->right != NULL)
            {
                st.push(node->right);
            }
            
            if(node->left != NULL)
            {
                st.push(node->left);
            }
        }
        return ans;
    }
};