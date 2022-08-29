class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n,0);
            
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=1;
                }
                else
                {
                    int leftMove =0;
                    if(j>0)
                    {
                        leftMove = curr[j-1];
                    }
                       
                    int upMove =0;
                    if(i>0)
                    {
                       upMove = prev[j];
                    }
                    
                    curr[j] = leftMove+upMove;
                }
                
            }
            
            prev =curr;
        }
        
        return prev[n-1];
    }
};