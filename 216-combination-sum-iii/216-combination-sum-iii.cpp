class Solution {
public:
    
    void combinations(int ind,vector<int>& nums,vector<vector<int>>& ans, vector<int>& temp,int k,int target)
    {
        if(temp.size()==k && target==0)
        {
           ans.push_back(temp);
           return;
        }
        
        if(temp.size() > k)
        {
            return ;
        }
        
        if(ind >= nums.size())
        {
            return ;
        }
        
        if(target >= nums[ind])
        {
            temp.push_back(nums[ind]);
            //pick 
            combinations(ind+1,nums,ans,temp,k,target-nums[ind]);
            temp.pop_back();
        }
        //not pick
        combinations(ind+1,nums,ans,temp,k,target);
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        
        combinations(0,nums,ans,temp,k,n);
        
        return ans;
        
    }
};