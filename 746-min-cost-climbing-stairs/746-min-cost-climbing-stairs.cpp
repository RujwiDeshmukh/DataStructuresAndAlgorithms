class Solution {
public:
    
    int minCost(vector<int>& cost,int ind,vector<int>& dp)
    {
        
        if(ind == cost.size())
        {
            return 0;
        }
        
        if(ind > cost.size())
        {
            return 100000;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int oneStep = cost[ind]+minCost(cost,ind+1,dp);
        
        int twoSteps = cost[ind]+minCost(cost,ind+2,dp);
        
        return dp[ind] = min(oneStep,twoSteps);
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {

       int n = cost.size(); 
       vector<int>dp(n,-1);
        
      int zeroIndex = minCost(cost,0,dp);
      int firstIndex = minCost(cost,1,dp);
        
      return min(zeroIndex,firstIndex);
       
    }
};