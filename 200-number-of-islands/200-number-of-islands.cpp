class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int n,int m,int row,int col)
    {
        if(row>=n || row<0 || col>=m || col<0 || grid[row][col]=='0')
        {
            return ;
        }
        
        grid[row][col]='0';
        dfs(grid,n,m,row+1,col);
        dfs(grid,n,m,row-1,col);
        dfs(grid,n,m,row,col+1);
        dfs(grid,n,m,row,col-1);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
     
         int n = grid.size();
         int m = grid[0].size();
         int islands=0;
        
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(grid[i][j]=='1')
                 {
                     dfs(grid,n,m,i,j);
                     islands++;
                 }
             }
         }
        
        return islands;
    }
};