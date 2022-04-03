class Solution {
public:
    
    int countPaths(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col)
    {
        if(row>=0 && col>=0 && grid[row][col] == 1)
        {
            return 0;
        }
        
        if(row==0 && col==0)
        {
            return 1;
        }
        
        if(row < 0 || col < 0 )
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int up = countPaths(grid,dp,row-1,col);
        int left = countPaths(grid,dp,row,col-1);
        
        return dp[row][col] = up+left;
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        return countPaths(obstacleGrid,dp,n-1,m-1);
    }
};