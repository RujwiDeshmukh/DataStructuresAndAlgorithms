class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        int mini=99999;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up = grid[i][j]+dp[i-1][j];
                    int leftDiag = 999999;
                    if(j>0)
                    {
                    leftDiag = grid[i][j]+dp[i-1][j-1];
                    }
                    int rightDiag = 999999;
                    if(j<n-1)
                    {
                    rightDiag = grid[i][j]+dp[i-1][j+1];
                    }
                    
                    dp[i][j] = min(up,min(leftDiag,rightDiag));
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
             cout<<dp[n-1][i]<<endl; 
            mini = min(mini,dp[n-1][i]);
        }
        
        return mini;
    }
};