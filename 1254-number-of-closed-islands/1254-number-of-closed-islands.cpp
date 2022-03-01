class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int currRow,int currCol,int m,int n)
    {
        
if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid[currRow][currCol]==1)
{
    return;
}
        
        grid[currRow][currCol]=1;
        dfs(grid,currRow+1,currCol,m,n);
        dfs(grid,currRow-1,currCol,m,n);
        dfs(grid,currRow,currCol+1,m,n);
        dfs(grid,currRow,currCol-1,m,n);
        
    }
    
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //Updating the corner 0s as we know that
        //corner zeros cant be included into close island
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                dfs(grid,i,0,m,n);
            }
            
            if(grid[i][n-1]==0)
            {
                //we are implementing dfs here to make all the connecting zeros to 
                //border zeros as visited
                //
                dfs(grid,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0)
            {
                dfs(grid,0,i,m,n);
            }
            
            if(grid[m-1][i]==0)
            {
                //we are implementing dfs here to make all the connecting zeros to 
                //border zeros as visited
                //
                dfs(grid,m-1,i,m,n);
            }
        }
        
        int count=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,m,n);
                    count++;
                    cout<<count<<endl;
                }
            }
        }
        
        return count;
    }
};