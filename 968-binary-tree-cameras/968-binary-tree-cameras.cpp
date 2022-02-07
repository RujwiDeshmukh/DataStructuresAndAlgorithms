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
    
    int minimumCameras(TreeNode* root,int& cameras)
    {
        //1 means dont need camera
        //-1 means require camera
        //0 means have camera
        if(root==NULL)
        {
            return 1;
        }
        
        int left = minimumCameras(root->left,cameras);
        int right = minimumCameras(root->right,cameras);
        
        //only child require camera then install camera
        if(left==-1 || right==-1)
        {
            cameras++;
            //returning zero to showcase that it has camera now
            return 0;
        }
        //it is already covered because either its left or right have camera
        if(left==0 || right==0)
        {
          return 1;
        }
        //both childs have camera, now we say to nodes parent , childs are covered but they dont have cameras, so I will require camera
        return -1;
    }
    
    
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        int ans = minimumCameras(root,cameras);
        if(ans==-1)
        {
            cameras++;
        }
        return cameras;
    }
};