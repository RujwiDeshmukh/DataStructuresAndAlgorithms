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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int prev;
        
        while(!q.empty())
        {
            int size = q.size();
            
            if(level%2==0)
            {
                prev = INT_MIN;
            }
            else
            {
                prev = INT_MAX;
            }
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(level%2==0)
                {
                    if(((node->val)%2)==0 || prev >= node->val)
                    {
                        return false;
                    }
                }
                else
                {
                    if(((node->val)%2)!=0 || prev <= node->val)
                    {
                        return false;
                    }
                }
                
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
                
                prev = node->val;
            }
            
         level++;
        }
        
        return true;
    }
};