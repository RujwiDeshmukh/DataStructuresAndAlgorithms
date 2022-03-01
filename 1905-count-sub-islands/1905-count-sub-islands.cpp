class Solution {
public:
    
    void bfs(int row,int col,int m,int n,vector<vector<int>>& grid1,vector<vector<int>>& grid2,bool & res)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty())
        {
            auto pr = q.front();
            q.pop();
            
            int currRow = pr.first;
            int currCol = pr.second;
            
if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || grid2[currRow][currCol]!=1)
    {
        continue;
    }
            
            if(grid1[currRow][currCol]==0)
            {
                res=false;
            }
            
            //mark it as visited
            grid2[currRow][currCol]=0;
            
            q.push({currRow+1,currCol});
            q.push({currRow-1,currCol});
            q.push({currRow,currCol+1});
            q.push({currRow,currCol-1});
            
        }
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
                     bfs(i,j,m,n,grid1,grid2,res);
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