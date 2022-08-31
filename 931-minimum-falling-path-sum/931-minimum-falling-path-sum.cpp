class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        vector<int>prev(n,0);
        
        int mini=99999;
        
        for(int i=0;i<n;i++)
        {
            vector<int>curr(n,0);
            
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    curr[j]=grid[i][j];
                }
                else
                {
                    int up = grid[i][j]+prev[j];
                    int leftDiag = 999999;
                    if(j>0)
                    {
                    leftDiag = grid[i][j]+prev[j-1];
                    }
                    int rightDiag = 999999;
                    if(j<n-1)
                    {
                    rightDiag = grid[i][j]+prev[j+1];
                    }
                    
                    curr[j] = min(up,min(leftDiag,rightDiag));
                }
            }
            prev=curr;
        }
        
        for(int i=0;i<n;i++)
        {
             cout<<prev[i]<<endl; 
            mini = min(mini,prev[i]);
        }
        
        return mini;
    }
};