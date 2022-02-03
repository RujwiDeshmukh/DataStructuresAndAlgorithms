class Solution {
public:
    
    void bfs(vector<vector<int>>& grid,int sr,int sc,int n,int m,int &temp)
    {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            auto pr = q.front();
            q.pop();
            int currentRow = pr.first;
            int currentCol = pr.second;
            
    if(currentRow<0 || currentRow >=n || currentCol<0 || currentCol>=m || 
      grid[currentRow][currentCol]==0)
      {
               continue;
      }
            
        grid[currentRow][currentCol] = 0;
        temp += 1;
        q.push({currentRow+1,currentCol});
        q.push({currentRow-1,currentCol});
        q.push({currentRow,currentCol+1});
        q.push({currentRow,currentCol-1});
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
                if(grid[i][j]==1)
                {
                    int temp=0;
                    bfs(grid,i,j,n,m,temp);
                    ans = max(ans,temp);
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