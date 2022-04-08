class Solution {
public:
    
    bool partitionArray(int idx,vector<int>& nums,int target,vector<vector<int>>& dp)
    {
        if(target == 0)  { return true; }
        
        if(idx==0) {
            if(target == nums[0]) { return true; }
            else { return false; } }
        
        if(dp[idx][target] != -1)   {  return  dp[idx][target]; }
        
        bool notTake = partitionArray(idx-1,nums,target,dp);
        bool take = false;
        
        if(nums[idx] <= target) {
            take = partitionArray(idx-1,nums,target-nums[idx],dp); }
         
        return dp[idx][target] = (take or notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int totSum=0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)  { totSum += nums[i]; }
        
        if(totSum%2==1)  { return false; }
        
        int target = totSum/2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    
       return partitionArray(n-1,nums,target,dp);
        
    }
};