class Solution {
public:
    
    int totalWays(int row,int col,int m,int n,vector<vector<int>> & ans)
    {
        if(row==0 && col==0)
        {
            return 1;
        }
        
        if(row<0 || col<0)
        {
           return 0;   
        }
        
        if(ans[row][col] != -1)
        {
            return ans[row][col];
        }
        
        int upMove = totalWays(row-1,col,m,n,ans);
        int leftMove = totalWays(row,col-1,m,n,ans);
        
        return ans[row][col] = upMove+leftMove;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
       return totalWays(m-1,n-1,m,n,ans);
    }
};