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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int>ans;
         unordered_map<TreeNode* ,TreeNode*>mp;
         markParents(root,NULL,mp);
        unordered_set<TreeNode*>st;
         printKDistance(target,k,st,mp,ans);
         return ans;
    }
    
    void markParents(TreeNode* currentNode, TreeNode* parentNode, unordered_map<TreeNode*,TreeNode*>& mp)
    {
        if(currentNode==NULL)
        {
            return ;
        }
        
        mp[currentNode] = parentNode;
        markParents(currentNode->left,currentNode,mp);
        markParents(currentNode->right,currentNode,mp);
    }
    
    void printKDistance(TreeNode* currentNode,int k, unordered_set<TreeNode*>st, unordered_map<TreeNode*,TreeNode*>& mp,vector<int>& ans)
    {
        if(currentNode==NULL || st.find(currentNode) != st.end())
        {
            return ;
        }
        
        st.insert(currentNode);
        
        if(k==0)
        {
            ans.push_back(currentNode->val);
            return ;
        }
        printKDistance(currentNode->left,k-1,st,mp,ans);
        printKDistance(currentNode->right,k-1,st,mp,ans);
        printKDistance(mp[currentNode],k-1,st,mp,ans);
    }
    
};