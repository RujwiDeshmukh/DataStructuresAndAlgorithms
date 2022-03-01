class Solution {
public:
    
    void dfs(int row,int col,int m,int n,vector<vector<int>>& grid1,vector<vector<int>>& grid2,bool & res)
    {
         if(row<0 || col<0 || row>=m || col>=n || grid2[row][col]!=1)
         {
             return;
         }
        
         if(grid1[row][col]==0)
         {
             res=false;
             return ;
         }
        
        //marking the cells of grid as visited
        grid2[row][col]=0;
        
        dfs(row+1,col,m,n,grid1,grid2,res);
        dfs(row-1,col,m,n,grid1,grid2,res);
        dfs(row,col+1,m,n,grid1,grid2,res);
        dfs(row,col-1,m,n,grid1,grid2,res);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
         int m = grid1.size();
         int n = grid1[0].size();
         bool res; 
         int islands=0;
        
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(grid2[i][j]==1)
                 {
                     //have to initialize it every time, otherwise it will retain its value
                      res=true;
                     dfs(i,j,m,n,grid1,grid2,res);
                     if(res)
                     {
                         islands++;
                     }
                 }
             }
         }
        
        return islands;
    }
};