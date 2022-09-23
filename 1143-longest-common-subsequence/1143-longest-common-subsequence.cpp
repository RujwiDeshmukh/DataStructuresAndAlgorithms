class Solution {
public:
    
    int f(int ind1,int ind2,string s, string t,vector<vector<int>>& dp)
    {
        
        if(ind1 == 0 || ind2 == 0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        
        //Match Case
        //it will either match or not match
        if(s[ind1-1]==t[ind2-1])
        {
            return 1+f(ind1-1,ind2-1,s,t,dp);
            //as string is matched increasing the length by one
        }
        //returning from here straight as if matched we dont want 
        //the program to further run
        
        return dp[ind1][ind2] = max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
      //  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        vector<int>prev(m+1,0) , curr(m+1,0);
        
        //for any i but j should be 0 ans will be 0
        
        //for any j but i should be 0 ans will be 0
        for(int j=0;j<=m;j++)
        {
            prev[j]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j] = 1+prev[j-1];
                }
                else
                {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            
            prev = curr;
        }
        
        return prev[m];
        
        //return f(n,m,text1,text2,dp);
    }
};