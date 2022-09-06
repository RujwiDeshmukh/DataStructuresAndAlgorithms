class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        
       // https://leetcode.com/problems/cherry-pickup-ii/discuss/1674294/C%2B%2B-oror-RECURSION-%2B-MEMOIZATION-oror-FULLY-EXPLAINED-oror-4-D-DP-oror-3-D-DP
        
        int n = grid.size();
        int m = grid[0].size();
        
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(m,INT_MIN)));
        
       // return maxCherries(0,0,m-1,n,m,grid);
        
        
        
        //write base case first
        
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else
                {
                    dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        
        //as base case is n-1 so we will compute from n-2
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int cherry=0;
                    
                    if(j1==j2)
                    {
                        cherry = grid[i][j1];
                    }
                    else
                    {
                        cherry = grid[i][j1]+grid[i][j2];
                    }
                    
                   int maxi=INT_MIN;
                    
                     for(int c1=-1;c1<=1;c1++)
                  {
                         for(int c2=-1;c2<=1;c2++)
                        {
                             if(j1+c1 >= 0 && j1+c1 < m && j2+c2 >= 0 && j2+c2< m)
                             {
                                 maxi=max(maxi,dp[i+1][j1+c1][j2+c2]);
                             }
                       }
                  }  
                    
                    dp[i][j1][j2]=maxi+cherry;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};