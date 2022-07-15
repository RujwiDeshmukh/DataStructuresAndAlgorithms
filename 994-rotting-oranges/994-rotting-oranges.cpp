class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>>& grid,int minutes)
    {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(row<0 || col<0 || row >=n || col >= m )
        {
            return ;
        }
        
        if(grid[row][col]==1 || grid[row][col]>=minutes)
        {
            grid[row][col] = minutes;
            dfs(row+1,col,grid,minutes+1);
            dfs(row-1,col,grid,minutes+1);
            dfs(row,col+1,grid,minutes+1);
            dfs(row,col-1,grid,minutes+1);
        }
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
     
          int n = grid.size();
          int m = grid[0].size();
          int minutes=2;
          int ans= -1;
         
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(grid[i][j]==2)
                  {
                      dfs(i,j,grid,minutes);
                  }
              }
          }
        
        for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(grid[i][j]==1)
                  {
                      return -1;
                  }
                  else
                  {
                      minutes = max(minutes,grid[i][j]);
                  }
              }
          }
        return minutes-2;
    }
};