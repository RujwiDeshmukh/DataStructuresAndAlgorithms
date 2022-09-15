class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totSum=0;
        
        if(n==1)
        {
            return false;
        }
        
        for(int i=0;i<n;i++)
        {
            totSum += nums[i];
        }
        
        if(totSum%2 == 1)
        {
            return false;
        }
        
        int target = totSum/2;
        
        vector<vector<bool>>dp(n+5,vector<bool>(target+5,false));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        
        //as target is 50 and our first element here is 99 so
        //it will give the error so every time target should be 
        //equal to nums[0] or always greatre than zero
        if(target >= nums[0])
        {
            dp[0][nums[0]]=true;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                bool notTake = dp[i-1][j];
                bool take = false;
                
                if(nums[i] <= j)
                {
                    take = dp[i-1][j-nums[i]];
                }
                
                dp[i][j] = take | notTake;
            }
        }
        
        return dp[n-1][target];
        
    }
};