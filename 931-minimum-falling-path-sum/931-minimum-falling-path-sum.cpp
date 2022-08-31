class Solution {
public:
    
    int minimumSum(int row,int col,int n,vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        
        if(col>=n || col<0)
         {
             return 10000000;
         }
        
         if(row==0)
         {
             return matrix[row][col];
         }
        
         if(dp[row][col] != -1)
         {
             return dp[row][col];
         }
        
      /*   if(col>=n || col<0)
         {
             return 10000000;
         }
         */
        
         int up = matrix[row][col]+minimumSum(row-1,col,n,matrix,dp);
         int leftDiag = matrix[row][col]+minimumSum(row-1,col-1,n,matrix,dp);
         int rightDiag = matrix[row][col]+minimumSum(row-1,col+1,n,matrix,dp);
        
        return dp[row][col] = min(up, min(leftDiag,rightDiag));
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int mini=99999;
        
        for(int i=0;i<n;i++)
        {
           int ans = minimumSum(n-1,i,n,matrix,dp);
           
            mini = min(mini,ans);
        }
        
        return mini;
    }
};