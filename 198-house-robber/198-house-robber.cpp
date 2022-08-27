class Solution {
public:
    
    int maxMoney(vector<int>& nums,int ind,vector<int>& dp)
    {
        if(ind==0)
        {
            return nums[ind];
        }
        
        if(ind<0)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        //if you put condition for index should be greater than 1
        //then for array [1,2] it wont chose 2 simply it will chose 1
        //bcoz of that condition
        
       int pick = nums[ind] + maxMoney(nums,ind-2,dp);
        
       int notPick = maxMoney(nums,ind-1,dp);
        
       return dp[ind] =max(pick,notPick);
    }
    
    
    
    
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        
        return maxMoney(nums,nums.size()-1,dp);
    }
};