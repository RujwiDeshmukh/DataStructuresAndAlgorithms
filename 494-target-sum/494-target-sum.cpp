class Solution {
public:
    
    int findWays(int ind,vector<int> & nums,int tar,vector<vector<int>>& dp)
    {
        
        if(ind==0)
        {
            if(tar==0 && nums[0]==0)
            {
                return 2;
            }
            
            if(tar==0 || nums[0]==tar)
            {
                return 1;
            }
            
            return 0;
        }
        
        if(dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }
        
        int notTake = findWays(ind-1,nums,tar,dp);
        int take=0;
        if(nums[ind] <= tar)
        {
            take = findWays(ind-1,nums,tar-nums[ind],dp);
        }
        
        return dp[ind][tar] = take+notTake;
    }
     
    int findTargetSumWays(vector<int>& nums, int tar) {
        
        int totSum = 0;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            totSum += nums[i];
        }
        
        if(totSum-tar<0 || (totSum-tar)%2==1)
        {
            return 0;
        }
        
        int target = (totSum-tar)/2;
        
        cout<<target<<endl;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return findWays(n-1,nums,target,dp);
        
    }
};