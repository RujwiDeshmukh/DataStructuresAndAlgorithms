class Solution {
public:
    
    int maximumCherry(int r1,int c1,int c2,int n,vector<vector<int>>& grid,     vector<vector<vector<int>>>& dp)
    {
        int r2 = r1+c1-c2;
        
       // https://leetcode.com/problems/cherry-pickup/discuss/1912865/C%2B%2B-oror-Detailed-Explanation-and-clear-Intuitions-oror-Memoization-oror-DP-oror-Good-Question
        
      //  https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
        
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        
        //checking for only one as both reach the target at the same time
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        
        if(dp[r1][c1][c2] != -1)
        {
            return dp[r1][c1][c2];
        }
        
        int cherry=0;
        
        if(r1==r2 && c1==c2)
        {
            cherry = grid[r1][c1];
        }
        else
        {
            cherry = grid[r1][c1]+grid[r2][c2];
        }
        
        int ans = max({maximumCherry(r1+1,c1,c2,n,grid,dp),   maximumCherry(r1,c1+1,c2+1,n,grid,dp), maximumCherry(r1+1,c1,c2+1,n,grid,dp), 
                      maximumCherry(r1,c1+1,c2,n,grid,dp)});
        
        return dp[r1][c1][c2] = ans+cherry;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        
        return max(0,maximumCherry(0,0,0,n,grid,dp));
       
        //this wont work as +ve value is being added to INT_MIN
        //so value will not remain == to INT_MIN
        
       /* if(ans == INT_MIN)
        {
            return 0;
        }
        
        return ans;*/
    }
};