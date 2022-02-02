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
    
    pair<int,int>maxMoney(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        
        pair<int,int>left = maxMoney(root->left);
        pair<int,int>right = maxMoney(root->right);
        
    int rootHouseRobbed = root->val + left.second + right.second;
    int rootHouseNotRobbed = max(left.first,left.second) + max(right.first,right.second);
        
       /* pair<int,int>ans;
        
        ans.first = rootHouseRobbed;
        ans.second = rootHouseNotRobbed;
        
        return ans;*/
        
        return {rootHouseRobbed, rootHouseNotRobbed};
        
    }
    
    int rob(TreeNode* root) {
        
        
        //here we are performing postorder first will move to extreme left and extreme right
        //then will process the node
         pair<int,int>result = maxMoney(root);
        //first int is housRobbed, second is houseNotRobbed
        
        return max(result.first,result.second);
    }
};