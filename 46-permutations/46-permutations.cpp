class Solution {
public:
    
    void recurPermutate(int ind, vector<int>& nums,vector<vector<int>>& ans)
    {
        if(ind >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        //for placing that particular element at every possible state 
        
        for(int i=ind;i<nums.size();i++)
        {
            //modifying the original array
            swap(nums[ind],nums[i]);
            recurPermutate(ind+1,nums,ans);
            //restoring the swapped values to original array
            swap(nums[ind],nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
        recurPermutate(0,nums,ans);
        return ans;
    }
};