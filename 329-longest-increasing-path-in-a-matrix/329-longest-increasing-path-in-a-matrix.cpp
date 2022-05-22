class Solution {
public:

int maximumPath(vector<vector<int>>& matrix,int i,int j,int prev,vector<vector<int>>& dp)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return 0;
        }
        if(prev >= matrix[i][j])
        {
            return 0;
        }
    
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        //for next step current element will be prev 
        int left = 1+maximumPath(matrix,i-1,j,matrix[i][j],dp);
        int right = 1+maximumPath(matrix,i+1,j,matrix[i][j],dp);
        int top = 1+maximumPath(matrix,i,j-1,matrix[i][j],dp);
        int bottom = 1+maximumPath(matrix,i,j+1,matrix[i][j],dp);
        
        return dp[i][j] = max(left, max(right, max(top,bottom)));
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxPath = 1;
        
        vector<vector<int>>dp(n+2, vector<int>(m+2,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //previous element for first element will be -1
                //as for 1st there wont be any previous element
                maxPath = max(maxPath, maximumPath(matrix,i,j,-1,dp));
            }
        }
        
        return maxPath;
    }
};