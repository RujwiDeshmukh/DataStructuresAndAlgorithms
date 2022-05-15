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
    
    
    //https://leetcode.com/problems/deepest-leaves-sum/discuss/1152947/Deepest-Leaves-Sum-or-Short-and-Easy-Solutions-w-Explanation-or-BFS-and-DFS-Approach
    
    void deepLeavesSum(TreeNode* root,int &deepest,int &sum,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
           if(depth > deepest)
           {
               sum = root->val;
               deepest = depth;
           }
            
            else if(depth == deepest)
            {
                //same depth is encountered again then
                //add to sum only
                sum += root->val;
            }
        }
        
        deepLeavesSum(root->left,deepest,sum,depth+1);
        deepLeavesSum(root->right,deepest,sum,depth+1);
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int deepest=0, sum=0;
        
        deepLeavesSum(root,deepest,sum,0);
        
        return sum;
    }
    
    
};