class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        
        for(int i=0;i<m;i++)
        {
            int start=0;
            int end=n-1;
            int idx=-1;
            
            while(start <= end)
            {
                int mid = (end+start)/2;
                
                if(grid[i][mid]>=0)
                {
                    start=mid+1;
                }
                else if(grid[i][mid]<0)
                {
                    end=mid-1;
                    idx=mid;
                }
                
            }
            if(idx!= -1)
            count += n-idx;
        }
            
        return count;
            
    }
};