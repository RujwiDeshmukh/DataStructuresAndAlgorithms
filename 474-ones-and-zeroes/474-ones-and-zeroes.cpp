class Solution {
public:
    
    int dp[605][105][105];
    
    pair<int,int> countOnesandZeroes(string str)
    {
        int one=0, zero=0;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        
        return {one,zero};
    }
    
    int solve(int i,int one,int zero,int maxZero,int maxOne,vector<string>& strs)
    {
         if(i >= strs.size())
         {
             return 0;
         }
        
         if(one > maxOne || zero > maxZero)
         {
             return 0;
         }
        
         if(dp[i][one][zero] != -1)
         {
             return dp[i][one][zero];
         }
        
         pair<int,int>p = countOnesandZeroes(strs[i]);
        
         int ans1=0 , ans2=0, ansWithout=0;
        
         if(p.first+one <= maxOne && p.second+zero <= maxZero)
         {
             //consider
             ans1 = 1+solve(i+1,p.first+one,p.second+zero,maxZero,maxOne,strs);
             
             //not consider
             ans2 = solve(i+1,one,zero,maxZero,maxOne,strs);
         }
        else
        {
            ansWithout = solve(i+1,one,zero,maxZero,maxOne,strs);
        }
        
        return dp[i][one][zero] = max({ans1, ans2, ansWithout});
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp, -1, sizeof(dp));
        return solve(0,0,0,m,n,strs);
    }
};