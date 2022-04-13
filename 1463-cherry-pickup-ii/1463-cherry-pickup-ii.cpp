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
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        //base condition
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
        
        //as we know the base case is n-1, the looping will start from n-2 position
        
        //for changing row
        for(int i=n-2;i>=0;i--)
        {
            //for changing column for robot 1
            for(int j1=0;j1<m;j1++)
            {
                //for changing column for robot 3
                for(int j2=0;j2<m;j2++)
                {
                      
                     int maxi = -1e9+8;
                    //for loops for the 9 possible combinations of 2 robots
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int value=0;
                if(j1==j2)
                {       
                    //maxi = max(maxi, grid[r][c1]+maxCherries(grid,n,m,r+1,c1+dj1,c2+dj2));
                    value += grid[i][j1];
                }
                else
                {
         //maxi = max(maxi, grid[r][c1]+grid[r][c2]+maxCherries(grid,n,m,r+1,c1+dj1,c2+dj2));
                    value += grid[i][j1]+grid[i][j2];
                }
                //check this out of bound condition always
                if(j1+dj1 >=0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                   value += dp[i+1][j1+dj1][j2+dj2];
                else
                    value = -1e8+9;
                maxi = max(maxi,value);
            }
        }
                    
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
            //dp[0][0] => robot 1
            //dp[0][m-1] => robot 2
    }
};