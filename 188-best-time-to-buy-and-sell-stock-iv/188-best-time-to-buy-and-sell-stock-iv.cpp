class Solution {
public:
    
    int maximumProfit(int ind,vector<int>& prices,int k, bool canBuy, vector<vector<vector<int>>>& dp)
    {
        if(ind >= prices.size() || k <= 0)
        {
            //not returning int min as we are adding value to 
            //next recursive part 
            return 0;
        }
        
        if(dp[ind][k][canBuy] != -1)
        {
            return dp[ind][k][canBuy];
        }
        
        if(canBuy)
        {
            int idle = maximumProfit(ind+1,prices,k,canBuy,dp);
            int buy = -prices[ind]+maximumProfit(ind+1,prices,k,false,dp);
            dp[ind][k][canBuy] = max(idle,buy);
            
        }
        else
        {
            int idle = maximumProfit(ind+1,prices,k,canBuy,dp);
            int sell = prices[ind]+maximumProfit(ind+1,prices,k-1,true,dp);
            dp[ind][k][canBuy] = max(idle,sell);
        }
        
        return dp[ind][k][canBuy];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+5,vector<vector<int>>(k+5,vector<int>(3,-1)));
        return maximumProfit(0,prices,k,true,dp);
    }
};