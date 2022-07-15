class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int minutes=0;
        queue<pair<int,int>>q;
        int fresh=0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        if(fresh==0)
        {
            return 0;
        }
        
        int dirX[] = {0,1,0,-1};
        int dirY[] = {1,0,-1,0};
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                auto p = q.front();
                q.pop();
               
                for(int k=0;k<4;k++)
                {
                    int x = p.first + dirX[k];
                    int y = p.second + dirY[k];
                    
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1)
                {
                    grid[x][y]=2;
                    fresh--;
                    q.push({x,y});
                }
              }
                
            }
            //after one for loop one level completes so incrementing after for loop
            minutes++;
        }
        
        if(fresh==0)
        {
            return minutes-1;
        }
        
        return -1;
    }
};