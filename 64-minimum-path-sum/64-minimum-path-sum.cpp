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
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up = 999999;
                    if(i>0)
                    {
                      up  = grid[i][j]+ dp[i-1][j];
                    }
                       
                    int left=999999;
                    if(j>0)
                    {
                       left = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] = min(up,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};