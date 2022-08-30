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
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0 )
                {
                    if(obstacleGrid[i][j]==0)
                    {
                       dp[i][j]=1;
                    }
                }
                else
                {
                   int left =0;
                    int right=0;
                    
                    if(i>0)
                    {
                        if(obstacleGrid[i][j]==0)
                        {
                           left = dp[i-1][j];
                        }
                    }
                    
                    
                    if(j>0)
                    {
                        if(obstacleGrid[i][j]==0)
                        {
                           right = dp[i][j-1];
                        }
                    }
                    
                    dp[i][j] = left+right;
                }
                
            }
        }
        
       //return uniquePath(n-1,m-1,n,m,obstacleGrid,dp);
        
        return dp[n-1][m-1];
        
    }
};