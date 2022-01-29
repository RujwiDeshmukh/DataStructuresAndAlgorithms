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
    
    //here we are performing level order traversal
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
        {
            return NULL;
        }
     
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        //q has treenode and index as a pair
        q.push({root,0});
        
        while(!q.empty())
        {
            int size= q.size();
            int first=0, last=0;
            int curr_idx=0;
            int mini = q.front().second;
            //using for loop as we want to process the whole level at once
            
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                int index = curr.second;
                TreeNode* currNode = curr.first;
                //modifying  index while processing that level
                curr_idx = index - mini; 
                
                if(i==0)
                {
                    first = curr_idx;
                }
                
                if(i==size-1)
                {
                    last = curr_idx;
                }
                
                if(currNode->left != NULL)
                {
                    q.push({currNode->left,2*curr_idx+1});
                }
                
                if(currNode->right != NULL)
                {
                    q.push({currNode->right,2*curr_idx+2});
                }
            }
            
            ans = max(ans, last-first+1);
        }
        
        return ans;
    }
};