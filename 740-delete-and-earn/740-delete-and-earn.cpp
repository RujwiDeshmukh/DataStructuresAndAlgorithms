class Solution {
public:
    
    int deleteEarn(vector<int>& count,int idx,int dp[])
    {
        if(idx >= count.size())
        {
            return 0;
        }
        
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        
        int consider = count[idx]+deleteEarn(count,idx+2,dp);
        int notConsider = deleteEarn(count,idx+1,dp);
        
        return dp[idx] = max(notConsider,consider);
    }
    
    //https://leetcode.com/problems/delete-and-earn/discuss/1588157/House-Robber-or-C%2B%2B-or-Memoization
    
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>count(10001,0);
        int dp[10001];
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]] += nums[i];
        }
        
        return deleteEarn(count,0,dp);
    }
};