class Solution {
public:
    
    int uniquePath(int row,int col,int m,int n,vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        
        if(row==0 && col==0 && obstacleGrid[row][col] != 1)
        {
            return 1;
        }
         if(row<0 || col<0)
        {
            return 0;
        }
        
        if(obstacleGrid[row][col]==1)
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int left = uniquePath(row-1,col,m,n,obstacleGrid,dp);
        int right = uniquePath(row,col-1,m,n,obstacleGrid,dp);
        
        return dp[row][col]=left+right;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
       return uniquePath(n-1,m-1,n,m,obstacleGrid,dp);
        
    }
};