class Solution {
public:
    
    //Striver's Bottom Up Solution
    
    int maxMoney(vector<int>& nums,vector<int>& dp)
    {
        dp[0] = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int take = nums[i];
            if(i>1)
            {
                take += dp[i-2];
            }
            int notTake = dp[i-1];
            
            dp[i] = max(take,notTake);
        }
        
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxMoney(nums,dp);
    }
};