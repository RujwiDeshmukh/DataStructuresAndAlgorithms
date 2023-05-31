class Solution {
public:
    
    int gameWinner(int start,int end,vector<int>& piles,bool turn,vector<vector<vector<int>>> & dp)
    {
        if(start>end)  return 0;
        
        if(dp[start][end][turn] != -1)  return dp[start][end][turn];
        
        if(turn)
        {
           int front = piles[start]+gameWinner(start+1,end,piles,0,dp);
           int back = piles[end]+gameWinner(start,end-1,piles,0,dp);
           return dp[start][end][turn] = max(front,back);
        }
        
        
           int front = -piles[start]+gameWinner(start+1,end,piles,1,dp);
           int back = -piles[end]+gameWinner(start,end-1,piles,1,dp);
           return dp[start][end][turn] = min(front,back);
    }
    
    bool stoneGame(vector<int>& piles) {
        
    //https://leetcode.com/problems/stone-game/discuss/2579538/C%2B%2B-oror-Game-Theory-Concept-Of-Min-Max-oror-O(N2)
    
        //https://leetcode.com/problems/stone-game/discuss/1385343/C%2B%2B-(Standard-Optimal-Game-Strategy)-Recur%2BMemo
        
        //https://leetcode.com/problems/stone-game/discuss/1755050/2-methods-greaterC%2B%2BororBottom-UporDp-oror-Explained-and-O(1)method.
        
         int n = piles.size();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1, vector<int>(2,-1)));
         return gameWinner(0,n-1,piles,true,dp);
    }
};