class Solution {
public:
    
    int recurCoinChange(vector<int>& coins,int idx,int amount,vector<vector<int>>& dp)
    {
        if(idx >= coins.size())
        {
            return 1000;
        }
        
        if(amount==0)
        {
            return 0;
        }
        
        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        
        int consider=1000;
        
        //using this condition as we are substracting values from amount
        //and final result can be -ve
        if(coins[idx] <= amount)
        {
            consider = 1+recurCoinChange(coins,idx,amount-coins[idx],dp);
        }
        
        int notConsider = recurCoinChange(coins,idx+1,amount,dp);
        
        return dp[idx][amount] = min(consider,notConsider);
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+5, vector<int>(amount+5,-1));
        
        int ans = recurCoinChange(coins,0,amount,dp);
        
        if(ans==1000)   return -1;
        
        return ans;
        
    }
};