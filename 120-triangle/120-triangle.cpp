class Solution {
public:
    
    int minimumSum(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(row==triangle.size()-1)
        {
            return triangle[row][col];
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        //for diagonal condition it wont cross as we are stopping for row==n-1
        
        int down = triangle[row][col]+minimumSum(row+1,col,triangle,dp);
        int diag = triangle[row][col]+minimumSum(row+1,col+1,triangle,dp);
        
        return dp[row][col] = min(down,diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return minimumSum(0,0,triangle,dp);
    }
};