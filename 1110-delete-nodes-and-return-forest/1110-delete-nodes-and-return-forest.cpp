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
    
    TreeNode* deleteNodes(TreeNode* root,set<int>& st,vector<TreeNode*>& ans)
    {
         if(root==NULL)
         {
             return NULL;
         }
        
        //perform postorder traversal now
        //we need to set values as how will we set NULL value
        root->left = deleteNodes(root->left,st,ans);
        root->right = deleteNodes(root->right,st,ans);
        
        if(st.find(root->val) != st.end())
        {
            //we found the node that was supposed to be deleted
            //now we need to store its left and right
            
            if(root->left != NULL)
            {
                ans.push_back(root->left);
            }
            
            if(root->right != NULL)
            {
                ans.push_back(root->right);
            }
            
            return NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //we have to delete the node
        //if we delete the node as we do in preorder traversal
        //then we have to maintain its child then only
        //so we do that in postorder traversal
        
        vector<TreeNode*>ans;
        set<int>st;
        
        for(int i=0;i<to_delete.size();i++)
        {
            st.insert(to_delete[i]);
        }
        
        deleteNodes(root,st,ans);
        //we have to add this condition as we wont add root now 
        //as it wont be processed as it is not inclueded in set
        
        if(st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        
        return ans;
    }
};