class Solution {
public:
    
    int f(string s,string p,int i,int j,vector<vector<int>>& dp)
    {
        
        //base case
        if(i==0 && j==0) return true;
        //wherever it is greater than or equal to make is greater than only.
        if(j==0 && i>0) return false;
        if(i==0 && j>0) 
        {
            //as now j is greater than 0 as it is 1 based indexing
            for(int k=1;k<=j;k++)
            {
                //wherever it is string do ind-1 everywhere
                if(p[k-1] != '*')
                {
                    return false;
                }
            }
            
            return true;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i-1]==p[j-1] || p[j-1]=='?')
        {
            return dp[i][j] = f(s,p,i-1,j-1,dp);
        }
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = f(s,p,i-1,j,dp) or f(s,p,i,j-1,dp);
        }
        
        //not matching not * or ? 
        //so return false;
        
        return 0;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        
        //return f(s,p,n,m,dp);
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=false;
        }
        
        for(int j=1;j<=m;j++)
        {
            int flag = 1;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1] != '*')
                {
                    flag = 0;
                    break;
                }
            }
             dp[0][j]=flag;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                   {
                      dp[i][j] = dp[i-1][j-1];
                    }
        
                 else if(p[j-1]=='*')
                    {
                       dp[i][j] = dp[i-1][j] or dp[i][j-1];
                    }
                else
                {
                dp[i][j]=0;
                }
            }
        }
        
        return dp[n][m];
    }
};