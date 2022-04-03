class Solution {
public:
    int dp[202][202];
    int minSum(vector<vector<int>>& grid,int row,int col,int m,int n)
    {
        if(row >= m || col >= n)
        {
            return 1000;
        }
        
        if(row==m-1 && col==n-1)
        {
            return grid[row][col];
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int rightMove = grid[row][col] + minSum(grid,row,col+1,m,n);
        int downMove = grid[row][col] + minSum(grid,row+1,col,m,n);
        
        return dp[row][col] = min(rightMove,downMove);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>prev(n+1,0);
        
        //memset(dp,-1,sizeof(dp));
        //return minSum(grid,0,0,m,n);
        
        for(int i=0;i<m;i++)
        {
            
            vector<int>curr(n+1,0);
            
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                    {
                        up += prev[j];
                    }
                    else
                    {
                        up += 1e9;
                    }
                    
                    int left = grid[i][j];
                    
                    if(j>0)
                    {
                        left += curr[j-1];
                    }
                    else
                    {
                        left += 1e+9;
                    }
                    
                    curr[j] = min(up,left);
                }
            }
            
            prev = curr;
        }
        
        //cout<<dp[n-3][m-3];
        
        return prev[n-1];
    }
};