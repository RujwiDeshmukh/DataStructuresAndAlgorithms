class Solution {
public:
    
    int maxCherries(vector<vector<int>>& grid,int n,int m,int r,int c1,int c2,
                    vector<vector<vector<int>>>& dp)
    {
        
        if(c1<0 || c2<0 || c1>=m || c2>=m)
        {
            return -1e9+8;
        }
        
        if(r==n-1)
        {
            if(c1==c2)
            {
                return grid[r][c1];
            }
            else
            {
                return grid[r][c1]+grid[r][c2];
            }
        }
        
        if(dp[r][c1][c2] != -1)
        {
            return dp[r][c1][c2];
        }
        
        //now for all 9 possible combinations for each move of alice and bob respectively
        int maxi = -1e9+8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int value=0;
                if(c1==c2)
                {       
                    //maxi = max(maxi, grid[r][c1]+maxCherries(grid,n,m,r+1,c1+dj1,c2+dj2));
                    value += grid[r][c1];
                }
                else
                {
         //maxi = max(maxi, grid[r][c1]+grid[r][c2]+maxCherries(grid,n,m,r+1,c1+dj1,c2+dj2));
                    value += grid[r][c1]+grid[r][c2];
                }
                value += maxCherries(grid,n,m,r+1,c1+dj1,c2+dj2,dp);
                maxi = max(maxi,value);
            }
        }
        
        return dp[r][c1][c2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return maxCherries(grid,n,m,0,0,m-1,dp);
    }
};