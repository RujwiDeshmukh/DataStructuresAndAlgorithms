class Solution {
public:

    int recurcoinChange(vector<int>& coins, int idx, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0)
        {
            return 0;
        }
        
        if(idx >= coins.size())
        {
            return 10000;
        }
        
        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        
        int consider = 10000;
        //as if we take consider=0 then if left call is not made
        //then minimum of both value will give 0 as value
        
        if(coins[idx] <= amount)
        {
            consider = 1 + recurcoinChange(coins,idx,amount-coins[idx],dp);
        }
        
        int notConsider =  recurcoinChange(coins,idx+1,amount,dp);
        
        return dp[idx][amount]=min(consider,notConsider);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+5, vector<int>(amount+5, -1));
        
        int ans = recurcoinChange(coins,0,amount,dp);
        
        if(ans == 10000)
        {
            return -1;
        }
        
        return ans;
    }
};