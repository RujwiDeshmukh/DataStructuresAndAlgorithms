class Solution {
public:
    
    int decode(string s, int idx, int n, vector<int>& dp)
    {
        if(idx >= n)
        {
            return 1;
        }
        
        if(idx < n && s[idx]=='0')
        {
            return 0;
        }
        
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        
        int ways=0;
        
        //pick single element
        if(s[idx] != '0')
        {
            ways = decode(s,idx+1,n,dp);
        }
        
        //pick double elment
      if(idx+1 < n && ((s[idx]=='1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
      {
          ways += decode(s,idx+2,n,dp);
      }
        
        return dp[idx] = ways;
    }
    
    int numDecodings(string s) {
       
        int n = s.size();
        
        vector<int>dp(n,-1);
        
        return decode(s,0,n,dp);
    }
};