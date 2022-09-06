class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>front(n,0);
        
       // return minimumSum(0,0,triangle,dp);
        
        //base condition it is 
        //as base condition is computed for row n-1
        //so we have to start for loop from n-2
        
        for(int j=0;j<triangle[n-1].size();j++)
        {
            front[j] = triangle[n-1][j];
        }
        
        for(int row=n-2;row>=0;row--)
        {
            vector<int>curr(n,0);
               
            for(int col=0;col<triangle[row].size();col++)
            {
                int down = INT_MAX;
                int diag = INT_MAX;
                if(row < n-1)
                {
                    down = triangle[row][col]+front[col];
                }
                
                if(row < n-1)
                {
                    diag = triangle[row][col]+front[col+1];
                }
               
                curr[col] = min(down,diag);
            }
            
            front = curr;
        }
        
        return front[0];
    }
};