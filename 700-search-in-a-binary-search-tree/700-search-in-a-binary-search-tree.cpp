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
    TreeNode* searchBST(TreeNode* root, int val) {
        
          TreeNode* curr = root;
          TreeNode* ans = NULL;
        
          while(curr != NULL)
          { 
              
          if(curr->val == val)
          {
              ans = curr;
              return ans;
          }
        
          else if(curr->val < val)
          {
              curr = curr->right;
          }
         else
          {
              curr = curr->left;
          }
              
         }
        return ans;
    }
};