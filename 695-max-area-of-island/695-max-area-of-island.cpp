class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>>& grid,int& size)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==0 || grid[row][col]==-1)
        {
            return;
        }
        
        if(grid[row][col]==1)
        {
            grid[row][col]=-1;
            size += 1;
            dfs(row+1,col,grid,size);
            dfs(row-1,col,grid,size);
            dfs(row,col+1,grid,size);
            dfs(row,col-1,grid,size);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int size=0;
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,size);
                    ans = max(ans,size);
                }
            }
        }
        
        if(ans==INT_MIN)
        {
            return 0;
        }
        
        return ans;
    }
};