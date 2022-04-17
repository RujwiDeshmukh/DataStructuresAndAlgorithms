class Solution {
public:
    
    int minimumHealth(vector<vector<int>>& mat,int i,int j,vector<vector<int>>& dp)
    {
        int n =mat.size();
        int m = mat[0].size();
        
        if(i >= n || j>= m)
        {
            return 1e9+8;
        }
        
        if(i== n-1 && j==m-1)
        {
            return mat[i][j] <= 0 ? -mat[i][j]+1 : 1;
        }
        
        if(dp[i][j] != 1e9+8)
        {
            return dp[i][j];
        }
        
        int right = minimumHealth(mat,i+1,j,dp);
        int down = minimumHealth(mat,i,j+1,dp);
        
        int minHealth = min(right,down) - mat[i][j];
        
        return dp[i][j] = minHealth <= 0 ? 1 : minHealth;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) { 
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 1e9+8));
        return minimumHealth(dungeon,0,0,dp);
    }
};