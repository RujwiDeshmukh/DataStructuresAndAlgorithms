class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        {
            return -1;
        }
        
        queue<pair<int,int>>q;
        //queue will store co-oridnates
        q.push({0,0});
        int level=1;
        
        while(!q.empty())
        {
            //as we want to find which one searches first we have to process all
            //nodes of particualr level once so using for loop
            
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
              auto pr = q.front();
              q.pop();
            
            int currentRow = pr.first;
            int currentCol = pr.second;
                
            if(currentRow==m-1 && currentCol==n-1)
            {
                return level;
            }
            
            if(currentRow < 0 || currentCol < 0 || currentRow >= m || currentCol >= n ||
              grid[currentRow][currentCol]==1)
            {
                continue ;
            }
            
            grid[currentRow][currentCol]=1;
            q.push({currentRow+1,currentCol});
            q.push({currentRow-1,currentCol});
            q.push({currentRow,currentCol+1});
            q.push({currentRow,currentCol-1});
            q.push({currentRow-1,currentCol-1});
            q.push({currentRow+1,currentCol+1});
            q.push({currentRow-1,currentCol+1});
            q.push({currentRow+1,currentCol-1});
                
            }
            level++;
        }
        
        return -1;
    }
};