class Solution {
public:
    
    //1st ---> no. of elements in an array
    //2nd ---> buy/not buy field
    //3rd ---> no. of transcations
    int dp[100000][3][2];
    
    int bestTime(vector<int>& prices,int currentDay,int canBuy,int transCount)
    {
        if(currentDay >= prices.size())
        {
            return 0;
        }
        
        if(transCount <= 0)
        {
            return 0;
        }
        
        if(dp[currentDay][canBuy][transCount] != -1)
        {
            return dp[currentDay][canBuy][transCount];
        }
        
        int idle;
        int ans=0;
        
        if(canBuy)
        {
            idle = bestTime(prices,currentDay+1,canBuy,transCount);
            int buy = -prices[currentDay]+bestTime(prices,currentDay+1,0,transCount);
            ans = max(idle,buy);
        }
        else
        {
           idle = bestTime(prices,currentDay+1,0,transCount);
           int sell = prices[currentDay]+bestTime(prices,currentDay+1,canBuy,transCount-1);
           ans = max(idle,sell);
        }
        
        return dp[currentDay][canBuy][transCount] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return bestTime(prices,0,1,1);
    }
};