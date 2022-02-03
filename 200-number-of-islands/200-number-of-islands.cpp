class Solution {
public:
    
    void bfs(vector<vector<char>>& grid,int sr,int sc,int n,int m)
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
      grid[currentRow][currentCol]=='0')
      {
               continue;
      }
            
        grid[currentRow][currentCol] = '0';
        q.push({currentRow+1,currentCol});
        q.push({currentRow-1,currentCol});
        q.push({currentRow,currentCol+1});
        q.push({currentRow,currentCol-1});
            
            
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int answer=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    answer += 1;
                    
                    bfs(grid,i,j,n,m);
                }
            }
        }
        
        return answer;
    }
};