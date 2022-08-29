class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m, vector<int>(n,-1));
        
        //when we reach 0 0 from m-1 n-1 then there will be one path
        dp[0][0]=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int leftMove =0;
                    if(j>0)
                    {
                        leftMove = dp[i][j-1];
                    }
                       
                    int upMove =0;
                    if(i>0)
                    {
                       upMove = dp[i-1][j];
                    }
                    
                    dp[i][j] = leftMove+upMove;
                }
                
                
            }

        }
        
        return dp[m-1][n-1];
    }
};