class Solution {
public:
    
    int totalWays(int row,int col,int m,int n,vector<vector<int>> & ans)
    {
        if(row==m-1 && col==n-1)
        {
            return 1;
        }
        
        if(row>=m || col>=n)
        {
           return 0;   
        }
        
        if(ans[row][col] != -1)
        {
            return ans[row][col];
        }
        
        int downMove = totalWays(row+1,col,m,n,ans);
        int rightMove = totalWays(row,col+1,m,n,ans);
        
        return ans[row][col] = downMove+rightMove;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
       return totalWays(0,0,m,n,ans);
    }
};