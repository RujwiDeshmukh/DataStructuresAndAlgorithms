class Solution {
public:
    
    int maxMoney(vector<int>& nums,vector<int>&dp,int n)
    {
        dp[0]=nums[0];
        
        for(int i=1;i<=n;i++)
        {
            int pick = nums[i];
            if(i>1)
            {
                pick += dp[i-2];
            }
            
            int notPick = dp[i-1];
            
            dp[i] = max(pick,notPick);
        }
        
        return dp[n];
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        vector<int>dp(n,-1);
        int zeroInd = maxMoney(nums,dp,n-2);
        cout<<zeroInd<<endl;
        fill(dp.begin(),dp.end(),-1);
        reverse(nums.begin(),nums.end());
        int lastInd = maxMoney(nums,dp,n-2);
        cout<<lastInd;
        
        return max(zeroInd,lastInd);
    }
};