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
    
    void totPaths(TreeNode* root,unordered_map<int,int>& mp,int & ans)
    {
       
        if(root == NULL)
        {
            return ;
        }
        
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL)
        {
            int ones=0;
            for(auto m : mp)
            {
               // if(m.second==1) wrong as count can be more
                if((m.second)%2==1)
                {
                    ones++;
                }
                
                if(ones > 1)
                {
                    break;
                }
                
               //out<<ones<<endl;
            }
            
            //dry run all the case
            //3355544 => one odd
            //3344 => all even
            //3344555666 => 2 odds
            //this wont be only equal to as all even numbers can exist
            if(ones<=1)
            {
                ans++;
            }
            
            //turn;
            //https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/991861/C%2B%2B-Super-Simple-Easy-Recursive-Solution-O(n)
        }
        
        //dry run the left and right part
        //u will get why mp[root->val]-- commented after left recursion
        //need to consider the null case here as well
        //and we need to add to map earlier as we are calculating
        //when left and right both are null for that root should be added
        //previously to the mp for further processing
        
        totPaths(root->left,mp,ans);
      //mp[root->val]--;
        totPaths(root->right,mp,ans);
         mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        int ans=0;
        totPaths(root,mp,ans);
        return ans;
    }
};