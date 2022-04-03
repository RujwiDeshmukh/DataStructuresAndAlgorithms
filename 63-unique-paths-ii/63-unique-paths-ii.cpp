class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<int>prev(m+1,0);
        
        for(int i=0;i<n;i++)
        {
            
             vector<int>temp(m+1,0);
            
            for(int j=0;j<m;j++)
            {
                
                if(obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                }
                else if(i==0 && j==0)
                {
                    temp[j]=1;
                }
                else 
                {
                    int up=0;
                    int left=0;
                    if(i>0)
                    {
                        up = prev[j];
                    }
                    if(j>0)
                    {
                        left = temp[j-1];
                    }
                        temp[j] = up+left;
                 }
                
                }
            
            prev = temp;
            }
        
        return prev[m-1];
    }
};