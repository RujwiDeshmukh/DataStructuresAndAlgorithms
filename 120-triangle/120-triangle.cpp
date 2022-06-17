class Solution {
public:
    
    int dfs(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& memo)
    {
        //as we are adding values if return INT_MAX
        //by seeing that we have to calculate the minimum value
        //then it will row wrong as while returing we are adding values
        //so it give the overflow condition so we need to simply return 0
        
        if(i==n)
        {
            return 0;
        }
        
        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }
        
        int leftPart = triangle[i][j] + dfs(i+1,j,n,triangle,memo);
        int rightPart = triangle[i][j] + dfs(i+1,j+1,n,triangle,memo);
        
        return memo[i][j] = min(leftPart,rightPart);
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>>memo(n, vector<int>(n,-1));
        
        return dfs(0,0,n,triangle,memo);
    }
};