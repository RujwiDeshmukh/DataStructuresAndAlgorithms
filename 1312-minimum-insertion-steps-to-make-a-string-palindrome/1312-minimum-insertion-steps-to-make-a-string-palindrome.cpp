class Solution {
public:
    
    int longestPalindromicSubsequence(string s,string t)
    {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=n;i++)  {      dp[i][0]=0 ; }
        for(int i=0;i<=n;i++)  {      dp[0][i]=0 ; }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
    
    int minInsertions(string s) {
        
        int n = s.size();
        string t = s;   
        reverse(t.begin(),t.end());
        
        int len = longestPalindromicSubsequence(s,t);
        
        return n-len;
        
    }
};