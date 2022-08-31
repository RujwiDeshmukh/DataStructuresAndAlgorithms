class Solution {
public:
    
    int minimumPath(int row,int col,int n ,int m, vector<vector<int>>& grid,     vector<vector<int>>& dp)
    {
        if(row==0 && col==0)
        {
            return grid[row][col];
        }
        
        //we dont want to include this condition in our answer
        //so we simply return the large value as we want to take the minimum
        
        if(row<0 || col<0)
        {
            return 9999999;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int up = grid[row][col] + minimumPath(row-1,col,n,m,grid,dp);
        int left = grid[row][col] + minimumPath(row,col-1,n,m,grid,dp);
        
        return dp[row][col] = min(up,left);
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return minimumPath(n-1,m-1,n,m,grid,dp);
    }
};