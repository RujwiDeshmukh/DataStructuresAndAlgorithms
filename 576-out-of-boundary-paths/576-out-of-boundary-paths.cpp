class Solution {
public:
    
    const int mod = 1e9+7;
    
    int findPath(int m,int n,int maxMove,int row,int col,vector<vector<vector<int>>>& dp)
    {
        if(row < 0 || row >= m || col < 0 || col >= n)
        {
            return 1;
        }
        
        if(maxMove == 0)
        {
            return 0;
        }
        
        if(dp[row][col][maxMove] != -1)
        {
            return dp[row][col][maxMove];
        }
        
        int ans = 0;
        
        ans = (ans+findPath(m,n,maxMove-1,row+1,col,dp))%mod;
        ans = (ans+findPath(m,n,maxMove-1,row-1,col,dp))%mod;
        ans = (ans+findPath(m,n,maxMove-1,row,col+1,dp))%mod;
        ans = (ans+findPath(m,n,maxMove-1,row,col-1,dp))%mod;
        
        return dp[row][col][maxMove] = ans;
    }
    
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(52, vector<vector<int>>(52, vector<int> (52,-1))); 
        return findPath(m,n,maxMove,startRow,startColumn,dp);
    }
};