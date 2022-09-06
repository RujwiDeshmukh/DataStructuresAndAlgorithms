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
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
       // return minimumSum(0,0,triangle,dp);
        
        //base condition it is 
        //as base condition is computed for row n-1
        //so we have to start for loop from n-2
        
        for(int j=0;j<triangle[n-1].size();j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int row=n-2;row>=0;row--)
        {
            for(int col=0;col<triangle[row].size();col++)
            {
                int down = INT_MAX;
                int diag = INT_MAX;
                if(row < n-1)
                {
                    down = triangle[row][col]+dp[row+1][col];
                }
                
                if(row < n-1)
                {
                    diag = triangle[row][col]+dp[row+1][col+1];
                }
               
                dp[row][col] = min(down,diag);
            }
        }
        return dp[0][0];
    }
};