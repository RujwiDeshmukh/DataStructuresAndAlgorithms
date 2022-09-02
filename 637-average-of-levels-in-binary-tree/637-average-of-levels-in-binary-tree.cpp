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
    vector<double> averageOfLevels(TreeNode* root) {
           
        vector<double>ans;
        
            queue<TreeNode*>q;
            q.push(root);
            int sum=0;
            int count=0;
        
           while(!q.empty())
           {
               double sum = 0;
               int n = q.size();
               
               for(int i=0;i<n;i++)
               {
                    TreeNode* node =  q.front();
                    q.pop();
                   
                    sum += node->val;
                   
                    if(node->left != NULL)
                    {
                        q.push(node->left);
                    }
                   
                   if(node->right != NULL)
                    {
                        q.push(node->right);
                    }
               }
               
               double avg = (double)sum/n;
               ans.push_back(avg);
               
           }
        
          return ans;
    }
};