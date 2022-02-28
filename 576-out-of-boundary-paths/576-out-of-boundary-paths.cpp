class Solution {
public:
    
    long long int MOD = 1e9+7;
    
    int findPath(int m,int n,int k, int startRow,int startColumn,int dp[52][52][52])
    {
        //as we have to go outside the boundary in specified moves
        if(startColumn<0 || startRow <0 || startColumn >= n || startRow >= m)
        {
            return 1;
        }
        
        if(k==0)
        {
            return 0;
        }
        
        if(dp[startRow][startColumn][k] != -1)
        {
            return dp[startRow][startColumn][k];
        }
        
        int ans=0;
        
        ans =  (ans+findPath(m,n,k-1,startRow+1,startColumn,dp))%MOD;
        ans =  (ans+findPath(m,n,k-1,startRow-1,startColumn,dp))%MOD;
        ans =  (ans+findPath(m,n,k-1,startRow,startColumn+1,dp))%MOD;
        ans =  (ans+findPath(m,n,k-1,startRow,startColumn-1,dp))%MOD;
        
        dp[startRow][startColumn][k] = ans;
        return dp[startRow][startColumn][k];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[52][52][52];
        memset(dp,-1,sizeof(dp));
        return findPath(m,n,maxMove,startRow,startColumn,dp);
    }
};