class Solution {
public:
    
    int dp[71][71][71];
    
    int maxCherries(int r1,int c1,int c2,int n,int m,vector<vector<int>>& grid)
    {
        if(c1>=m || c2>=m || c1<0 || c2<0)
        {
            return INT_MIN;
        }
        
        
        if(r1==n-1)
        {
            if(c1==c2)
            {
                return grid[r1][c1];
            }
            else
            {
                return grid[r1][c1]+grid[r1][c2];
            }
        }
        
        if(dp[r1][c1][c2] != -1)
        {
            return dp[r1][c1][c2];
        }
        
        
        int cherry=0;
        
        if(c1==c2)
        {
            cherry += grid[r1][c1];
        }
        else
        {
            cherry += grid[r1][c1]+grid[r1][c2];
        }
        
        int maxi=INT_MIN;
        
        //instead of this we can write 9 combinations 
        //to get the maximum value out of the one
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                maxi=max(maxi,maxCherries(r1+1,c1+i,c2+j,n,m,grid));
            }
        }
        
        return dp[r1][c1][c2] = maxi+cherry;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
       // https://leetcode.com/problems/cherry-pickup-ii/discuss/1674294/C%2B%2B-oror-RECURSION-%2B-MEMOIZATION-oror-FULLY-EXPLAINED-oror-4-D-DP-oror-3-D-DP
        
        memset(dp,-1,sizeof(dp));;
        
        int n = grid.size();
        int m = grid[0].size();
        
        return maxCherries(0,0,m-1,n,m,grid);
        
    }
};