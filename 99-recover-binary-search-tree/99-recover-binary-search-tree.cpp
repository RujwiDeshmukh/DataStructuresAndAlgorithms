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
    
    private:
      TreeNode* first;
      TreeNode* middle;
      TreeNode* prev;
      TreeNode* last;
    
    void InOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        
        InOrder(root->left);
        
        if(prev != NULL && (root->val < prev->val))
        {
            if(first==NULL)
            {
              first = prev;
              middle = root;
            }
            else
            {
                last=root;
            }
        }
        
        //prev everytime before recursive call
        prev=root;
        InOrder(root->right);
    }
    
    public :
    void recoverTree(TreeNode* root) {
        first = middle = prev = last = NULL;
        prev = new TreeNode(INT_MIN);
        InOrder(root);
         if(first && last)//will have to check this condition first as midle will be present 
             //for first an last case as well
        {
            swap(first->val,last->val);
        }
        else if(first && middle)
        {
            swap(first->val,middle->val);
        }
    }
};
