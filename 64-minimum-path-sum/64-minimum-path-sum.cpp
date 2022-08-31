class Solution {
public:
  
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>prev(m,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int>curr(m,0);
            
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=grid[i][j];
                }
                else
                {
                    int up = 999999;
                    if(i>0)
                    {
                      up  = grid[i][j]+ prev[j];
                    }
                       
                    int left=999999;
                    if(j>0)
                    {
                       left = grid[i][j] + curr[j-1];
                    }
                    curr[j] = min(up,left);
                } 
            }
            
            prev = curr;
        }
        
        return prev[m-1];
    }
};