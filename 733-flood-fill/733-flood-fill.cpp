class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        
        int color = grid[sr][sc];
        queue<pair<int,int>>q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[sr][sc]==newColor)
        {
            return grid;
        }
        
        q.push({sr,sc});
        
        while(!q.empty())
        {
            auto currentPair = q.front();
            q.pop();
            
            int currentRow =  currentPair.first;
            int currentCol = currentPair.second;
            
         if(currentRow < 0 || currentRow >= n || currentCol < 0 || currentCol >= m ||
           grid[currentRow][currentCol] != color)
         {
             continue;
         }
            
            grid[currentRow][currentCol] =newColor;
            q.push({currentRow+1,currentCol});
            q.push({currentRow-1,currentCol});
            q.push({currentRow,currentCol-1});
            q.push({currentRow,currentCol+1});
            
            
        }
        
        return grid;
    }
};