class Solution {
public:
    
    void bfs(vector<vector<int>>& grid,int currRow,int currCol,int m,int n)
    {
        
        queue<pair<int,int>>q;
        q.push({currRow,currCol});
        grid[currRow][currCol]=1;
        
        while(!q.empty())
        {
            auto pr = q.front();
            q.pop();
            
            int row = pr.first;
            int col = pr.second;
            
    if(row+1 >= 0 && row+1 < m && col >= 0 && col < n && grid[row+1][col]==0 )
    {
        q.push({row+1,col});
        grid[row+1][col]=1;
    }
       if(row-1 >= 0 && row-1 < m && col >= 0 && col < n && grid[row-1][col]==0 )
    {
        q.push({row-1,col});
        grid[row-1][col]=1;
    }
    if(row >= 0 && row < m && col+1 >= 0 && col+1 < n && grid[row][col+1]==0 )
    {
        q.push({row,col+1});
        grid[row][col+1]=1;
    }
    if(row >= 0 && row < m && col-1 >= 0 && col-1 < n && grid[row][col-1]==0 )
    {
        q.push({row,col-1});
        grid[row][col-1]=1;
    }
            
        }
    }
    
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //Updating the corner 0s as we know that
        //corner zeros cant be included into close island
        
        //excluding the zeros groups of the corner
        //will account only intermediate one
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                bfs(grid,i,0,m,n);
            }
            
            if(grid[i][n-1]==0)
            {
                //we are implementing dfs here to make all the connecting zeros to 
                //border zeros as visited
                //
                bfs(grid,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0)
            {
                bfs(grid,0,i,m,n);
            }
            
            if(grid[m-1][i]==0)
            {
                //we are implementing dfs here to make all the connecting zeros to 
                //border zeros as visited
                //
                bfs(grid,m-1,i,m,n);
            }
        }
        
        int count=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    bfs(grid,i,j,m,n);
                    count++;
                    cout<<count<<endl;
                }
            }
        }
        
        return count;
    }
};