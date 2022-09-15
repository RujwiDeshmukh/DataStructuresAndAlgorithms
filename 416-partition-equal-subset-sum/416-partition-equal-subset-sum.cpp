class Solution {
public:
    
    int partition(int ind,vector<int>& nums,int target,vector<vector<int>>& dp)
    {
        if(target==0)
        {
            return 1;
        }
        
        if(ind==0)
        {
            return (target==nums[0]);
        }
        
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        
        int notTake = partition(ind-1,nums,target,dp);
        
        int take = 0;
        
        if(nums[ind] <= target)
        {
            take = partition(ind-1,nums,target-nums[ind],dp);
        }
        
        return dp[ind][target] = take or notTake;
    } 
    
    bool canPartition(vector<int>& nums) {
        
        int totSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            totSum += nums[i];
        }
        
        //totSum is odd then it wont be possible to divide the array
        //into 2 parts
        if(totSum%2==1)
        {
            return false;
        }
        
        int target = totSum/2;
        
        vector<vector<int>>dp(nums.size()+5,vector<int>(target+5,-1));
        
        return partition(nums.size()-1,nums,target,dp);
        
    }
};