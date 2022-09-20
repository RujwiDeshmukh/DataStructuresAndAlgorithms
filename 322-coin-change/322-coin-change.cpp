class Solution {
public:
    
    int minCoins(int ind,vector<int>& coins,int amount, vector<vector<int>>& dp)
    {
        
        if(ind==0)
        {
            if(amount%coins[0]==0)
            {
                return amount/coins[0];
            }
                return 1e9+6;
        }
        
        if(dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }
        
        int notTake = minCoins(ind-1,coins,amount,dp);
        
        int take = 1e9+6;
        
        if(coins[ind] <= amount)
        {
            take = 1+minCoins(ind,coins,amount-coins[ind],dp);
        }
        
        return dp[ind][amount] = min(notTake,take);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
         
          int n = coins.size();
        
          vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
          int ans = minCoins(n-1,coins,amount,dp);
        
          if(ans == 1e9+6)
          {
              return -1;
          }
        
        return ans;
    }
};