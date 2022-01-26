/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original==NULL)
        {
            return NULL;
        }
        
        if(original==target)
        {
            return cloned;
        }
       
        //if we want to choose from any of the two branches then 
        //first we will compute value and will if else condition
    TreeNode* left =  getTargetCopy(original->left,cloned->left,target);
    TreeNode* right =  getTargetCopy(original->right,cloned->right,target);
        
        if(left!=NULL)
        {
            return left;
        }
        
        return right;
    }
};