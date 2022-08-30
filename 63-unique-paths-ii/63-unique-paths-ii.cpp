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
        
        vector<int>prev(m,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int>curr(m,0);
            
            for(int j=0;j<m;j++)
            {
                
                //here itself can check if dp[i][j]==1 then 
                 //directly store dp[i][j]=0 as it is a obstacle
                if(i==0 && j==0 )
                {
                    if(obstacleGrid[i][j]==0)
                    {
                       curr[j]=1;
                    }
                }
                else
                {
                   int up =0;
                    int right=0;
                    
                    if(i>0)
                    {
                        if(obstacleGrid[i][j]==0)
                        {
                           up = prev[j];
                        }
                    }
                    
                    
                    if(j>0)
                    {
                        if(obstacleGrid[i][j]==0)
                        {
                           right = curr[j-1];
                        }
                    }
                    
                    curr[j] = up+right;
                }
                
            }
            
            prev=curr;
        }
        
       //return uniquePath(n-1,m-1,n,m,obstacleGrid,dp);
        
        return prev[m-1];
        
    }
};